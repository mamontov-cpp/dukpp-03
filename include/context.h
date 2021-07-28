/*! \mainpage dukpp-03
    
    A C++03 experimental bindings for Duktape library
 */
/*! \file context.h


    A wrapper around basic Duktape context to support embeddable operations.
 */
#pragma once
#include "abstractcontext.h"
#include "dukpp-03.h"
#include "maybe.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "mapinterface.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "variantinterface.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "timerinterface.h"
#include "wrapvalue.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "errorcodes.h"
#include "callable.h"
#include "decay.h"
// ReSharper disable once CppUnusedIncludeDirective
#include <iostream>

/*! A property name for an object, which must have this property set to a string variant
 */
#define DUKPP03_VARIANT_PROPERTY_SIGNATURE "\1dukpp03::Variant\1"

namespace dukpp03
{

template<
    typename _Value,
    typename _Context
>
class PushValue;

template<
    typename _Value,
    typename _Context
>
class GetValue;

template<
    typename _Context
>
class ClassBinding;

/*! A miscellaneous class, for performing garbage collection, 
    used as finalizer in duktape. Specialize this class, to overload
    finalization for objects of specific value.
 */
template<
    typename _Context
>
struct Finalizer
{
    /*! Returns variant to be finalized
        \param[in] ctx context
        \return variant or null if nothing
     */
    static typename _Context::Variant* getVariantToFinalize(duk_context* ctx);
    /*! A finalization function
        \param[in] ctx context
        \return 0
     */
    static duk_ret_t finalize(duk_context *ctx);
};

/*! A common finalizing function for finalizer
 */
typedef duk_ret_t (*FinalizerFunction)(duk_context*);


/*! A wrapper around basic duktape context with replaceable map, timer and variant implementations
 */
template<
    template<typename, typename> class _MapInterface,
    typename _VariantInterface,
    typename _TimerInterface,
    typename _WrapValue = dukpp03::WrapValue
>
class Context: public dukpp03::AbstractContext
{
public:
    /*! Name synonym in context of class, used to shorten some specifications
     */
    typedef  dukpp03::Context<_MapInterface, _VariantInterface, _TimerInterface, _WrapValue> Self;
    /*! Lift variant name here
     */
    typedef typename _VariantInterface::Variant Variant;
    /*! A timer for timer interface
     */
    typedef typename _TimerInterface::Timer Timer;
    /*! Own callable type for context
     */
    typedef dukpp03::Callable<dukpp03::Context<_MapInterface, _VariantInterface, _TimerInterface, _WrapValue> > LocalCallable;
    /*! A callback set for context
     */
    typedef _MapInterface<dukpp03::AbstractCallable*, dukpp03::AbstractCallable*> CallbackSet;
    /*! A class binding set for context
     */
    typedef _MapInterface<std::string, ClassBinding<Self>*> ClassBindingSet;
    /*! Registered objects set for context
     */
    typedef _MapInterface<Variant*, Variant*> RegisteredObjectSet;
    /*! A registered item set for context
     */
    typedef _MapInterface<void*, void*> LinkedPointerSet;
    /*! A type for selecting utilities from context
     */
    typedef _VariantInterface VariantUtils;
    /*! An utilities for wrapping value into context
     */
    typedef  _WrapValue WrapValue;
    /*! Creates new context
     */
    Context()
    {

    }
    /*! Context is inheritable
     */
    virtual ~Context() override
    {
        for(typename CallbackSet::iterator it = m_functions.begin(); it.end() == false; it.next())
        {
            delete it.value();
        }
        for(typename ClassBindingSet::iterator it = m_class_bindings.begin(); it.end() == false; it.next())
        {
            delete it.value();
        }
        m_class_bindings.clear();
        m_functions.clear();
        if (m_context)
        {
            duk_destroy_heap(m_context);
            m_context = nullptr;
        }
    }
    /*! Resets context fully, erasing all data
     */
    virtual void reset()  override
    {
        for(typename CallbackSet::iterator it = m_functions.begin(); it.end() == false; it.next())
        {
            delete it.value();
        }
        m_functions.clear();
        for(typename ClassBindingSet::iterator it = m_class_bindings.begin(); it.end() == false; it.next())
        {
            delete it.value();
        }
        m_class_bindings.clear();
        duk_destroy_heap(m_context);
        m_context = duk_create_heap(nullptr,nullptr, nullptr, this, nullptr);
        this->initContextBeforeAccessing();
    }
    /*! Pushes variant to a pool. Note, that context becomes owner of variant, so don't push your own variants into here.
        \param[in] v variant
        \param[in] ff a finalizer that must be used for this context
     */
    template< typename _Value >
    void pushVariant(Variant* v,  dukpp03::FinalizerFunction ff = dukpp03::Finalizer<Self>::finalize)
    {
	    const duk_idx_t obj = duk_push_object(m_context);
        // Push pointer value for variant
        duk_push_string(m_context, DUKPP03_VARIANT_PROPERTY_SIGNATURE); 
        duk_push_pointer(m_context, v);
        duk_def_prop(m_context, obj, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_FORCE | 0);

        m_registered_objects.insert(v, v);

        // Set finalizer for current object
        duk_push_c_function(m_context, ff, 2);
        duk_set_finalizer(m_context, obj);
        // Default handler for wrapping value
        std::string class_binding_name = this->typeName<_Value>();
        bool wrapped = false;
        if (m_class_bindings.contains(class_binding_name))
        {
            m_class_bindings.get(class_binding_name)->wrapValue(this);
            wrapped = true;
        }
        // Wrap value, populating it with methods if needed  
        WrapValue::perform(this, v, wrapped);
    }

    /*! DO NOT use this function, unless you know, what you're doing. This functions pushes on stack
        variant with type passed in first argument, trying to wrap it onto method. 

        You should check manually, that this type of variant corresponds to name, otherwise the behaviour is undefined
        \param[in] name name of variant
        \param[in] v a variant name
        \param[in] ff a finalizer that must be used for this context
     */ 
    void pushUntypedVariant(const std::string& name, Variant* v, dukpp03::FinalizerFunction ff = dukpp03::Finalizer<Self>::finalize)
    {
        const duk_idx_t obj = duk_push_object(m_context);

        // Push pointer value for variant
        duk_push_string(m_context, DUKPP03_VARIANT_PROPERTY_SIGNATURE); 
        duk_push_pointer(m_context, v);
        duk_def_prop(m_context, obj, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_FORCE | 0);

        m_registered_objects.insert(v, v);

        // Set finalizer for current object
        duk_push_c_function(m_context,  ff, 2);
        duk_set_finalizer(m_context, obj);
        // Default handler for wrapping value
        bool wrapped = false;
        if (m_class_bindings.contains(name))
        {
            m_class_bindings.get(name)->wrapValue(this);
            wrapped = true;
        }
        // Wrap value, populating it with methods if needed     
        WrapValue::perform(this, v, wrapped);       
    }

    /*! Test if variant is register
        \param[in] v variant
        \return if value is registered
     */
    bool isVariantRegistered(Variant* v)
    {
        return m_registered_objects.contains(v);            
    }

    /*! Unregisters variant from context
        \param[in] v variant
     */
    void unregisterVariant(Variant* v)
    {
        m_registered_objects.remove(v);
    }
    
    /*! Registers variable as property of global object, pushing it into a persistent stack. Replaces existing property.
        \param[in] property_name name of new property of global object
        \param[in] v a value to be registered
     */
    template<
        typename _Value
    >
    void registerGlobalVariable(const std::string& property_name, Variant* v)
    {
        if (v)
        {
            duk_push_global_object(m_context);
            duk_push_string(m_context, property_name.c_str());
            this->pushVariant<_Value>(v);
            duk_put_prop(m_context, -3);
            duk_pop(m_context);
        }
    }
    /*! Marks top object on stack as global with name without removing it from stack
        \param[in] property_name a name of object
        \return true if object is not on stack
     */
    bool markTopObjectAsGlobal(const std::string& property_name) const
    {
        if (this->getTop() == 0)
        {
            return false;
        }
        duk_dup_top(m_context);
        duk_push_string(m_context, property_name.c_str());
        duk_push_global_object(m_context);
        duk_swap(m_context, -3, -1); 
        duk_put_prop(m_context, -3);
        duk_pop(m_context);
        return true;
    }
    /*! Pushes new default object to stack
     */
    void pushObject() const
    {
        duk_push_object(m_context);
    }
    /*! Returns error string from stack if it's here
        \param[in] pos a position on stack
        \return error string from stack
     */
    dukpp03::Maybe<std::string> errorOnStack(int pos) const
    {
        dukpp03::Maybe<std::string> result;
        if (duk_is_error(m_context, pos))
        {
            if (duk_has_prop_string(m_context,  -1, "stack"))
            {
                duk_get_prop_string(m_context, -1, "stack");
                result.setValue(duk_safe_to_string(m_context, -1));
                duk_pop(m_context);
            }
            else 
            {
                result.setValue(duk_safe_to_string(m_context, -1));
            }
        }
        return result;
    }
    /*! Pops object from stack
     */
    void pop() const
    {
        duk_pop(m_context);
    }
    /*! Cleans stack from other values. Useful after evaluating code
     */
    void cleanStack() const
    {
        while(getTop()) this->pop();
    }
    /*! Registers variable as global object, pushing it into a persistent stack. Replaces existing property.
        \param[in] property_name name of new property of global object
        \param[in] value a value to be registered
     */
    template<
        typename T
    >
    void registerGlobal(const std::string& property_name, const T& value)
    {
        registerGlobalVariable<T>(property_name, _VariantInterface::makeFrom(value));
    }    
    /*! Unregisters global variable
        \param[in] name name of variable or global callable function
     */
    void unregisterGlobal(const std::string& name) const
    {
        duk_push_global_object(m_context);
        duk_del_prop_string(m_context, -1, name.c_str());
        duk_pop(m_context);
    }

    /*! Calls function, using self as context
        \param[in] callable a callable value
     */
    virtual int call(void* callable) override
    {
        return static_cast<LocalCallable*>(callable)->call(this);
    }
    /*! Registers callable as property of global object
        \param[in] callable_name name of property of global object
        \param[in] callable a callable object
        \param[in] own whether context will own a callable
     */
    void registerCallable(const std::string& callable_name, LocalCallable* callable, bool own = true)
    {
        this->dukpp03::AbstractContext::registerCallable(callable_name, callable, own);
    }
    /*! Pushes callable to property of global object
        \param[in] callable a callable object
        \param[in] own whether we would own this callable
     */
    void pushCallable(LocalCallable* callable, bool own = true)
    {
        this->dukpp03::AbstractContext::pushCallable(callable, own);
    }
    /*! Sets immutable property for value on stack top
        \param[in] property_name a property name
        \param[in] v a value for property
     */
    template<
        typename _Value
    >
    void registerImmutableProperty(const std::string& property_name, const _Value& v)
    {
        duk_push_string(m_context, property_name.c_str());
        dukpp03::PushValue<_Value, Self>::perform(this, v);
        duk_def_prop(m_context, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_FORCE | 0);
    }
    /*! Sets mutable property for value on stack top
        \param[in] property_name a property name
        \param[in] v a value for property 
     */
    template<
        typename _Value
    >
    void registerMutableProperty(const std::string& property_name, const _Value& v)
    {
        duk_push_string(m_context, property_name.c_str());
        dukpp03::PushValue<_Value, Self>::perform(this, v);
        duk_put_prop(m_context, -3);
    }
    /*! Sets immutable callable property for value on stack top.
        \param[in] property_name a property name
        \param[in] callable a callable object
        \param[in] own whether we would own callable
     */
    void registerImmutableProperty(const std::string& property_name, LocalCallable* callable, bool own = true)
    {
        duk_push_string(m_context, property_name.c_str());
        this->pushCallable(callable, own);
        duk_def_prop(m_context, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_FORCE | 0);
    }
    /*! Sets mutable callable property  for value on stack top. 
        \param[in] property_name a property name
        \param[in] callable a callable object 
        \param[in] own whether we would own callable
      */
    void registerMutableProperty(const std::string& property_name, LocalCallable* callable, bool own = true)
    {
        duk_push_string(m_context, property_name.c_str());
        this->pushCallable(callable, own);
        duk_put_prop(m_context, -3);
    }
    /*! Registers new attribute property for value on stack top
        \param[in] property_name a property name
        \param[in] getter a getter
        \param[in] should_own_getter whether context should own getter
        \param[in] setter a setter
        \param[in] should_own_setter whether context should own setter
     */
    void registerAttribute(
        const std::string& property_name, 
        LocalCallable* getter,
        bool should_own_getter,
        LocalCallable* setter,
        bool should_own_setter
    )
    {
        // Do not allow empty attributes
        if (!getter && !setter)
        {
            return;
        }
        duk_push_string(m_context, property_name.c_str());
        duk_idx_t obj = -2;
        duk_uint_t flags = DUK_DEFPROP_HAVE_CONFIGURABLE | DUK_DEFPROP_HAVE_ENUMERABLE | DUK_DEFPROP_ENUMERABLE | DUK_DEFPROP_FORCE;
        if (getter)
        {
            flags = flags | DUK_DEFPROP_HAVE_GETTER;
            this->dukpp03::AbstractContext::pushCallable(getter, should_own_getter, true);
            obj -= 1;
        }
        
        if (setter)
        {
            flags = flags | DUK_DEFPROP_HAVE_SETTER;
            this->dukpp03::AbstractContext::pushCallable(setter, should_own_setter, true);
            obj -= 1;
        }
        duk_def_prop(m_context, obj, flags);
    }
    /*! Get global object from value
        \param[in] property_name a property for global object
        \return a value
     */
    template<
        typename _Value
    >
    dukpp03::Maybe<_Value> getGlobal(const std::string& property_name)
    {
        duk_get_global_string(m_context, property_name.c_str());
        dukpp03::Maybe<_Value> result = dukpp03::GetValue<_Value, Self>::perform(this, -1);
        duk_pop(m_context);
        return result;
    }

    /*! Evaluates string, with code in it. If no error occurred, result is not popped
        out from stack, since we still may need it
        \param[in] string a string
        \param[out] error a string, where error should be written
        \return true if no error
     */
    template<
        typename _Value
    >
    dukpp03::Maybe<_Value> evalAndGet(const std::string& string,std::string* error = nullptr)
    {
        this->eval(string, false, error);   
        return dukpp03::GetValue<_Value, Self>::perform(this, -1);
    }
    /*! Returns value from variant
        \param[in] v variant
        \return maybe value
     */
    template<
        typename T
    >
    inline static dukpp03::Maybe<T> valueFromVariant(Variant* v)
    {
        return _VariantInterface::template get<T>(v);
    }
    
    /*! Returns value from variant
        \param[in] v variant
        \return maybe value
     */
    template<
        typename T
    >
    inline static dukpp03::Maybe<T> valueAddressFromVariant(Variant* v)
    {
        return _VariantInterface::template getAddress<T>(v);
    }

    /*! Returns typename for type
        \return type
     */
    template<
        typename T
    >
    inline static std::string typeName()
    {
        return _VariantInterface::template TypeName< typename dukpp03::Decay<T>::Type >::type();
    }
    /*! Adds new class binding. Returns true and does nothing if already
        \param[in] name a type name for binding, use Context::typeName() to obtain it
        \param[in] c binding
        \return true on success, otherwise false
     */
    virtual bool addClassBinding(const std::string& name, dukpp03::ClassBinding<Self>* c)
    {
        if (m_class_bindings.contains(name))
        {
            return false;
        }
        m_class_bindings.insert(name, c);
        c->registerInContext(this);
        return true;
    }

    /*! Adds new class binding. Returns true and does nothing if already
        \param[in] c binding
        \return true on success, otherwise false
     */
    template<
        typename T
    >
    bool addClassBinding(dukpp03::ClassBinding<Self>* c)
    {
        return addClassBinding(this->typeName<T>(), c);
    }
    /*! Removes class binding by name
        \param[in] name a name
     */
    void removeClassBinding(const std::string& name)
    {
        if (m_class_bindings.contains(name))
        {
            dukpp03::ClassBinding<Self>* c = m_class_bindings.get(name);
            c->unregisterInContext(this);
            delete c;
            m_class_bindings.remove(name);
        }
    }
    /*! Returns class binding if it's exists
        \param[in] name a name fo bindings
     */
    dukpp03::ClassBinding<Self>* getClassBinding(const std::string& name)
    {
        if (m_class_bindings.contains(name))
        {
            return m_class_bindings.get(name);
        }
        return nullptr;
    }

    /*! Inserts linked pointer to context, storing it 
        \param[in] ptr pointer
     */
    void insertLinkedPointer(void* ptr)
    {
        if (m_linked_pointers.contains(ptr) == false)
        {
            m_linked_pointers.insert(ptr, ptr);
        }
    }
    /*! Returns true if linked pointer is stored in context
        \param[in] ptr a pointer
        \return whether an inner map has this pointer
     */
    bool isLinkedPointerStored(void* ptr)
    {
        return m_linked_pointers.contains(ptr);
    }

    /*! Removes linked pointer to context, deleting it 
        \param[in] ptr pointer
     */
    void removeLinkedPointer(void* ptr)
    {
        if (m_linked_pointers.contains(ptr))
        {
            m_linked_pointers.remove(ptr);
        }
    }
    /*! Calls global function
        \param[in] function a function
     */
    void callGlobalFunction(const char* function)
    {
        duk_context* ctx = this->context();
        duk_get_global_string(ctx, function);
        duk_call(ctx, 0);
    }
    /*! Calls global function
        \param[in] function a function
        \param[in] v1 a first argument
     */
    template<typename _T1>
    void callGlobalFunction(const char* function, _T1 v1)
    {
        duk_context* ctx = this->context();
        duk_get_global_string(ctx, function);
        dukpp03::PushValue<_T1, Self>::perform(this, v1);
        duk_call(ctx, 1);
    }
    /*! Calls global function
        \param[in] function a function
        \param[in] v1 a first argument
        \param[in] v2 a second argument
     */
    template<typename _T1, typename _T2>
    void callGlobalFunction(const char* function, _T1 v1, _T2 v2)
    {
        duk_context* ctx = this->context();
        duk_get_global_string(ctx, function);
        dukpp03::PushValue<_T1, Self>::perform(this, v1);
        dukpp03::PushValue<_T2, Self>::perform(this, v2);
        duk_call(ctx, 2);
    }
    /*! Calls global function
        \param[in] function a function
        \param[in] v1 a first argument
        \param[in] v2 a second argument
        \param[in] v3 a third argument
     */
    template<typename _T1, typename _T2, typename _T3>
    void callGlobalFunction(const char* function, _T1 v1, _T2 v2, _T3 v3)
    {
        duk_context* ctx = this->context();
        duk_get_global_string(ctx, function);
        dukpp03::PushValue<_T1, Self>::perform(this, v1);
        dukpp03::PushValue<_T2, Self>::perform(this, v2);
        dukpp03::PushValue<_T3, Self>::perform(this, v3);
        duk_call(ctx, 3);
    }
    /*! Calls global function
        \param[in] function a function
        \param[in] v1 a first argument
        \param[in] v2 a second argument
        \param[in] v3 a third argument
        \param[in] v4 a fourth argument
     */
    template<typename _T1, typename _T2, typename _T3, typename _T4>
    void callGlobalFunction(const char* function, _T1 v1, _T2 v2, _T3 v3, _T4 v4)
    {
        duk_context* ctx = this->context();
        duk_get_global_string(ctx, function);
        dukpp03::PushValue<_T1, Self>::perform(this, v1);
        dukpp03::PushValue<_T2, Self>::perform(this, v2);
        dukpp03::PushValue<_T3, Self>::perform(this, v3);
        dukpp03::PushValue<_T4, Self>::perform(this, v4);
        duk_call(ctx, 4);
    }
    /*! Calls global function
        \param[in] function a function
        \param[in] v1 a first argument
        \param[in] v2 a second argument
        \param[in] v3 a third argument
        \param[in] v4 a fourth argument
        \param[in] v5 a fifth argument
     */
    template<typename _T1, typename _T2, typename _T3, typename _T4, typename _T5>
    void callGlobalFunction(const char* function, _T1 v1, _T2 v2, _T3 v3, _T4 v4, _T5 v5)
    {
        duk_context* ctx = this->context();
        duk_get_global_string(ctx, function);
        dukpp03::PushValue<_T1, Self>::perform(this, v1);
        dukpp03::PushValue<_T2, Self>::perform(this, v2);
        dukpp03::PushValue<_T3, Self>::perform(this, v3);
        dukpp03::PushValue<_T4, Self>::perform(this, v4);
        dukpp03::PushValue<_T5, Self>::perform(this, v5);
        duk_call(ctx, 5);
    }
    /*! Calls global function
        \param[in] function a function
        \param[in] v1 a first argument
        \param[in] v2 a second argument
        \param[in] v3 a third argument
        \param[in] v4 a fourth argument
        \param[in] v5 a fifth argument
        \param[in] v6 a sixth argument
     */
    template<typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6>
    void callGlobalFunction(const char* function, _T1 v1, _T2 v2, _T3 v3, _T4 v4, _T5 v5, _T6 v6)
    {
        duk_context* ctx = this->context();
        duk_get_global_string(ctx, function);
        dukpp03::PushValue<_T1, Self>::perform(this, v1);
        dukpp03::PushValue<_T2, Self>::perform(this, v2);
        dukpp03::PushValue<_T3, Self>::perform(this, v3);
        dukpp03::PushValue<_T4, Self>::perform(this, v4);
        dukpp03::PushValue<_T5, Self>::perform(this, v5);
        dukpp03::PushValue<_T6, Self>::perform(this, v6);
        duk_call(ctx, 6);
    }
    /*! Calls global function
        \param[in] function a function
        \param[in] v1 a first argument
        \param[in] v2 a second argument
        \param[in] v3 a third argument
        \param[in] v4 a fourth argument
        \param[in] v5 a fifth argument
        \param[in] v6 a sixth argument
        \param[in] v7 a seventh argument
     */
    template<typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6, typename _T7>
    void callGlobalFunction(const char* function, _T1 v1, _T2 v2, _T3 v3, _T4 v4, _T5 v5, _T6 v6, _T7 v7)
    {
        duk_context* ctx = this->context();
        duk_get_global_string(ctx, function);
        dukpp03::PushValue<_T1, Self>::perform(this, v1);
        dukpp03::PushValue<_T2, Self>::perform(this, v2);
        dukpp03::PushValue<_T3, Self>::perform(this, v3);
        dukpp03::PushValue<_T4, Self>::perform(this, v4);
        dukpp03::PushValue<_T5, Self>::perform(this, v5);
        dukpp03::PushValue<_T6, Self>::perform(this, v6);
        dukpp03::PushValue<_T7, Self>::perform(this, v7);
        duk_call(ctx, 7);
    }
    /*! Calls global function
        \param[in] function a function
        \param[in] v1 a first argument
        \param[in] v2 a second argument
        \param[in] v3 a third argument
        \param[in] v4 a fourth argument
        \param[in] v5 a fifth argument
        \param[in] v6 a sixth argument
        \param[in] v7 a seventh argument
        \param[in] v8 an eighth argument
     */
    template<typename _T1, typename _T2, typename _T3, typename _T4, typename _T5, typename _T6, typename _T7, typename _T8>
    void callGlobalFunction(const char* function, _T1 v1, _T2 v2, _T3 v3, _T4 v4, _T5 v5, _T6 v6, _T7 v7, _T8 v8)
    {
        duk_context* ctx = this->context();
        duk_get_global_string(ctx, function);
        dukpp03::PushValue<_T1, Self>::perform(this, v1);
        dukpp03::PushValue<_T2, Self>::perform(this, v2);
        dukpp03::PushValue<_T3, Self>::perform(this, v3);
        dukpp03::PushValue<_T4, Self>::perform(this, v4);
        dukpp03::PushValue<_T5, Self>::perform(this, v5);
        dukpp03::PushValue<_T6, Self>::perform(this, v6);
        dukpp03::PushValue<_T7, Self>::perform(this, v7);
        dukpp03::PushValue<_T8, Self>::perform(this, v8);
        duk_call(ctx, 8);
    }
protected:
    /*! Starts evaluating object, needed for data
     */
    virtual void startEvaluating() override
    {
        _TimerInterface::restart(m_timeout_timer);
    }
    /*! Returns time, elapsed from evaluation
     */
    virtual double elapsedFromEvaluation() override
    {
        return _TimerInterface::elapsed(m_timeout_timer);
    }
    /*! Adds callable to needed set
        \param[in] c callable
     */
    virtual void addCallableToSet(dukpp03::AbstractCallable* c) override
    {
        if (m_functions.contains(c) == false)
        {
            m_functions.insert(c, c);
        }
    }
    /*! Registered global functions
     */
    CallbackSet m_functions;
    /*! A class binding set
     */
    ClassBindingSet m_class_bindings;
    /*! Registered objects set
     */
    RegisteredObjectSet m_registered_objects;
    /*! A stored registered pointer of random types
     */ 
    LinkedPointerSet m_linked_pointers;
    /*! A timeout timer for context
     */
    Timer m_timeout_timer;
};

template<
    typename _Context
>
typename _Context::Variant* Finalizer<_Context>::getVariantToFinalize(duk_context* ctx)
{
    if (duk_is_object(ctx, 0))
    {
        typename _Context::Variant* result = nullptr;
        duk_get_prop_string(ctx, 0, DUKPP03_VARIANT_PROPERTY_SIGNATURE);
        if (duk_is_pointer(ctx, -1))
        {
            void* ptr = duk_to_pointer(ctx, -1);
            result = static_cast<typename _Context::Variant*>(ptr);
        }
        duk_pop(ctx);
        return result;
    }
    return nullptr;
}


template<
    typename _Context
>
duk_ret_t Finalizer<_Context>::finalize(duk_context *ctx)
{    
    typename _Context::Variant* variant = Finalizer<_Context>::getVariantToFinalize(ctx);
    _Context* parent  = static_cast<_Context*>(dukpp03::AbstractContext::getContext(ctx));
    if (variant && parent->isVariantRegistered(variant)) 
    {
        delete variant;
        parent->unregisterVariant(variant);
    }
    return 0;
}

}

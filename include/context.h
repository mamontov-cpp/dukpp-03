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
#include "mapinterface.h"
#include "variantinterface.h"
#include "timerinterface.h"
#include "wrapvalue.h"
#include "errorcodes.h"
#include "callable.h"
#include "decay.h"
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
    virtual ~Context()
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
            m_context = NULL;
        }
    }
    /*! Resets context fully, erasing all data
     */
    void reset()
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
        m_context = duk_create_heap(NULL,NULL, NULL, this, NULL);
        this->initContextBeforeAccessing();
    }
    /*! Pushes variant to a pool. Note, that context becames owner of variant, so don't push your own variants into here.
        \param[in] v variant
        \param[in] ff a finalizer that must be used for this context
     */
    template< typename _Value >
    void pushVariant(Variant* v,  dukpp03::FinalizerFunction ff = dukpp03::Finalizer<Self>::finalize)
    {
        duk_idx_t obj = duk_push_object(m_context);
        // Push pointer value for variant
        duk_push_string(m_context, DUKPP03_VARIANT_PROPERTY_SIGNATURE); 
        duk_push_pointer(m_context, v);
        duk_def_prop(m_context, obj, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_FORCE | 0);

        m_registered_objects.insert(v, v);

        // Set finalizer for current object
        duk_push_c_function(m_context, ff, 2);
        duk_set_finalizer(m_context, obj);
        // Default handler for wrapping value
        std::string cbname = this->typeName<_Value>();
        bool wrapped = false;
        if (m_class_bindings.contains(cbname))
        {
            m_class_bindings.get(cbname)->wrapValue(this);
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
        duk_idx_t obj = duk_push_object(m_context);

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
    /*! Returns error string from stack if it's herer
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
    virtual int call(void* callable)
    {
        return reinterpret_cast<LocalCallable*>(callable)->call(this);
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
        \param[in] propname a property name
        \param[in] v a value for property
     */
    template<
        typename _Value
    >
    void registerImmutableProperty(const std::string& propname, const _Value& v)
    {
        duk_push_string(m_context, propname.c_str());
        dukpp03::PushValue<_Value, Self>::perform(this, v);
        duk_def_prop(m_context, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_FORCE | 0);
    }
    /*! Sets mutable property for value on stack top
        \param[in] propname a property name
        \param[in] v a value for property 
     */
    template<
        typename _Value
    >
    void registerMutableProperty(const std::string& propname, const _Value& v)
    {
        duk_push_string(m_context, propname.c_str());
        dukpp03::PushValue<_Value, Self>::perform(this, v);
        duk_put_prop(m_context, -3);
    }
    /*! Sets immutable callable property for value on stack top.
        \param[in] propname a property name
        \param[in] callable a callable object
        \param[in] own whether we would own callable
     */
    void registerImmutableProperty(const std::string& propname, LocalCallable* callable, bool own = true)
    {
        duk_push_string(m_context, propname.c_str());
        this->pushCallable(callable, own);
        duk_def_prop(m_context, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_FORCE | 0);
    }
    /*! Sets mutable callable property  for value on stack top. 
        \param[in] propname a property name
        \param[in] callable a callable object 
        \param[in] own whether we would own callable
      */
    void registerMutableProperty(const std::string& propname, LocalCallable* callable, bool own = true)
    {
        duk_push_string(m_context, propname.c_str());
        this->pushCallable(callable, own);
        duk_put_prop(m_context, -3);
    }
    /*! Registers new attribute property for value on stack top
        \param[in] propname a property name
        \param[in] getter a getter
        \param[in] owngetter whether context should own getter
        \param[in] setter a setter
        \param[in] ownsetter whether context should own setter
     */
    void registerAtribute(
        const std::string& propname, 
        LocalCallable* getter,
        bool owngetter,
        LocalCallable* setter,
        bool ownsetter    
    )
    {
        // Do not allow empty attributes
        if (!getter && !setter)
        {
            return;
        }
        duk_push_string(m_context, propname.c_str());
        duk_idx_t obj = -2;
        duk_uint_t flags = DUK_DEFPROP_HAVE_CONFIGURABLE | DUK_DEFPROP_HAVE_ENUMERABLE | DUK_DEFPROP_ENUMERABLE | DUK_DEFPROP_FORCE;
        if (getter)
        {
            flags = flags | DUK_DEFPROP_HAVE_GETTER;
            this->dukpp03::AbstractContext::pushCallable(getter, owngetter, true);
            obj -= 1;
        }
        
        if (setter)
        {
            flags = flags | DUK_DEFPROP_HAVE_SETTER;
            this->dukpp03::AbstractContext::pushCallable(setter, ownsetter, true);
            obj -= 1;
        }
        duk_def_prop(m_context, obj, flags);
    }
    /*! Get global object from value
        \param[in] propname a property for global object
        \return a value
     */
    template<
        typename _Value
    >
    dukpp03::Maybe<_Value> getGlobal(const std::string& propname)
    {
        duk_get_global_string(m_context, propname.c_str());
        dukpp03::Maybe<_Value> result = dukpp03::GetValue<_Value, Self>::perform(this, -1);
        duk_pop(m_context);
        return result;
    }

    /*! Evals string, with code in it. If no error occured, result is not popped
        out from stack, since we still may need it
        \param[in] string a string
        \param[out] error a string, where error should be written
        \return true if no error
     */
    template<
        typename _Value
    >
    dukpp03::Maybe<_Value> evalAndGet(const std::string& string,std::string* error = NULL)
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
        return NULL;
    }
protected:
    /*! Starts evaluating object, needed for data
     */
    virtual void startEvaluating()
    {
        _TimerInterface::restart(m_timeout_timer);
    }
    /*! Returns time, elapsed from evaluation
     */
    virtual double elapsedFromEvaluation()
    {
        return _TimerInterface::elapsed(m_timeout_timer);
    }
    /*! Adds callable to needed set
        \param[in] c callable
     */
    virtual void addCallableToSet(dukpp03::AbstractCallable* c)
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
        typename _Context::Variant* result = NULL;
        duk_get_prop_string(ctx, 0, DUKPP03_VARIANT_PROPERTY_SIGNATURE);
        if (duk_is_pointer(ctx, -1))
        {
            void* ptr = duk_to_pointer(ctx, -1);
            result = reinterpret_cast<typename _Context::Variant*>(ptr);
        }
        duk_pop(ctx);
        return result;
    }
    return NULL;
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

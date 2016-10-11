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

/*! A property name for an object, which must have this property set to a string variant
 */
#define DUKPP03_VARIANT_PROPERTY_SIGNATURE "\1dukpp03::Variant\1"
/*! A signature, which points, that current string is linked to variant pool
 */
#define DUKPP03_VARIANT_SIGNATURE "\1dukpp03::Variant\1"
/*! A signature, which points, that current string is linked to variant persistent
 */
#define DUKPP03_PERSISTENT_VARIANT_SIGNATURE "\1dukpp03::Variant__persistent\1"

namespace dukpp03
{

/*! A miscellaneous class, for performing garbage collection, 
    used as finalizer in duktape. Specialize this class, to overload
    finalization for objects of specific value.
 */
template<
    typename _Context,
    typename _Value
>
struct Finalizer
{
    /*! A finalization function
        \param[in] ctx context
        \return 0
     */
    static duk_ret_t finalize(duk_context *ctx);
};

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
        m_functions.clear();
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

        duk_destroy_heap(m_context);
        m_context = duk_create_heap(NULL,NULL, NULL, this, NULL);
        this->initContextBeforeAccessing();
    }
    /*! Pushes variant to a pool. Note, that context becames owner of variant, so don't push your own variants into here.
        \param[in] v variant
        \param[in] persistent whether it should be persistent
        \return string signature
     */
    template< typename _Value >
    void pushVariant(Variant* v)
    {
        duk_idx_t obj = duk_push_object(m_context);
        // Push pointer value for variant
        duk_push_string(m_context, DUKPP03_VARIANT_PROPERTY_SIGNATURE); 
        duk_push_pointer(m_context, v);
        duk_def_prop(m_context, obj, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | 0);
        // Set finalizer for current object
        duk_push_c_function(m_context, dukpp03::Finalizer<Self, _Value>::finalize, 1);
        duk_set_finalizer(m_context, obj);
        // Wrap value, populating it with methods if needed
        WrapValue::template perform<_Value>(this);       
    }
    
    /*! Registers variable as property of global object, pushing it into a persistent stack. Replaces existing property.
        \param[in] property_name name of new property of global object
        \param[in] value a value to be registered
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
     */
    void registerCallable(const std::string& callable_name, LocalCallable* callable)
    {
        this->dukpp03::AbstractContext::registerCallable(callable_name, callable);
    }
    /*! Pushes callable to property of global object
        \param[in] callable a callable object
     */
    void pushCallable(LocalCallable* callable)
    {
        this->dukpp03::AbstractContext::pushCallable(callable);
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
    /*! A timeout timer for context
     */
    Timer m_timeout_timer;
};

template<
    typename _Context,
    typename _Value
>
duk_ret_t Finalizer<_Context, _Value>::finalize(duk_context *ctx)
{
    if (duk_is_object(ctx, 0))
    {
       duk_get_prop_string(ctx, 0, DUKPP03_VARIANT_PROPERTY_SIGNATURE);
        if (duk_is_pointer(ctx, -1))
        {
            void* ptr = duk_to_pointer(ctx, -1);
            typename _Context::Variant* v = reinterpret_cast<typename _Context::Variant*>(ptr);
            delete v;
        }
        duk_pop(ctx);
    }
}

}

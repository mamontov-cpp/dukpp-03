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
#include "pool.h"
#include "errorcodes.h"
#include "callable.h"
#include "decay.h"

//#include "pushvalue.h"
//#include "getvalue.h"

/*! A signature, which points, that current string is linked to variant pool
 */
#define DUKPP03_VARIANT_SIGNATURE "\1dukpp03::Variant\1"
/*! A signature, which points, that current string is linked to variant persistent
 */
#define DUKPP03_PERSISTENT_VARIANT_SIGNATURE "\1dukpp03::Variant__persistent\1"

namespace dukpp03
{

/*! A wrapper around basic duktape context with replaceable map, timer and variant implementations
 */
template<
    template<typename, typename> class _MapInterface,
    typename _VariantInterface,
    typename _TimerInterface
>
class Context: public dukpp03::AbstractContext
{
public:
    /*! A local pool definition
     */
    typedef  dukpp03::Pool<_VariantInterface, _MapInterface> Pool;
    /*! Lift variant name here
     */
    typedef typename _VariantInterface::Variant Variant;
    /*! A timer for timer interface
     */
    typedef typename _TimerInterface::Timer Timer;
    /*! Own callable type for context
     */
    typedef dukpp03::Callable<dukpp03::Context<_MapInterface, _VariantInterface, _TimerInterface> > LocalCallable;
    /*! A callback set for context
     */
    typedef _MapInterface<dukpp03::AbstractCallable*, dukpp03::AbstractCallable*> CallbackSet;
    /*! A type for selecting utilities from context
     */
    typedef _VariantInterface VariantUtils;
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
    /*! Cleans non-persistent pool of objects, resetting it
     */
    void clean()
    {
        m_pool.free();
    }
    /*! Resets context fully, erasing all data
     */
    void reset()
    {
        m_pool.free();
        m_persistent_pool.free();
        for(typename CallbackSet::iterator it = m_functions.begin(); it.end() == false; it.next())
        {
            delete it.value();
        }
        m_functions.clear();

        duk_destroy_heap(m_context);
        m_context = duk_create_heap(NULL,NULL, NULL, this, NULL);
        this->initContextBeforeAccessing();
    }
    /*! Pushes variant to a persistent pool
        \param[in] v variant
        \return string signature
     */
    std::string pushPersistentVariant(Variant* v)
    {
        std::string result = DUKPP03_PERSISTENT_VARIANT_SIGNATURE;
        result.append(m_persistent_pool.insert(v));
        duk_push_string(m_context, result.c_str());
        return result;
    }
    /*! Pushes variant to a pool
        \param[in] v variant
        \return string signature
     */
    std::string pushVariant(Variant* v)
    {
        std::string result = DUKPP03_VARIANT_SIGNATURE;
        result.append(m_pool.insert(v));
        duk_push_string(m_context, result.c_str());
        return result;
    }
    /*! Gets value from pool by key
        \param[in] key a key of value, which could be either in common pool or persistent pool
        \return value
     */
    Variant* getValueFromPool(const std::string& key)
    {
        std::string signature = DUKPP03_VARIANT_SIGNATURE;
        if (key.substr(0, signature.length()) != signature)
        {
            std::string persistent_signature = DUKPP03_PERSISTENT_VARIANT_SIGNATURE;
            if (key.substr(0, persistent_signature.length()) != persistent_signature)
            {
                return NULL;
            }
            return m_persistent_pool.get(
                key.substr(
                    persistent_signature.length(),
                    key.length() - persistent_signature.length()
                )
            );
        }
        return m_pool.get(key.substr(signature.length(), key.length() - signature.length()));
    }
    /*! Registers variable as property of global object, pushing it into a persistent stack. Replaces existing property.
        \param[in] property_name name of new property of global object
        \param[in] value a value to be registered
     */
    void registerGlobalVariable(const std::string& property_name, Variant* value)
    {
        if (value)
        {
            std::string identifier = DUKPP03_PERSISTENT_VARIANT_SIGNATURE;
            identifier.append(m_persistent_pool.insert(value));
            duk_push_global_object(m_context);
            duk_push_string(m_context, property_name.c_str());
            duk_push_string(m_context, identifier.c_str());
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
        registerGlobalVariable(property_name, _VariantInterface::makeFrom(value));
    }
    /*! Returns value from pool by string, linked on stack
        \param[in] pos position on stack
        \return value
     */
    template<
        typename T
    >
    dukpp03::Maybe<T> getValueFromPoolByStringFromStack(duk_idx_t pos)
    {
        dukpp03::Maybe<T> result;
        if (duk_is_string(m_context, pos))
        {
            Variant* v = this->getValueFromPool(duk_to_string(m_context, pos));
            if (v)
            {
                result = _VariantInterface::template get<T>(v);
            }
        }
        return result;
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
    /*! A basic pool for objects in context
     */
    Pool m_pool;
    /*! A persistent pool for values
     */
    Pool m_persistent_pool;
    /*! Registered global functions
     */
    CallbackSet m_functions;
    /*! A timeout timer for context
     */
    Timer m_timeout_timer;
};

}

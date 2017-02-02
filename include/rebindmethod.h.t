/*! \file rebindmethod.h
     
    Defines a simple defines for creating bindings for any kind of method, that will be called from this but with another class
 */
#pragma once
#include "callable.h"
#include "decay.h"
#include "getvalue.h"
#include "pushvalue.h"
#include "errorcodes.h"
#include "context.h"

namespace dukpp03
{

{{#variants}}

/*! Defines a wrapper for method, which returns nothing and receives {{argscount}} arguments
 */
template<
    typename _Context,
    typename _RebindedClassName,
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class RebindedThisVoidMethod{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}});
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod{{argscount}}(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::RebindedThisVoidMethod{{argscount}}<_Context, _RebindedClassName, _ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return {{argscount}};
    }

    DUKPP03_CBC_WITH_THIS_{{argscount}}(_RebindedClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}
        ((_ac._())->*m_callee)({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisVoidMethod{{argscount}}()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};
{{/variants}}
{{#variants}}

/*! Defines a wrapper for method, which returns some value and receives {{argscount}} arguments
 */
template<
    typename _Context, 
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class RebindedThisRetMethod{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}});
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod{{argscount}}(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RebindedThisRetMethod{{argscount}}<_Context, _RebindedClassName, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return {{argscount}};
    }

    DUKPP03_CBC_WITH_THIS_{{argscount}}(_RebindedClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}
        _ReturnType t = ((_ac._())->*m_callee)({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisRetMethod{{argscount}}()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};
{{/variants}}

{{#variants}}

/*! Defines a wrapper for method, which returns nothing and receives {{argscount}} arguments
 */
template<
    typename _Context,
    typename _RebindedClassName,
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class RebindedClassNameThisConstVoidMethod{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod{{argscount}}(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::RebindedThisConstVoidMethod{{argscount}}<_Context, _RebindedClassName, _ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return {{argscount}};
    }

    DUKPP03_CBC_WITH_THIS_{{argscount}}(_RebindedClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}              
        ((_ac._())->*m_callee)({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisConstVoidMethod{{argscount}}()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};
{{/variants}}
{{#variants}}

/*! Defines a wrapper for method, which returns some value and receives {{argscount}} arguments
 */
template<
    typename _Context,
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class RebindedThisConstRetMethod{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod{{argscount}}(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RebindedThisConstRetMethod{{argscount}}<_Context, _RebindedClassName, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return {{argscount}};
    }

    DUKPP03_CBC_WITH_THIS_{{argscount}}(_RebindedClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}               
        _ReturnType t = ((_ac._())->*m_callee)({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisConstRetMethod{{argscount}}()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};
{{/variants}}

template<
    typename _Context
>
struct rebind_method
{

template<
	typename _RebindedClassName
>
struct to
{

{{#variants}}
/*! Makes callable from method which returns nothing and receives {{argscount}} arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)({{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}))
{
    return new RebindedThisVoidMethod{{argscount}}<_Context, _RebindedClassName, _ClassName{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}

{{#variants}}
/*! Makes callable from method which returns value and receives {{argscount}} arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)({{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}))
{
    return new RebindedThisRetMethod{{argscount}}<_Context, _RebindedClassName, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}
{{#variants}}
/*! Makes callable from const method which returns nothing and receives {{argscount}} arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)({{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}) const)
{
    return new RebindedThisConstVoidMethod{{argscount}}<_Context, _RebindedClassName, _ClassName{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}

{{#variants}}
/*! Makes callable from const method which returns value and receives {{argscount}} arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)({{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}) const)
{
    return new RebindedThisConstRetMethod{{argscount}}<_Context, _RebindedClassName, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}

};

};

}

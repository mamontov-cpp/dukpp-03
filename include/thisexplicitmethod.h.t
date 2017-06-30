/*! \file thisexplicitmethod.h
     
    Defines a simple defines for creating bindings for any kind of method, that will be called from this with specified
    types
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
    typename _Method,
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class ThisExplicitVoidMethod{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod{{argscount}}(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisExplicitVoidMethod{{argscount}}<_Context, _Method,_ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return {{argscount}};
    }

    DUKPP03_CBC_WITH_THIS_{{argscount}}(_ClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}
        ((_ac._())->*m_callee)({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisExplicitVoidMethod{{argscount}}()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};
{{/variants}}
{{#variants}}

/*! Defines a wrapper for method, which returns some value and receives {{argscount}} arguments
 */
template<
    typename _Context, 
    typename _Method,
    typename _ClassName,
    typename _ReturnType{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class ThisExplicitRetMethod{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod{{argscount}}(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisExplicitRetMethod{{argscount}}<_Context, _Method, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return {{argscount}};
    }

    DUKPP03_CBC_WITH_THIS_{{argscount}}(_ClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}
        _ReturnType t = ((_ac._())->*m_callee)({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisExplicitRetMethod{{argscount}}()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};
{{/variants}}

template<
    typename _Context
>
struct bind_explicit_method
{
{{#variants}}
template<
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
struct with_args_and_no_return_type{{argscount}}
{

/*! Makes callable from method which returns nothing and receives {{argscount}} arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod{{argscount}}<_Context, _Method, _ClassName{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

};


{{/variants}}

{{#variants}}

template<
    typename _ClassName,
    typename _ReturnType{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
struct with_args_and_and_return_type{{argscount}}
{

/*! Makes callable from method which returns value and receives {{argscount}} arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod{{argscount}}<_Context, _Method, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

};

{{/variants}}

};

}

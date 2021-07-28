/*! \file lambda.h
     
    Defines a simple defines for creating bindings for lambdas
 */
#pragma once
#include "callable.h"
#include "decay.h"
#include "getvalue.h"
#include "pushvalue.h"
#include "errorcodes.h"
#include "context.h"

#include <functional>

namespace dukpp03
{
{{#variants}}

/*! Defines a wrapper for lambda function, which returns nothing and receives {{argscount}} arguments
 */
template<
    typename _Context,
    typename _ClassName{{#has_args}},
{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}{{/args}}
>
class ThisVoidLambda{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*{{#has_args}},{{/has_args}}{{#args}}{{#not_last}}_Arg{{number}},{{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}})> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda{{argscount}}(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda{{argscount}}<_Context,_ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override  
    {
        return {{argscount}};
    }
    
    DUKPP03_CBC_WITH_THIS_{{argscount}}(_ClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}
        m_callee((_ac._()){{#has_args}},{{/has_args}}{{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda{{argscount}}() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};
{{/variants}}
{{#variants}}

/*! Defines a wrapper for lambda, which returns some value and receives {{argscount}} arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class ThisRetLambda{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*{{#has_args}},{{/has_args}}{{#args}}{{#not_last}}_Arg{{number}},{{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}})> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda{{argscount}}(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda{{argscount}}<_Context, _ReturnType,_ClassName{{#has_args}},{{/has_args}}{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override  
    {
        return {{argscount}};
    }
    
    DUKPP03_CBC_WITH_THIS_{{argscount}}(_ClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}
        _ReturnType t = m_callee((_ac._()){{#has_args}},{{/has_args}}{{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda{{argscount}}() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};
{{/variants}}

template<
    typename _Context
>
struct bind_lambda 
{
{{#variants}}
/*! Makes callable from function which returns nothing and receives {{argscount}} arguments
    \param[in] f function
    \return callable version
 */
template<
typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*{{#has_args}},{{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}})> f)
{
    return new ThisVoidLambda{{argscount}}<_Context,_ClassName{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}

{{#variants}}
/*! Makes callable from function which returns value and receives {{argscount}} arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*{{#has_args}},{{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}})> f)
{
    return new ThisRetLambda{{argscount}}<_Context, _ReturnType,_ClassName{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}

};

}

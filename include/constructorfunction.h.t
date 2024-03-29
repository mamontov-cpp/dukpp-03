/*! \file function.h
     
    Defines a simple defines for creating bindings for any kind of function
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

/*! Defines a wrapper for function, which returns some value and receives {{argscount}} arguments
 */
template<
    typename _Context,
    typename _ReturnType{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class ConstructorFunction{{argscount}} : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)({{#args}}{{#not_last}}_Arg{{number}},{{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}});
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction{{argscount}}(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction{{argscount}}<_Context, _ReturnType{{#has_args}},{{/has_args}}{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return {{argscount}};
    }
    
    DUKPP03_CBC_{{argscount}}{{#has_args}}(0,{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}){{/has_args}}
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}

        _ReturnType t = m_callee({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction{{argscount}}() override
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
struct make_constructor_fun 
{

{{#variants}}
/*! Makes callable from function which returns value and receives {{argscount}} arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)({{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}))
{
    return new ConstructorFunction{{argscount}}<_Context, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}

};

}

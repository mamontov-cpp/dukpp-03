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

/*! Defines a wrapper for function, which returns nothing and receives {{argscount}} arguments
 */
template<
    typename _Context{{#has_args}},
{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}{{/args}}
>
class VoidFunction{{argscount}} : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)({{#args}}{{#not_last}}_Arg{{number}},{{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}});
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction{{argscount}}(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction{{argscount}}<_Context{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return {{argscount}};
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {        
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}
        m_callee({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidFunction{{argscount}}()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};
{{/variants}}
{{#variants}}

/*! Defines a wrapper for function, which returns some value and receives {{argscount}} arguments
 */
template<
    typename _Context,
    typename _ReturnType{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class RetFunction{{argscount}} : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)({{#args}}{{#not_last}}_Arg{{number}},{{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}});
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction{{argscount}}(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction{{argscount}}<_Context, _ReturnType{{#has_args}},{{/has_args}}{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return {{argscount}};
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {        
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}

        _ReturnType t = m_callee({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction{{argscount}}()
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
struct make_fun 
{
{{#variants}}
/*! Makes callable from function which returns nothing and receives {{argscount}} arguments
    \param[in] f function
    \return callable version
 */
{{#has_args}}
template<
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
{{/has_args}}
static inline dukpp03::Callable<_Context>* from(void (*f)({{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}))
{
    return new VoidFunction{{argscount}}<_Context{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}

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
    return new RetFunction{{argscount}}<_Context, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}

};

}

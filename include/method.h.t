/*! \file method.h
     
    Defines a simple defines for creating bindings for any kind of method
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
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class VoidMethod{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}});
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod{{argscount}}(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidMethod{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }   
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return {{argscountp1}};
    }

    DUKPP03_CBC_{{argscountp1}}(0,_ClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{numberp1}}, {{numberp2}});
{{/args}}
        ((_ac._())->*m_callee)({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidMethod{{argscount}}() override
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
    typename _ClassName,
    typename _ReturnType{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class RetMethod{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}});
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod{{argscount}}(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetMethod{{argscount}}<_Context, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()   override
    {
        return {{argscountp1}};
    }

    DUKPP03_CBC_{{argscountp1}}(0,_ClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{numberp1}}, {{numberp2}});
{{/args}}
        _ReturnType t = ((_ac._())->*m_callee)({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetMethod{{argscount}}() override
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
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class ConstVoidMethod{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod{{argscount}}(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstVoidMethod{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return {{argscountp1}};
    }

    DUKPP03_CBC_{{argscountp1}}(0,_ClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{numberp1}}, {{numberp2}});
{{/args}}               
        ((_ac._())->*m_callee)({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ConstVoidMethod{{argscount}}() override
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
    typename _ClassName,
    typename _ReturnType{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class ConstRetMethod{{argscount}} : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod{{argscount}}(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstRetMethod{{argscount}}<_Context, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override  
    {
        return {{argscountp1}};
    }

    DUKPP03_CBC_{{argscountp1}}(0,_ClassName*{{#has_args}},{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}{{/has_args}})
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{numberp1}}, {{numberp2}});
{{/args}}               
        _ReturnType t = ((_ac._())->*m_callee)({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}});
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstRetMethod{{argscount}}() override
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
struct make_method
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
    return new VoidMethod{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
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
    return new RetMethod{{argscount}}<_Context, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
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
    return new ConstVoidMethod{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
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
    return new ConstRetMethod{{argscount}}<_Context, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}

};

}

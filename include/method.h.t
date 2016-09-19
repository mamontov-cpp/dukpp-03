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
class VoidMethod{{argscount}} : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidMethod{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return {{argscountp1}};
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != {{argscountp1}})
        {
            c->throwInvalidArgumentCountError({{argscountp1}}, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
{{#args}}
        dukpp03::Maybe< typename dukpp03::Decay<_Arg{{number}}>::Type > _a{{number}} = dukpp03::GetValue< typename dukpp03::Decay<_Arg{{number}}>::Type, _Context >::perform(c, {{numberp1}});
{{/args}}       
        if (_cls.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_ClassName>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        {{#args}}       
        if (_a{{number}}.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg{{number}}>::Type >::type();
            c->throwInvalidTypeError({{numberp2}}, name);
            return 0;
        }
        {{/args}}
        
        try
        {
            ((_cls.mutableValue()).*m_callee)({{#args}}_a{{number}}.mutableValue(){{#not_last}}, {{/not_last}}{{/args}});
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidMethod{{argscount}}()
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
class RetMethod{{argscount}} : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetMethod{{argscount}}<_Context, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return {{argscountp1}};
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != {{argscountp1}})
        {
            c->throwInvalidArgumentCountError({{argscountp1}}, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_ClassName>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

{{#has_args}}{{#args}}        dukpp03::Maybe< typename dukpp03::Decay<_Arg{{number}}>::Type > _a{{number}} = dukpp03::GetValue< typename dukpp03::Decay<_Arg{{number}}>::Type, _Context >::perform(c, {{numberp1}});
        {{/args}}
        
        {{#args}}       
        if (_a{{number}}.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg{{number}}>::Type >::type();
            c->throwInvalidTypeError({{numberp2}}, name);
            return 0;
        }
        {{/args}}

{{/has_args}}       try
        {
            _ReturnType t = ((_cls.mutableValue()).*m_callee)({{#args}}_a{{number}}.mutableValue(){{#not_last}}, {{/not_last}}{{/args}});
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetMethod{{argscount}}()
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
class ConstVoidMethod{{argscount}} : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidMethod{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return {{argscountp1}};
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != {{argscountp1}})
        {
            c->throwInvalidArgumentCountError({{argscountp1}}, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_ClassName>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
{{#args}}
        dukpp03::Maybe< typename dukpp03::Decay<_Arg{{number}}>::Type > _a{{number}} = dukpp03::GetValue< typename dukpp03::Decay<_Arg{{number}}>::Type, _Context >::perform(c, {{numberp1}});
{{/args}} 
        {{#args}}       
        if (_a{{number}}.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg{{number}}>::Type >::type();
            c->throwInvalidTypeError({{numberp2}}, name);
            return 0;
        }
        {{/args}}
        
        try
        {
            ((_cls.mutableValue()).*m_callee)({{#args}}_a{{number}}.mutableValue(){{#not_last}}, {{/not_last}}{{/args}});
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ConstVoidMethod{{argscount}}()
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
class ConstRetMethod{{argscount}} : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetMethod{{argscount}}<_Context, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return {{argscountp1}};
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != {{argscountp1}})
        {
            c->throwInvalidArgumentCountError({{argscountp1}}, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_ClassName>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

{{#has_args}}{{#args}}        dukpp03::Maybe< typename dukpp03::Decay<_Arg{{number}}>::Type > _a{{number}} = dukpp03::GetValue< typename dukpp03::Decay<_Arg{{number}}>::Type, _Context >::perform(c, {{number}});
        {{/args}}
        
        {{#args}}       
        if (_a{{number}}.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg{{number}}>::Type >::type();
            c->throwInvalidTypeError({{numberp2}}, name);
            return 0;
        }
        {{/args}}

{{/has_args}}       try
        {
            _ReturnType t = ((_cls.mutableValue()).*m_callee)({{#args}}_a{{number}}.mutableValue(){{#not_last}}, {{/not_last}}{{/args}});
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstRetMethod{{argscount}}()
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
inline dukpp03::Callable* from(void (_ClassName::*f)({{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}))
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
inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)({{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}))
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
inline dukpp03::Callable* from(void (_ClassName::*f)({{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}) const)
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
inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)({{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}) const)
{
    return new ConstRetMethod{{argscount}}<_Context, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}

};

}

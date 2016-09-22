/*! \file ptrmethod.h
     
    Defines a simple defines for creating bindings for method calls, that will be called on pointer
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
class VoidPtrMethod{{argscount}} : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}});
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod{{argscount}}(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidPtrMethod{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != {{argscountp1}})
        {
            c->throwInvalidArgumentCountError({{argscountp1}}, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
{{#args}}
        dukpp03::Maybe< typename dukpp03::Decay<_Arg{{number}}>::Type > _a{{number}} = dukpp03::GetValue< typename dukpp03::Decay<_Arg{{number}}>::Type, _Context >::perform(c, {{numberp1}});
{{/args}}       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        {{#args}}       
        if (_a{{number}}.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg{{number}} >();
            c->throwInvalidTypeError({{numberp2}}, name);
            return 0;
        }
        {{/args}}
        
        try
        {
            ((_cls.mutableValue())->*m_callee)({{#args}}_a{{number}}.mutableValue(){{#not_last}}, {{/not_last}}{{/args}});
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
    virtual ~VoidPtrMethod{{argscount}}()
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
class RetPtrMethod{{argscount}} : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}});
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod{{argscount}}(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetPtrMethod{{argscount}}<_Context, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != {{argscountp1}})
        {
            c->throwInvalidArgumentCountError({{argscountp1}}, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

{{#has_args}}{{#args}}        dukpp03::Maybe< typename dukpp03::Decay<_Arg{{number}}>::Type > _a{{number}} = dukpp03::GetValue< typename dukpp03::Decay<_Arg{{number}}>::Type, _Context >::perform(c, {{numberp1}});
        {{/args}}
        
        {{#args}}       
        if (_a{{number}}.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg{{number}} >();
            c->throwInvalidTypeError({{numberp2}}, name);
            return 0;
        }
        {{/args}}

{{/has_args}}       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)({{#args}}_a{{number}}.mutableValue(){{#not_last}}, {{/not_last}}{{/args}});
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
    virtual ~RetPtrMethod{{argscount}}()
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
class ConstVoidPtrMethod{{argscount}} : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod{{argscount}}(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidPtrMethod{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != {{argscountp1}})
        {
            c->throwInvalidArgumentCountError({{argscountp1}}, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
{{#args}}
        dukpp03::Maybe< typename dukpp03::Decay<_Arg{{number}}>::Type > _a{{number}} = dukpp03::GetValue< typename dukpp03::Decay<_Arg{{number}}>::Type, _Context >::perform(c, {{numberp1}});
{{/args}} 
        {{#args}}       
        if (_a{{number}}.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg{{number}} >();
            c->throwInvalidTypeError({{numberp2}}, name);
            return 0;
        }
        {{/args}}
        
        try
        {
            ((_cls.mutableValue())->*m_callee)({{#args}}_a{{number}}.mutableValue(){{#not_last}}, {{/not_last}}{{/args}});
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
    virtual ~ConstVoidPtrMethod{{argscount}}()
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
class ConstRetPtrMethod{{argscount}} : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)({{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod{{argscount}}(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetPtrMethod{{argscount}}<_Context, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != {{argscountp1}})
        {
            c->throwInvalidArgumentCountError({{argscountp1}}, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

{{#has_args}}{{#args}}        dukpp03::Maybe< typename dukpp03::Decay<_Arg{{number}}>::Type > _a{{number}} = dukpp03::GetValue< typename dukpp03::Decay<_Arg{{number}}>::Type, _Context >::perform(c, {{number}});
        {{/args}}
        
        {{#args}}       
        if (_a{{number}}.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg{{number}} > ();
            c->throwInvalidTypeError({{numberp2}}, name);
            return 0;
        }
        {{/args}}

{{/has_args}}       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)({{#args}}_a{{number}}.mutableValue(){{#not_last}}, {{/not_last}}{{/args}});
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
    virtual ~ConstRetPtrMethod{{argscount}}()
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
struct make_ptr_method
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
    return new VoidPtrMethod{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
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
    return new RetPtrMethod{{argscount}}<_Context, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
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
    return new ConstVoidPtrMethod{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
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
    return new ConstRetPtrMethod{{argscount}}<_Context, _ClassName, _ReturnType{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>(f);
}

{{/variants}}

};

}

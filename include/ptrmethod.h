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


/*! Defines a wrapper for method, which returns nothing and receives 0 arguments
 */
template<
    typename _Context,
    typename _ClassName
>
class VoidPtrMethod0 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)();
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod0<_Context, _ClassName>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 1;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 1)
        {
            c->throwInvalidArgumentCountError(1, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
                
        try
        {
            ((_cls.mutableValue())->*m_callee)();
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
    virtual ~VoidPtrMethod0()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 1 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0
>
class VoidPtrMethod1 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod1<_Context, _ClassName, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 2;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 2)
        {
            c->throwInvalidArgumentCountError(2, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue());
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
    virtual ~VoidPtrMethod1()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 2 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
class VoidPtrMethod2 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod2<_Context, _ClassName, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 3;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 3)
        {
            c->throwInvalidArgumentCountError(3, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue());
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
    virtual ~VoidPtrMethod2()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 3 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class VoidPtrMethod3 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 4;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 4)
        {
            c->throwInvalidArgumentCountError(4, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue());
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
    virtual ~VoidPtrMethod3()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 4 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class VoidPtrMethod4 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 5;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 5)
        {
            c->throwInvalidArgumentCountError(5, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue());
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
    virtual ~VoidPtrMethod4()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 5 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class VoidPtrMethod5 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 6;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 6)
        {
            c->throwInvalidArgumentCountError(6, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue());
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
    virtual ~VoidPtrMethod5()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 6 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class VoidPtrMethod6 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 7;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 7)
        {
            c->throwInvalidArgumentCountError(7, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue());
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
    virtual ~VoidPtrMethod6()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 7 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
class VoidPtrMethod7 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 8;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 8)
        {
            c->throwInvalidArgumentCountError(8, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue());
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
    virtual ~VoidPtrMethod7()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 8 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7
>
class VoidPtrMethod8 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 9;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 9)
        {
            c->throwInvalidArgumentCountError(9, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue());
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
    virtual ~VoidPtrMethod8()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 9 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8
>
class VoidPtrMethod9 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 10;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 10)
        {
            c->throwInvalidArgumentCountError(10, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue());
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
    virtual ~VoidPtrMethod9()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 10 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9
>
class VoidPtrMethod10 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 11;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 11)
        {
            c->throwInvalidArgumentCountError(11, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue());
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
    virtual ~VoidPtrMethod10()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 11 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10
>
class VoidPtrMethod11 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 12;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 12)
        {
            c->throwInvalidArgumentCountError(12, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue());
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
    virtual ~VoidPtrMethod11()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 12 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11
>
class VoidPtrMethod12 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 13;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 13)
        {
            c->throwInvalidArgumentCountError(13, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue());
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
    virtual ~VoidPtrMethod12()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 13 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12
>
class VoidPtrMethod13 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 14;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 14)
        {
            c->throwInvalidArgumentCountError(14, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue());
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
    virtual ~VoidPtrMethod13()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 14 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13
>
class VoidPtrMethod14 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 15;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 15)
        {
            c->throwInvalidArgumentCountError(15, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 14);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue());
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
    virtual ~VoidPtrMethod14()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 15 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14
>
class VoidPtrMethod15 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 16;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 16)
        {
            c->throwInvalidArgumentCountError(16, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 14);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 15);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
       
        if (_a14.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg14 >();
            c->throwInvalidTypeError(16, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue());
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
    virtual ~VoidPtrMethod15()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 16 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14,
    typename _Arg15
>
class VoidPtrMethod16 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidPtrMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::VoidPtrMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 17;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 17)
        {
            c->throwInvalidArgumentCountError(17, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 14);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 15);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg15>::Type > _a15 = dukpp03::GetValue< typename dukpp03::Decay<_Arg15>::Type, _Context >::perform(c, 16);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
       
        if (_a14.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg14 >();
            c->throwInvalidTypeError(16, name);
            return 0;
        }
       
        if (_a15.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg15 >();
            c->throwInvalidTypeError(17, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue(), _a15.mutableValue());
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
    virtual ~VoidPtrMethod16()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 0 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType
>
class RetPtrMethod0 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)();
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod0<_Context, _ClassName, _ReturnType>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 1;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 1)
        {
            c->throwInvalidArgumentCountError(1, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)();
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
    virtual ~RetPtrMethod0()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 1 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0
>
class RetPtrMethod1 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod1<_Context, _ClassName, _ReturnType, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 2;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 2)
        {
            c->throwInvalidArgumentCountError(2, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue());
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
    virtual ~RetPtrMethod1()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 2 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1
>
class RetPtrMethod2 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 3;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 3)
        {
            c->throwInvalidArgumentCountError(3, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue());
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
    virtual ~RetPtrMethod2()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 3 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class RetPtrMethod3 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 4;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 4)
        {
            c->throwInvalidArgumentCountError(4, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue());
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
    virtual ~RetPtrMethod3()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 4 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class RetPtrMethod4 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 5;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 5)
        {
            c->throwInvalidArgumentCountError(5, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue());
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
    virtual ~RetPtrMethod4()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 5 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class RetPtrMethod5 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 6;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 6)
        {
            c->throwInvalidArgumentCountError(6, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue());
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
    virtual ~RetPtrMethod5()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 6 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class RetPtrMethod6 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 7;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 7)
        {
            c->throwInvalidArgumentCountError(7, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue());
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
    virtual ~RetPtrMethod6()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 7 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
class RetPtrMethod7 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 8;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 8)
        {
            c->throwInvalidArgumentCountError(8, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue());
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
    virtual ~RetPtrMethod7()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 8 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7
>
class RetPtrMethod8 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 9;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 9)
        {
            c->throwInvalidArgumentCountError(9, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue());
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
    virtual ~RetPtrMethod8()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 9 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8
>
class RetPtrMethod9 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 10;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 10)
        {
            c->throwInvalidArgumentCountError(10, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue());
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
    virtual ~RetPtrMethod9()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 10 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9
>
class RetPtrMethod10 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 11;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 11)
        {
            c->throwInvalidArgumentCountError(11, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue());
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
    virtual ~RetPtrMethod10()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 11 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10
>
class RetPtrMethod11 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 12;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 12)
        {
            c->throwInvalidArgumentCountError(12, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue());
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
    virtual ~RetPtrMethod11()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 12 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11
>
class RetPtrMethod12 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 13;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 13)
        {
            c->throwInvalidArgumentCountError(13, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue());
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
    virtual ~RetPtrMethod12()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 13 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12
>
class RetPtrMethod13 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 14;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 14)
        {
            c->throwInvalidArgumentCountError(14, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue());
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
    virtual ~RetPtrMethod13()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 14 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13
>
class RetPtrMethod14 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 15;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 15)
        {
            c->throwInvalidArgumentCountError(15, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 14);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue());
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
    virtual ~RetPtrMethod14()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 15 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14
>
class RetPtrMethod15 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 16;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 16)
        {
            c->throwInvalidArgumentCountError(16, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 14);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 15);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
       
        if (_a14.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg14 >();
            c->throwInvalidTypeError(16, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue());
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
    virtual ~RetPtrMethod15()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 16 arguments
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14,
    typename _Arg15
>
class RetPtrMethod16 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetPtrMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::RetPtrMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 17;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 17)
        {
            c->throwInvalidArgumentCountError(17, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 14);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 15);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg15>::Type > _a15 = dukpp03::GetValue< typename dukpp03::Decay<_Arg15>::Type, _Context >::perform(c, 16);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
       
        if (_a14.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg14 >();
            c->throwInvalidTypeError(16, name);
            return 0;
        }
       
        if (_a15.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg15 >();
            c->throwInvalidTypeError(17, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue(), _a15.mutableValue());
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
    virtual ~RetPtrMethod16()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};


/*! Defines a wrapper for method, which returns nothing and receives 0 arguments
 */
template<
    typename _Context,
    typename _ClassName
>
class ConstVoidPtrMethod0 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)() const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod0(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod0<_Context, _ClassName>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 1;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 1)
        {
            c->throwInvalidArgumentCountError(1, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
 
                
        try
        {
            ((_cls.mutableValue())->*m_callee)();
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
    virtual ~ConstVoidPtrMethod0()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 1 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0
>
class ConstVoidPtrMethod1 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod1(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod1<_Context, _ClassName, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 2;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 2)
        {
            c->throwInvalidArgumentCountError(2, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue());
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
    virtual ~ConstVoidPtrMethod1()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 2 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
class ConstVoidPtrMethod2 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod2(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod2<_Context, _ClassName, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 3;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 3)
        {
            c->throwInvalidArgumentCountError(3, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue());
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
    virtual ~ConstVoidPtrMethod2()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 3 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class ConstVoidPtrMethod3 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod3(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 4;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 4)
        {
            c->throwInvalidArgumentCountError(4, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue());
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
    virtual ~ConstVoidPtrMethod3()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 4 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class ConstVoidPtrMethod4 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod4(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 5;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 5)
        {
            c->throwInvalidArgumentCountError(5, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue());
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
    virtual ~ConstVoidPtrMethod4()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 5 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class ConstVoidPtrMethod5 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod5(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 6;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 6)
        {
            c->throwInvalidArgumentCountError(6, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue());
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
    virtual ~ConstVoidPtrMethod5()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 6 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class ConstVoidPtrMethod6 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod6(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 7;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 7)
        {
            c->throwInvalidArgumentCountError(7, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue());
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
    virtual ~ConstVoidPtrMethod6()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 7 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
class ConstVoidPtrMethod7 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod7(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 8;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 8)
        {
            c->throwInvalidArgumentCountError(8, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue());
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
    virtual ~ConstVoidPtrMethod7()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 8 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7
>
class ConstVoidPtrMethod8 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod8(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 9;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 9)
        {
            c->throwInvalidArgumentCountError(9, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue());
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
    virtual ~ConstVoidPtrMethod8()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 9 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8
>
class ConstVoidPtrMethod9 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod9(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 10;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 10)
        {
            c->throwInvalidArgumentCountError(10, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue());
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
    virtual ~ConstVoidPtrMethod9()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 10 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9
>
class ConstVoidPtrMethod10 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod10(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 11;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 11)
        {
            c->throwInvalidArgumentCountError(11, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue());
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
    virtual ~ConstVoidPtrMethod10()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 11 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10
>
class ConstVoidPtrMethod11 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod11(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 12;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 12)
        {
            c->throwInvalidArgumentCountError(12, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue());
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
    virtual ~ConstVoidPtrMethod11()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 12 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11
>
class ConstVoidPtrMethod12 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod12(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 13;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 13)
        {
            c->throwInvalidArgumentCountError(13, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue());
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
    virtual ~ConstVoidPtrMethod12()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 13 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12
>
class ConstVoidPtrMethod13 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod13(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 14;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 14)
        {
            c->throwInvalidArgumentCountError(14, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue());
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
    virtual ~ConstVoidPtrMethod13()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 14 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13
>
class ConstVoidPtrMethod14 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod14(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 15;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 15)
        {
            c->throwInvalidArgumentCountError(15, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 14);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue());
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
    virtual ~ConstVoidPtrMethod14()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 15 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14
>
class ConstVoidPtrMethod15 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod15(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 16;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 16)
        {
            c->throwInvalidArgumentCountError(16, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 14);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 15);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
       
        if (_a14.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg14 >();
            c->throwInvalidTypeError(16, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue());
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
    virtual ~ConstVoidPtrMethod15()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 16 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14,
    typename _Arg15
>
class ConstVoidPtrMethod16 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidPtrMethod16(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::ConstVoidPtrMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 17;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 17)
        {
            c->throwInvalidArgumentCountError(17, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 14);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 15);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg15>::Type > _a15 = dukpp03::GetValue< typename dukpp03::Decay<_Arg15>::Type, _Context >::perform(c, 16);
 
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
       
        if (_a14.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg14 >();
            c->throwInvalidTypeError(16, name);
            return 0;
        }
       
        if (_a15.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg15 >();
            c->throwInvalidTypeError(17, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue(), _a15.mutableValue());
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
    virtual ~ConstVoidPtrMethod16()
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 0 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType
>
class ConstRetPtrMethod0 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)() const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod0<_Context, _ClassName, _ReturnType>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 1;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 1)
        {
            c->throwInvalidArgumentCountError(1, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)();
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
    virtual ~ConstRetPtrMethod0()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 1 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0
>
class ConstRetPtrMethod1 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod1<_Context, _ClassName, _ReturnType, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 2;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 2)
        {
            c->throwInvalidArgumentCountError(2, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue());
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
    virtual ~ConstRetPtrMethod1()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 2 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1
>
class ConstRetPtrMethod2 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 3;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 3)
        {
            c->throwInvalidArgumentCountError(3, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue());
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
    virtual ~ConstRetPtrMethod2()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 3 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class ConstRetPtrMethod3 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 4;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 4)
        {
            c->throwInvalidArgumentCountError(4, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue());
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
    virtual ~ConstRetPtrMethod3()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 4 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class ConstRetPtrMethod4 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 5;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 5)
        {
            c->throwInvalidArgumentCountError(5, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue());
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
    virtual ~ConstRetPtrMethod4()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 5 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class ConstRetPtrMethod5 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 6;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 6)
        {
            c->throwInvalidArgumentCountError(6, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue());
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
    virtual ~ConstRetPtrMethod5()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 6 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class ConstRetPtrMethod6 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 7;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 7)
        {
            c->throwInvalidArgumentCountError(7, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 > ();
            c->throwInvalidTypeError(7, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue());
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
    virtual ~ConstRetPtrMethod6()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 7 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
class ConstRetPtrMethod7 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 8;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 8)
        {
            c->throwInvalidArgumentCountError(8, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 > ();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 > ();
            c->throwInvalidTypeError(8, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue());
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
    virtual ~ConstRetPtrMethod7()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 8 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7
>
class ConstRetPtrMethod8 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 9;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 9)
        {
            c->throwInvalidArgumentCountError(9, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 > ();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 > ();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 > ();
            c->throwInvalidTypeError(9, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue());
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
    virtual ~ConstRetPtrMethod8()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 9 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8
>
class ConstRetPtrMethod9 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 10;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 10)
        {
            c->throwInvalidArgumentCountError(10, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 > ();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 > ();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 > ();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 > ();
            c->throwInvalidTypeError(10, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue());
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
    virtual ~ConstRetPtrMethod9()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 10 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9
>
class ConstRetPtrMethod10 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 11;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 11)
        {
            c->throwInvalidArgumentCountError(11, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 > ();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 > ();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 > ();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 > ();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 > ();
            c->throwInvalidTypeError(11, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue());
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
    virtual ~ConstRetPtrMethod10()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 11 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10
>
class ConstRetPtrMethod11 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 12;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 12)
        {
            c->throwInvalidArgumentCountError(12, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 > ();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 > ();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 > ();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 > ();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 > ();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 > ();
            c->throwInvalidTypeError(12, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue());
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
    virtual ~ConstRetPtrMethod11()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 12 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11
>
class ConstRetPtrMethod12 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 13;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 13)
        {
            c->throwInvalidArgumentCountError(13, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 > ();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 > ();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 > ();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 > ();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 > ();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 > ();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 > ();
            c->throwInvalidTypeError(13, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue());
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
    virtual ~ConstRetPtrMethod12()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 13 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12
>
class ConstRetPtrMethod13 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 14;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 14)
        {
            c->throwInvalidArgumentCountError(14, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 > ();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 > ();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 > ();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 > ();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 > ();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 > ();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 > ();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 > ();
            c->throwInvalidTypeError(14, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue());
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
    virtual ~ConstRetPtrMethod13()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 14 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13
>
class ConstRetPtrMethod14 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 15;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 15)
        {
            c->throwInvalidArgumentCountError(15, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 13);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 > ();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 > ();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 > ();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 > ();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 > ();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 > ();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 > ();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 > ();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 > ();
            c->throwInvalidTypeError(15, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue());
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
    virtual ~ConstRetPtrMethod14()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 15 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14
>
class ConstRetPtrMethod15 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 16;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 16)
        {
            c->throwInvalidArgumentCountError(16, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 14);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 > ();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 > ();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 > ();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 > ();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 > ();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 > ();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 > ();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 > ();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 > ();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
       
        if (_a14.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg14 > ();
            c->throwInvalidTypeError(16, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue());
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
    virtual ~ConstRetPtrMethod15()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 16 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14,
    typename _Arg15
>
class ConstRetPtrMethod16 : public dukpp03::Callable
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetPtrMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()  
    {
        return new dukpp03::ConstRetPtrMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 17;
    }   
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 17)
        {
            c->throwInvalidArgumentCountError(17, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName*> _cls = dukpp03::GetValue< _ClassName*, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 14);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg15>::Type > _a15 = dukpp03::GetValue< typename dukpp03::Decay<_Arg15>::Type, _Context >::perform(c, 15);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 > ();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 > ();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 > ();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 > ();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 > ();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 > ();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 > ();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 > ();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 > ();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 > ();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 > ();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 > ();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 > ();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 > ();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
       
        if (_a14.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg14 > ();
            c->throwInvalidTypeError(16, name);
            return 0;
        }
       
        if (_a15.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg15 > ();
            c->throwInvalidTypeError(17, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue())->*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue(), _a15.mutableValue());
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
    virtual ~ConstRetPtrMethod16()
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    Method m_callee;
};

template<
    typename _Context
>
struct make_ptr_method
{
/*! Makes callable from method which returns nothing and receives 0 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName
>
static inline dukpp03::Callable* from(void (_ClassName::*f)())
{
    return new VoidPtrMethod0<_Context, _ClassName>(f);
}

/*! Makes callable from method which returns nothing and receives 1 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0))
{
    return new VoidPtrMethod1<_Context, _ClassName, _Arg0>(f);
}

/*! Makes callable from method which returns nothing and receives 2 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1))
{
    return new VoidPtrMethod2<_Context, _ClassName, _Arg0, _Arg1>(f);
}

/*! Makes callable from method which returns nothing and receives 3 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2))
{
    return new VoidPtrMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(f);
}

/*! Makes callable from method which returns nothing and receives 4 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3))
{
    return new VoidPtrMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(f);
}

/*! Makes callable from method which returns nothing and receives 5 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4))
{
    return new VoidPtrMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
}

/*! Makes callable from method which returns nothing and receives 6 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5))
{
    return new VoidPtrMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
}

/*! Makes callable from method which returns nothing and receives 7 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6))
{
    return new VoidPtrMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
}

/*! Makes callable from method which returns nothing and receives 8 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7))
{
    return new VoidPtrMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
}

/*! Makes callable from method which returns nothing and receives 9 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8))
{
    return new VoidPtrMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
}

/*! Makes callable from method which returns nothing and receives 10 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9))
{
    return new VoidPtrMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
}

/*! Makes callable from method which returns nothing and receives 11 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10))
{
    return new VoidPtrMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
}

/*! Makes callable from method which returns nothing and receives 12 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11))
{
    return new VoidPtrMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
}

/*! Makes callable from method which returns nothing and receives 13 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12))
{
    return new VoidPtrMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
}

/*! Makes callable from method which returns nothing and receives 14 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13))
{
    return new VoidPtrMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
}

/*! Makes callable from method which returns nothing and receives 15 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14))
{
    return new VoidPtrMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
}

/*! Makes callable from method which returns nothing and receives 16 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14,
    typename _Arg15
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15))
{
    return new VoidPtrMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


/*! Makes callable from method which returns value and receives 0 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)())
{
    return new RetPtrMethod0<_Context, _ClassName, _ReturnType>(f);
}

/*! Makes callable from method which returns value and receives 1 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0))
{
    return new RetPtrMethod1<_Context, _ClassName, _ReturnType, _Arg0>(f);
}

/*! Makes callable from method which returns value and receives 2 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1))
{
    return new RetPtrMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(f);
}

/*! Makes callable from method which returns value and receives 3 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2))
{
    return new RetPtrMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
}

/*! Makes callable from method which returns value and receives 4 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3))
{
    return new RetPtrMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
}

/*! Makes callable from method which returns value and receives 5 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4))
{
    return new RetPtrMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
}

/*! Makes callable from method which returns value and receives 6 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5))
{
    return new RetPtrMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
}

/*! Makes callable from method which returns value and receives 7 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6))
{
    return new RetPtrMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
}

/*! Makes callable from method which returns value and receives 8 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7))
{
    return new RetPtrMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
}

/*! Makes callable from method which returns value and receives 9 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8))
{
    return new RetPtrMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
}

/*! Makes callable from method which returns value and receives 10 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9))
{
    return new RetPtrMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
}

/*! Makes callable from method which returns value and receives 11 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10))
{
    return new RetPtrMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
}

/*! Makes callable from method which returns value and receives 12 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11))
{
    return new RetPtrMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
}

/*! Makes callable from method which returns value and receives 13 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12))
{
    return new RetPtrMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
}

/*! Makes callable from method which returns value and receives 14 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13))
{
    return new RetPtrMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
}

/*! Makes callable from method which returns value and receives 15 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14))
{
    return new RetPtrMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
}

/*! Makes callable from method which returns value and receives 16 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14,
    typename _Arg15
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15))
{
    return new RetPtrMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}

/*! Makes callable from const method which returns nothing and receives 0 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName
>
static inline dukpp03::Callable* from(void (_ClassName::*f)() const)
{
    return new ConstVoidPtrMethod0<_Context, _ClassName>(f);
}

/*! Makes callable from const method which returns nothing and receives 1 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0) const)
{
    return new ConstVoidPtrMethod1<_Context, _ClassName, _Arg0>(f);
}

/*! Makes callable from const method which returns nothing and receives 2 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1) const)
{
    return new ConstVoidPtrMethod2<_Context, _ClassName, _Arg0, _Arg1>(f);
}

/*! Makes callable from const method which returns nothing and receives 3 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2) const)
{
    return new ConstVoidPtrMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(f);
}

/*! Makes callable from const method which returns nothing and receives 4 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3) const)
{
    return new ConstVoidPtrMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(f);
}

/*! Makes callable from const method which returns nothing and receives 5 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const)
{
    return new ConstVoidPtrMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
}

/*! Makes callable from const method which returns nothing and receives 6 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const)
{
    return new ConstVoidPtrMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
}

/*! Makes callable from const method which returns nothing and receives 7 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const)
{
    return new ConstVoidPtrMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
}

/*! Makes callable from const method which returns nothing and receives 8 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const)
{
    return new ConstVoidPtrMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
}

/*! Makes callable from const method which returns nothing and receives 9 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const)
{
    return new ConstVoidPtrMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
}

/*! Makes callable from const method which returns nothing and receives 10 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const)
{
    return new ConstVoidPtrMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
}

/*! Makes callable from const method which returns nothing and receives 11 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const)
{
    return new ConstVoidPtrMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
}

/*! Makes callable from const method which returns nothing and receives 12 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const)
{
    return new ConstVoidPtrMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
}

/*! Makes callable from const method which returns nothing and receives 13 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const)
{
    return new ConstVoidPtrMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
}

/*! Makes callable from const method which returns nothing and receives 14 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const)
{
    return new ConstVoidPtrMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
}

/*! Makes callable from const method which returns nothing and receives 15 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const)
{
    return new ConstVoidPtrMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
}

/*! Makes callable from const method which returns nothing and receives 16 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14,
    typename _Arg15
>
static inline dukpp03::Callable* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const)
{
    return new ConstVoidPtrMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


/*! Makes callable from const method which returns value and receives 0 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)() const)
{
    return new ConstRetPtrMethod0<_Context, _ClassName, _ReturnType>(f);
}

/*! Makes callable from const method which returns value and receives 1 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0) const)
{
    return new ConstRetPtrMethod1<_Context, _ClassName, _ReturnType, _Arg0>(f);
}

/*! Makes callable from const method which returns value and receives 2 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1) const)
{
    return new ConstRetPtrMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(f);
}

/*! Makes callable from const method which returns value and receives 3 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2) const)
{
    return new ConstRetPtrMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
}

/*! Makes callable from const method which returns value and receives 4 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3) const)
{
    return new ConstRetPtrMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
}

/*! Makes callable from const method which returns value and receives 5 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const)
{
    return new ConstRetPtrMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
}

/*! Makes callable from const method which returns value and receives 6 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const)
{
    return new ConstRetPtrMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
}

/*! Makes callable from const method which returns value and receives 7 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const)
{
    return new ConstRetPtrMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
}

/*! Makes callable from const method which returns value and receives 8 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const)
{
    return new ConstRetPtrMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
}

/*! Makes callable from const method which returns value and receives 9 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const)
{
    return new ConstRetPtrMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
}

/*! Makes callable from const method which returns value and receives 10 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const)
{
    return new ConstRetPtrMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
}

/*! Makes callable from const method which returns value and receives 11 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const)
{
    return new ConstRetPtrMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
}

/*! Makes callable from const method which returns value and receives 12 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const)
{
    return new ConstRetPtrMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
}

/*! Makes callable from const method which returns value and receives 13 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const)
{
    return new ConstRetPtrMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
}

/*! Makes callable from const method which returns value and receives 14 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const)
{
    return new ConstRetPtrMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
}

/*! Makes callable from const method which returns value and receives 15 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const)
{
    return new ConstRetPtrMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
}

/*! Makes callable from const method which returns value and receives 16 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7,
    typename _Arg8,
    typename _Arg9,
    typename _Arg10,
    typename _Arg11,
    typename _Arg12,
    typename _Arg13,
    typename _Arg14,
    typename _Arg15
>
static inline dukpp03::Callable* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const)
{
    return new ConstRetPtrMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


};

}

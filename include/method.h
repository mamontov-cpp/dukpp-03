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


/*! Defines a wrapper for method, which returns nothing and receives 0 arguments
 */
template<
    typename _Context,
    typename _ClassName
>
class VoidMethod0 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)();
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod0<_Context, _ClassName>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 1)
        {
            c->throwInvalidArgumentCountError(1, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
                
        try
        {
            ((_cls.mutableValue()).*m_callee)();
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
    virtual ~VoidMethod0()
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
class VoidMethod1 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod1<_Context, _ClassName, _Arg0>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 2)
        {
            c->throwInvalidArgumentCountError(2, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 1);
       
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
               
        if (_a0.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue());
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
    virtual ~VoidMethod1()
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
class VoidMethod2 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod2<_Context, _ClassName, _Arg0, _Arg1>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 3)
        {
            c->throwInvalidArgumentCountError(3, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue());
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
    virtual ~VoidMethod2()
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
class VoidMethod3 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 4)
        {
            c->throwInvalidArgumentCountError(4, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue());
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
    virtual ~VoidMethod3()
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
class VoidMethod4 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 5)
        {
            c->throwInvalidArgumentCountError(5, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue());
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
    virtual ~VoidMethod4()
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
class VoidMethod5 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 6)
        {
            c->throwInvalidArgumentCountError(6, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue());
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
    virtual ~VoidMethod5()
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
class VoidMethod6 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 7)
        {
            c->throwInvalidArgumentCountError(7, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue());
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
    virtual ~VoidMethod6()
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
class VoidMethod7 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 8)
        {
            c->throwInvalidArgumentCountError(8, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue());
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
    virtual ~VoidMethod7()
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
class VoidMethod8 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 9)
        {
            c->throwInvalidArgumentCountError(9, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue());
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
    virtual ~VoidMethod8()
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
class VoidMethod9 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 10)
        {
            c->throwInvalidArgumentCountError(10, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue());
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
    virtual ~VoidMethod9()
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
class VoidMethod10 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 11)
        {
            c->throwInvalidArgumentCountError(11, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue());
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
    virtual ~VoidMethod10()
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
class VoidMethod11 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 12)
        {
            c->throwInvalidArgumentCountError(12, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue());
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
    virtual ~VoidMethod11()
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
class VoidMethod12 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 13)
        {
            c->throwInvalidArgumentCountError(13, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue());
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
    virtual ~VoidMethod12()
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
class VoidMethod13 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 14)
        {
            c->throwInvalidArgumentCountError(14, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue());
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
    virtual ~VoidMethod13()
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
class VoidMethod14 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 15)
        {
            c->throwInvalidArgumentCountError(15, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue());
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
    virtual ~VoidMethod14()
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
class VoidMethod15 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 16)
        {
            c->throwInvalidArgumentCountError(16, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
       
        if (_a14.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg14 >();
            c->throwInvalidTypeError(16, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue());
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
    virtual ~VoidMethod15()
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
class VoidMethod16 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 17)
        {
            c->throwInvalidArgumentCountError(17, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context>::perform(c, 0);      
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
            std::string name =_Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
       
        if (_a1.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
       
        if (_a2.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
       
        if (_a3.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
       
        if (_a4.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
       
        if (_a5.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
       
        if (_a6.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
       
        if (_a7.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
       
        if (_a8.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
       
        if (_a9.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
       
        if (_a10.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
       
        if (_a11.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
       
        if (_a12.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
       
        if (_a13.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
       
        if (_a14.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg14 >();
            c->throwInvalidTypeError(16, name);
            return 0;
        }
       
        if (_a15.exists() == false) 
        {
            std::string name =_Context::template typeName< _Arg15 >();
            c->throwInvalidTypeError(17, name);
            return 0;
        }
        
        try
        {
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue(), _a15.mutableValue());
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
    virtual ~VoidMethod16()
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
class RetMethod0 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)();
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod0<_Context, _ClassName, _ReturnType>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 1)
        {
            c->throwInvalidArgumentCountError(1, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue()).*m_callee)();
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
    virtual ~RetMethod0()
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
class RetMethod1 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod1<_Context, _ClassName, _ReturnType, _Arg0>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 2)
        {
            c->throwInvalidArgumentCountError(2, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue());
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
    virtual ~RetMethod1()
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
class RetMethod2 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 3)
        {
            c->throwInvalidArgumentCountError(3, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue());
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
    virtual ~RetMethod2()
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
class RetMethod3 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 4)
        {
            c->throwInvalidArgumentCountError(4, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue());
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
    virtual ~RetMethod3()
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
class RetMethod4 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 5)
        {
            c->throwInvalidArgumentCountError(5, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue());
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
    virtual ~RetMethod4()
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
class RetMethod5 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 6)
        {
            c->throwInvalidArgumentCountError(6, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue());
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
    virtual ~RetMethod5()
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
class RetMethod6 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 7)
        {
            c->throwInvalidArgumentCountError(7, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue());
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
    virtual ~RetMethod6()
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
class RetMethod7 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 8)
        {
            c->throwInvalidArgumentCountError(8, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue());
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
    virtual ~RetMethod7()
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
class RetMethod8 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 9)
        {
            c->throwInvalidArgumentCountError(9, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue());
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
    virtual ~RetMethod8()
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
class RetMethod9 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 10)
        {
            c->throwInvalidArgumentCountError(10, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue());
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
    virtual ~RetMethod9()
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
class RetMethod10 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 11)
        {
            c->throwInvalidArgumentCountError(11, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue());
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
    virtual ~RetMethod10()
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
class RetMethod11 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 12)
        {
            c->throwInvalidArgumentCountError(12, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue());
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
    virtual ~RetMethod11()
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
class RetMethod12 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 13)
        {
            c->throwInvalidArgumentCountError(13, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue());
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
    virtual ~RetMethod12()
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
class RetMethod13 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 14)
        {
            c->throwInvalidArgumentCountError(14, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue());
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
    virtual ~RetMethod13()
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
class RetMethod14 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 15)
        {
            c->throwInvalidArgumentCountError(15, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue());
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
    virtual ~RetMethod14()
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
class RetMethod15 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 16)
        {
            c->throwInvalidArgumentCountError(16, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue());
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
    virtual ~RetMethod15()
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
class RetMethod16 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 17)
        {
            c->throwInvalidArgumentCountError(17, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue(), _a15.mutableValue());
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
    virtual ~RetMethod16()
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
class ConstVoidMethod0 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)() const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod0(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod0<_Context, _ClassName>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 1)
        {
            c->throwInvalidArgumentCountError(1, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
 
                
        try
        {
            ((_cls.mutableValue()).*m_callee)();
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
    virtual ~ConstVoidMethod0()
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
class ConstVoidMethod1 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod1(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod1<_Context, _ClassName, _Arg0>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 2)
        {
            c->throwInvalidArgumentCountError(2, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue());
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
    virtual ~ConstVoidMethod1()
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
class ConstVoidMethod2 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod2(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod2<_Context, _ClassName, _Arg0, _Arg1>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 3)
        {
            c->throwInvalidArgumentCountError(3, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue());
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
    virtual ~ConstVoidMethod2()
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
class ConstVoidMethod3 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod3(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 4)
        {
            c->throwInvalidArgumentCountError(4, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue());
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
    virtual ~ConstVoidMethod3()
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
class ConstVoidMethod4 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod4(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 5)
        {
            c->throwInvalidArgumentCountError(5, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue());
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
    virtual ~ConstVoidMethod4()
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
class ConstVoidMethod5 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod5(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 6)
        {
            c->throwInvalidArgumentCountError(6, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue());
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
    virtual ~ConstVoidMethod5()
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
class ConstVoidMethod6 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod6(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 7)
        {
            c->throwInvalidArgumentCountError(7, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue());
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
    virtual ~ConstVoidMethod6()
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
class ConstVoidMethod7 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod7(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 8)
        {
            c->throwInvalidArgumentCountError(8, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue());
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
    virtual ~ConstVoidMethod7()
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
class ConstVoidMethod8 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod8(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 9)
        {
            c->throwInvalidArgumentCountError(9, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue());
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
    virtual ~ConstVoidMethod8()
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
class ConstVoidMethod9 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod9(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 10)
        {
            c->throwInvalidArgumentCountError(10, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue());
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
    virtual ~ConstVoidMethod9()
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
class ConstVoidMethod10 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod10(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 11)
        {
            c->throwInvalidArgumentCountError(11, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue());
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
    virtual ~ConstVoidMethod10()
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
class ConstVoidMethod11 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod11(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 12)
        {
            c->throwInvalidArgumentCountError(12, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue());
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
    virtual ~ConstVoidMethod11()
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
class ConstVoidMethod12 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod12(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 13)
        {
            c->throwInvalidArgumentCountError(13, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue());
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
    virtual ~ConstVoidMethod12()
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
class ConstVoidMethod13 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod13(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 14)
        {
            c->throwInvalidArgumentCountError(14, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue());
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
    virtual ~ConstVoidMethod13()
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
class ConstVoidMethod14 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod14(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 15)
        {
            c->throwInvalidArgumentCountError(15, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue());
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
    virtual ~ConstVoidMethod14()
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
class ConstVoidMethod15 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod15(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 16)
        {
            c->throwInvalidArgumentCountError(16, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue());
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
    virtual ~ConstVoidMethod15()
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
class ConstVoidMethod16 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstVoidMethod16(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ConstVoidMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 17)
        {
            c->throwInvalidArgumentCountError(17, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);   
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
            ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue(), _a15.mutableValue());
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
    virtual ~ConstVoidMethod16()
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
class ConstRetMethod0 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)() const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod0<_Context, _ClassName, _ReturnType>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 1)
        {
            c->throwInvalidArgumentCountError(1, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue()).*m_callee)();
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
    virtual ~ConstRetMethod0()
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
class ConstRetMethod1 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod1<_Context, _ClassName, _ReturnType, _Arg0>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 2)
        {
            c->throwInvalidArgumentCountError(2, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
        if (_cls.exists() == false) 
        {
            std::string name = _Context::template typeName< _ClassName >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        
               
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }

       try
        {
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue());
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
    virtual ~ConstRetMethod1()
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
class ConstRetMethod2 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 3)
        {
            c->throwInvalidArgumentCountError(3, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue());
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
    virtual ~ConstRetMethod2()
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
class ConstRetMethod3 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 4)
        {
            c->throwInvalidArgumentCountError(4, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue());
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
    virtual ~ConstRetMethod3()
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
class ConstRetMethod4 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 5)
        {
            c->throwInvalidArgumentCountError(5, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue());
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
    virtual ~ConstRetMethod4()
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
class ConstRetMethod5 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 6)
        {
            c->throwInvalidArgumentCountError(6, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue());
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
    virtual ~ConstRetMethod5()
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
class ConstRetMethod6 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 7)
        {
            c->throwInvalidArgumentCountError(7, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue());
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
    virtual ~ConstRetMethod6()
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
class ConstRetMethod7 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 8)
        {
            c->throwInvalidArgumentCountError(8, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue());
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
    virtual ~ConstRetMethod7()
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
class ConstRetMethod8 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 9)
        {
            c->throwInvalidArgumentCountError(9, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue());
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
    virtual ~ConstRetMethod8()
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
class ConstRetMethod9 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 10)
        {
            c->throwInvalidArgumentCountError(10, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue());
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
    virtual ~ConstRetMethod9()
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
class ConstRetMethod10 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 11)
        {
            c->throwInvalidArgumentCountError(11, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue());
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
    virtual ~ConstRetMethod10()
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
class ConstRetMethod11 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 12)
        {
            c->throwInvalidArgumentCountError(12, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue());
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
    virtual ~ConstRetMethod11()
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
class ConstRetMethod12 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 13)
        {
            c->throwInvalidArgumentCountError(13, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue());
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
    virtual ~ConstRetMethod12()
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
class ConstRetMethod13 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 14)
        {
            c->throwInvalidArgumentCountError(14, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue());
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
    virtual ~ConstRetMethod13()
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
class ConstRetMethod14 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 15)
        {
            c->throwInvalidArgumentCountError(15, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue());
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
    virtual ~ConstRetMethod14()
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
class ConstRetMethod15 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 16)
        {
            c->throwInvalidArgumentCountError(16, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue());
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
    virtual ~ConstRetMethod15()
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
class ConstRetMethod16 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstRetMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ConstRetMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
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
    virtual int call(_Context* c)
    {
        if (c->getTop() != 17)
        {
            c->throwInvalidArgumentCountError(17, c->getTop());
            return 0;
        }

        dukpp03::Maybe<_ClassName> _cls = dukpp03::GetValue< _ClassName, _Context >::perform(c, 0);  
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
            _ReturnType t = ((_cls.mutableValue()).*m_callee)(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue(), _a15.mutableValue());
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
    virtual ~ConstRetMethod16()
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
struct make_method
{
/*! Makes callable from method which returns nothing and receives 0 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName
>
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)())
{
    return new VoidMethod0<_Context, _ClassName>(f);
}

/*! Makes callable from method which returns nothing and receives 1 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0
>
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0))
{
    return new VoidMethod1<_Context, _ClassName, _Arg0>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1))
{
    return new VoidMethod2<_Context, _ClassName, _Arg0, _Arg1>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2))
{
    return new VoidMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3))
{
    return new VoidMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4))
{
    return new VoidMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5))
{
    return new VoidMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6))
{
    return new VoidMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7))
{
    return new VoidMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8))
{
    return new VoidMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9))
{
    return new VoidMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10))
{
    return new VoidMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11))
{
    return new VoidMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12))
{
    return new VoidMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13))
{
    return new VoidMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14))
{
    return new VoidMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15))
{
    return new VoidMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


/*! Makes callable from method which returns value and receives 0 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType
>
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)())
{
    return new RetMethod0<_Context, _ClassName, _ReturnType>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0))
{
    return new RetMethod1<_Context, _ClassName, _ReturnType, _Arg0>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1))
{
    return new RetMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2))
{
    return new RetMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3))
{
    return new RetMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4))
{
    return new RetMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5))
{
    return new RetMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6))
{
    return new RetMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7))
{
    return new RetMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8))
{
    return new RetMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9))
{
    return new RetMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10))
{
    return new RetMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11))
{
    return new RetMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12))
{
    return new RetMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13))
{
    return new RetMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14))
{
    return new RetMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15))
{
    return new RetMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}

/*! Makes callable from const method which returns nothing and receives 0 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName
>
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)() const)
{
    return new ConstVoidMethod0<_Context, _ClassName>(f);
}

/*! Makes callable from const method which returns nothing and receives 1 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _Arg0
>
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0) const)
{
    return new ConstVoidMethod1<_Context, _ClassName, _Arg0>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1) const)
{
    return new ConstVoidMethod2<_Context, _ClassName, _Arg0, _Arg1>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2) const)
{
    return new ConstVoidMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3) const)
{
    return new ConstVoidMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const)
{
    return new ConstVoidMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const)
{
    return new ConstVoidMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const)
{
    return new ConstVoidMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const)
{
    return new ConstVoidMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const)
{
    return new ConstVoidMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const)
{
    return new ConstVoidMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const)
{
    return new ConstVoidMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const)
{
    return new ConstVoidMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const)
{
    return new ConstVoidMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const)
{
    return new ConstVoidMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const)
{
    return new ConstVoidMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const)
{
    return new ConstVoidMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


/*! Makes callable from const method which returns value and receives 0 arguments
    \param[in] f method
    \return callable version
 */
template<
    typename _ClassName,
    typename _ReturnType
>
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)() const)
{
    return new ConstRetMethod0<_Context, _ClassName, _ReturnType>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0) const)
{
    return new ConstRetMethod1<_Context, _ClassName, _ReturnType, _Arg0>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1) const)
{
    return new ConstRetMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2) const)
{
    return new ConstRetMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3) const)
{
    return new ConstRetMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const)
{
    return new ConstRetMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const)
{
    return new ConstRetMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const)
{
    return new ConstRetMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const)
{
    return new ConstRetMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const)
{
    return new ConstRetMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const)
{
    return new ConstRetMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const)
{
    return new ConstRetMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const)
{
    return new ConstRetMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const)
{
    return new ConstRetMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const)
{
    return new ConstRetMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const)
{
    return new ConstRetMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const)
{
    return new ConstRetMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


};

}

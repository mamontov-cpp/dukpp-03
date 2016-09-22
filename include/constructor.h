/*! \file constructor.h
     
    Defines a simple defines for creating bindings for creating new objects
 */
#pragma once
#include "callable.h"
#include "decay.h"
#include "getvalue.h"
#include "pushvalue.h"
#include "context.h"

namespace dukpp03
{


/*! Defines a wrapper for method, which returns nothing and receives 0 arguments
 */
template<
    typename _Context,
    typename _ClassName
>
class Constructor0 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor0()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor0<_Context, _ClassName>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 0;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(_Context* c)
    {
        if (c->getTop() != 0)
        {
            c->throwInvalidArgumentCountError(0, c->getTop());
            return 0;
        }
        
        try
        {
            _ClassName  t;
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor0()
    {
    }   
};

/*! Defines a wrapper for method, which returns nothing and receives 1 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0
>
class Constructor1 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor1()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor1<_Context, _ClassName, _Arg0>();
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
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
      
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor1()
    {
    }   
};

/*! Defines a wrapper for method, which returns nothing and receives 2 arguments
 */
template<
    typename _Context,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
class Constructor2 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor2()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor2<_Context, _ClassName, _Arg0, _Arg1>();
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
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
      
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor2()
    {
    }   
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
class Constructor3 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor3()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>();
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
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
      
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor3()
    {
    }   
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
class Constructor4 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor4()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>();
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
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
      
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor4()
    {
    }   
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
class Constructor5 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor5()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>();
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
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
      
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor5()
    {
    }   
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
class Constructor6 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor6()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>();
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
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
      
        if (_a0.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg0 >();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor6()
    {
    }   
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
class Constructor7 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor7()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>();
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
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor7()
    {
    }   
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
class Constructor8 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor8()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>();
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
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor8()
    {
    }   
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
class Constructor9 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor9()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>();
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
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor9()
    {
    }   
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
class Constructor10 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor10()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>();
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
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor10()
    {
    }   
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
class Constructor11 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor11()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>();
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
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor11()
    {
    }   
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
class Constructor12 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor12()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>();
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
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
      
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor12()
    {
    }   
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
class Constructor13 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor13()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>();
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
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
      
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
      
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor13()
    {
    }   
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
class Constructor14 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor14()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>();
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
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
      
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
      
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
      
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor14()
    {
    }   
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
class Constructor15 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor15()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>();
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
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
      
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
      
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
      
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
      
        if (_a14.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg14 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor15()
    {
    }   
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
class Constructor16 : public dukpp03::Callable<_Context>
{
public:
    /*! Constructs new object
     */
    Constructor16()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::Constructor16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>();
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
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg1 >();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg2 >();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg3 >();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg4 >();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg5 >();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg6 >();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg7 >();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg8 >();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg9 >();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg10 >();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
      
        if (_a11.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg11 >();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
      
        if (_a12.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg12 >();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
      
        if (_a13.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg13 >();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
      
        if (_a14.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg14 >();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
      
        if (_a15.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg15 >();
            c->throwInvalidTypeError(16, name);
            return 0;
        }
        
        try
        {
            _ClassName  t(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue(), _a15.mutableValue());
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
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
    virtual ~Constructor16()
    {
    }   
};

template<
    typename _Context
>
struct register_constructor
{

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
 */
template<
    typename _ClassName
>
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor0<_Context, _ClassName>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
 */
template<
    typename _ClassName,
    typename _Arg0
>
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor1<_Context, _ClassName, _Arg0>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor2<_Context, _ClassName, _Arg0, _Arg1>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
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
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
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
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
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
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
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
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
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
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
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
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
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
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
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
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
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
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
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
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>();
    ctx->registerCallable(prop, c);
}

/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
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
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable<_Context>* c = new Constructor16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>();
    ctx->registerCallable(prop, c);
}


};

}

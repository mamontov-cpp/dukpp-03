/*! \file constructor.h
     
    Defines a simple defines for creating bindings for creating new QObject instances
 */
#pragma once
#include "callable.h"
#include "context.h"

namespace dukpp03
{

namespace qt
{


/*! Defines a wrapper for method, which returns nothing and receives 0 arguments
 */
template<
    typename _ClassName
>
class Constructor0 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor0<_ClassName>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 0;
    }
    DUKPP03_CBC_0
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        
        _ClassName*  t = new  _ClassName;
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
    typename _ClassName,
    typename _Arg0
>
class Constructor1 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor1<_ClassName, _Arg0>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 1;
    }
    DUKPP03_CBC_1(0,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        
        _ClassName*  t = new  _ClassName(_a0._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
class Constructor2 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor2<_ClassName, _Arg0, _Arg1>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 2;
    }
    DUKPP03_CBC_2(0,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class Constructor3 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor3<_ClassName, _Arg0, _Arg1, _Arg2>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 3;
    }
    DUKPP03_CBC_3(0,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class Constructor4 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor4<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 4;
    }
    DUKPP03_CBC_4(0,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class Constructor5 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor5<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 5;
    }
    DUKPP03_CBC_5(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class Constructor6 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor6<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 6;
    }
    DUKPP03_CBC_6(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
class Constructor7 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor7<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 7;
    }
    DUKPP03_CBC_7(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
class Constructor8 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor8<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 8;
    }
    DUKPP03_CBC_8(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
class Constructor9 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor9<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 9;
    }
    DUKPP03_CBC_9(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
class Constructor10 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor10<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 10;
    }
    DUKPP03_CBC_10(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 9, 10);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
class Constructor11 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor11<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 11;
    }
    DUKPP03_CBC_11(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 10, 11);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
class Constructor12 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor12<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 12;
    }
    DUKPP03_CBC_12(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 11, 12);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
class Constructor13 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor13<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 13;
    }
    DUKPP03_CBC_13(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 12, 13);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
class Constructor14 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor14<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 14;
    }
    DUKPP03_CBC_14(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 13, 14);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
class Constructor15 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor15<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 15;
    }
    DUKPP03_CBC_15(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg14, 14, 14, 15);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
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
class Constructor16 : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local contrxt
     */
    typedef dukpp03::qt::BasicContext _Context;
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
        return new dukpp03::qt::Constructor16<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 16;
    }
    DUKPP03_CBC_16(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg14, 14, 14, 15);
        DUKPP03_MAYBE_FROM_STACK(_Arg15, 15, 15, 16);
        
        _ClassName*  t = new  _ClassName(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~Constructor16()
    {
    }   
};

struct qobject
{

/*! Register constructor as global function of context
    \return callable constructor
 */
template<
    typename _ClassName
>
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor0<_ClassName>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
 */
template<
    typename _ClassName,
    typename _Arg0
>
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor1<_ClassName, _Arg0>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor2<_ClassName, _Arg0, _Arg1>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor3<_ClassName, _Arg0, _Arg1, _Arg2>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor4<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
 */
template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor5<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
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
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor6<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
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
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor7<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
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
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor8<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
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
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor9<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
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
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor10<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
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
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor11<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
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
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor12<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
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
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor13<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
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
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor14<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
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
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor15<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>();
    return c;
}

/*! Register constructor as global function of context
    \return callable constructor
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
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor16<_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>();
    return c;
}


};


}

}

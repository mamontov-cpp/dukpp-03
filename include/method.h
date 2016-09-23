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
class VoidMethod0 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_1(0,_ClassName)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        ((_ac._()).*m_callee)();
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
class VoidMethod1 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_2(0,_ClassName,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        ((_ac._()).*m_callee)(_a0._());
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
class VoidMethod2 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_3(0,_ClassName,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        ((_ac._()).*m_callee)(_a0._(), _a1._());
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
class VoidMethod3 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_4(0,_ClassName,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._());
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
class VoidMethod4 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_5(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
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
class VoidMethod5 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_6(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
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
class VoidMethod6 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_7(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
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
class VoidMethod7 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_8(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
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
class VoidMethod8 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_9(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
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
class VoidMethod9 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_10(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
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
class VoidMethod10 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_11(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
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
class VoidMethod11 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_12(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
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
class VoidMethod12 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_13(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
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
class VoidMethod13 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_14(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
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
class VoidMethod14 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_15(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
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
class VoidMethod15 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_16(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
        DUKPP03_MAYBE_FROM_STACK(_Arg14, 14, 15, 16);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
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
class VoidMethod16 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_17(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
        DUKPP03_MAYBE_FROM_STACK(_Arg14, 14, 15, 16);
        DUKPP03_MAYBE_FROM_STACK(_Arg15, 15, 16, 17);
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
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
class RetMethod0 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_1(0,_ClassName)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        _ReturnType t = ((_ac._()).*m_callee)();
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod1 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_2(0,_ClassName,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod2 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_3(0,_ClassName,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod3 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_4(0,_ClassName,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod4 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_5(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod5 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_6(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod6 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_7(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod7 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_8(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod8 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_9(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod9 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_10(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod10 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_11(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod11 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_12(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod12 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_13(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod13 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_14(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod14 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_15(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod15 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_16(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
        DUKPP03_MAYBE_FROM_STACK(_Arg14, 14, 15, 16);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class RetMethod16 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_17(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
        DUKPP03_MAYBE_FROM_STACK(_Arg14, 14, 15, 16);
        DUKPP03_MAYBE_FROM_STACK(_Arg15, 15, 16, 17);
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstVoidMethod0 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_1(0,_ClassName)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
               
        ((_ac._()).*m_callee)();
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
class ConstVoidMethod1 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_2(0,_ClassName,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
               
        ((_ac._()).*m_callee)(_a0._());
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
class ConstVoidMethod2 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_3(0,_ClassName,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._());
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
class ConstVoidMethod3 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_4(0,_ClassName,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._());
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
class ConstVoidMethod4 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_5(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
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
class ConstVoidMethod5 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_6(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
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
class ConstVoidMethod6 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_7(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
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
class ConstVoidMethod7 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_8(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
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
class ConstVoidMethod8 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_9(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
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
class ConstVoidMethod9 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_10(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
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
class ConstVoidMethod10 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_11(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
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
class ConstVoidMethod11 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_12(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
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
class ConstVoidMethod12 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_13(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
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
class ConstVoidMethod13 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_14(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
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
class ConstVoidMethod14 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_15(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
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
class ConstVoidMethod15 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_16(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
        DUKPP03_MAYBE_FROM_STACK(_Arg14, 14, 15, 16);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
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
class ConstVoidMethod16 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_17(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
        DUKPP03_MAYBE_FROM_STACK(_Arg14, 14, 15, 16);
        DUKPP03_MAYBE_FROM_STACK(_Arg15, 15, 16, 17);
               
        ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
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
class ConstRetMethod0 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_1(0,_ClassName)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
               
        _ReturnType t = ((_ac._()).*m_callee)();
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod1 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_2(0,_ClassName,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod2 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_3(0,_ClassName,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod3 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_4(0,_ClassName,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod4 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_5(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod5 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_6(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod6 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_7(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod7 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_8(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod8 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_9(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod9 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_10(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod10 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_11(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod11 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_12(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod12 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_13(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod13 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_14(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod14 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_15(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod15 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_16(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
        DUKPP03_MAYBE_FROM_STACK(_Arg14, 14, 15, 16);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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
class ConstRetMethod16 : public dukpp03::FunctionCallable<_Context>
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

    DUKPP03_CBC_17(0,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        DUKPP03_MAYBE_FROM_STACK(_Arg9, 9, 10, 11);
        DUKPP03_MAYBE_FROM_STACK(_Arg10, 10, 11, 12);
        DUKPP03_MAYBE_FROM_STACK(_Arg11, 11, 12, 13);
        DUKPP03_MAYBE_FROM_STACK(_Arg12, 12, 13, 14);
        DUKPP03_MAYBE_FROM_STACK(_Arg13, 13, 14, 15);
        DUKPP03_MAYBE_FROM_STACK(_Arg14, 14, 15, 16);
        DUKPP03_MAYBE_FROM_STACK(_Arg15, 15, 16, 17);
               
        _ReturnType t = ((_ac._()).*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
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

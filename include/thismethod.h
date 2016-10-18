/*! \file thismethod.h
     
    Defines a simple defines for creating bindings for any kind of method, that will be called from this
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
class ThisVoidMethod0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)();
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod0<_Context, _ClassName>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_ClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        ((_ac._())->*m_callee)();
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod0()
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
class ThisVoidMethod1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod1<_Context, _ClassName, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_ClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        ((_ac._())->*m_callee)(_a0._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod1()
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
class ThisVoidMethod2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod2<_Context, _ClassName, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 2;
    }

    DUKPP03_CBC_WITH_THIS_2(_ClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        ((_ac._())->*m_callee)(_a0._(), _a1._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod2()
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
class ThisVoidMethod3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 3;
    }

    DUKPP03_CBC_WITH_THIS_3(_ClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod3()
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
class ThisVoidMethod4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 4;
    }

    DUKPP03_CBC_WITH_THIS_4(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod4()
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
class ThisVoidMethod5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 5;
    }

    DUKPP03_CBC_WITH_THIS_5(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod5()
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
class ThisVoidMethod6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 6;
    }

    DUKPP03_CBC_WITH_THIS_6(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod6()
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
class ThisVoidMethod7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 7;
    }

    DUKPP03_CBC_WITH_THIS_7(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod7()
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
class ThisVoidMethod8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 8;
    }

    DUKPP03_CBC_WITH_THIS_8(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod8()
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
class ThisVoidMethod9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 9;
    }

    DUKPP03_CBC_WITH_THIS_9(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod9()
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
class ThisVoidMethod10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 10;
    }

    DUKPP03_CBC_WITH_THIS_10(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod10()
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
class ThisVoidMethod11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 11;
    }

    DUKPP03_CBC_WITH_THIS_11(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod11()
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
class ThisVoidMethod12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 12;
    }

    DUKPP03_CBC_WITH_THIS_12(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod12()
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
class ThisVoidMethod13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 13;
    }

    DUKPP03_CBC_WITH_THIS_13(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod13()
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
class ThisVoidMethod14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 14;
    }

    DUKPP03_CBC_WITH_THIS_14(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod14()
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
class ThisVoidMethod15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 15;
    }

    DUKPP03_CBC_WITH_THIS_15(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod15()
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
class ThisVoidMethod16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisVoidMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 16;
    }

    DUKPP03_CBC_WITH_THIS_16(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidMethod16()
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
class ThisRetMethod0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)();
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod0<_Context, _ClassName, _ReturnType>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_ClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        _ReturnType t = ((_ac._())->*m_callee)();
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod0()
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
class ThisRetMethod1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod1<_Context, _ClassName, _ReturnType, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_ClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod1()
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
class ThisRetMethod2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 2;
    }

    DUKPP03_CBC_WITH_THIS_2(_ClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod2()
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
class ThisRetMethod3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 3;
    }

    DUKPP03_CBC_WITH_THIS_3(_ClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod3()
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
class ThisRetMethod4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 4;
    }

    DUKPP03_CBC_WITH_THIS_4(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod4()
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
class ThisRetMethod5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 5;
    }

    DUKPP03_CBC_WITH_THIS_5(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod5()
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
class ThisRetMethod6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 6;
    }

    DUKPP03_CBC_WITH_THIS_6(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod6()
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
class ThisRetMethod7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 7;
    }

    DUKPP03_CBC_WITH_THIS_7(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod7()
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
class ThisRetMethod8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 8;
    }

    DUKPP03_CBC_WITH_THIS_8(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod8()
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
class ThisRetMethod9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 9;
    }

    DUKPP03_CBC_WITH_THIS_9(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod9()
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
class ThisRetMethod10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 10;
    }

    DUKPP03_CBC_WITH_THIS_10(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod10()
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
class ThisRetMethod11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 11;
    }

    DUKPP03_CBC_WITH_THIS_11(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod11()
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
class ThisRetMethod12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 12;
    }

    DUKPP03_CBC_WITH_THIS_12(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod12()
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
class ThisRetMethod13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 13;
    }

    DUKPP03_CBC_WITH_THIS_13(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod13()
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
class ThisRetMethod14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 14;
    }

    DUKPP03_CBC_WITH_THIS_14(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod14()
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
class ThisRetMethod15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 15;
    }

    DUKPP03_CBC_WITH_THIS_15(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod15()
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
class ThisRetMethod16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisRetMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 16;
    }

    DUKPP03_CBC_WITH_THIS_16(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetMethod16()
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
class ThisConstVoidMethod0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)() const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod0(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod0<_Context, _ClassName>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_ClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
              
        ((_ac._())->*m_callee)();
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod0()
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
class ThisConstVoidMethod1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod1(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod1<_Context, _ClassName, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_ClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
              
        ((_ac._())->*m_callee)(_a0._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod1()
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
class ThisConstVoidMethod2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod2(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod2<_Context, _ClassName, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 2;
    }

    DUKPP03_CBC_WITH_THIS_2(_ClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
              
        ((_ac._())->*m_callee)(_a0._(), _a1._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod2()
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
class ThisConstVoidMethod3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod3(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 3;
    }

    DUKPP03_CBC_WITH_THIS_3(_ClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod3()
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
class ThisConstVoidMethod4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod4(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 4;
    }

    DUKPP03_CBC_WITH_THIS_4(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod4()
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
class ThisConstVoidMethod5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod5(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 5;
    }

    DUKPP03_CBC_WITH_THIS_5(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod5()
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
class ThisConstVoidMethod6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod6(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 6;
    }

    DUKPP03_CBC_WITH_THIS_6(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod6()
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
class ThisConstVoidMethod7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod7(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 7;
    }

    DUKPP03_CBC_WITH_THIS_7(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod7()
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
class ThisConstVoidMethod8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod8(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 8;
    }

    DUKPP03_CBC_WITH_THIS_8(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod8()
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
class ThisConstVoidMethod9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod9(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 9;
    }

    DUKPP03_CBC_WITH_THIS_9(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod9()
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
class ThisConstVoidMethod10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod10(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 10;
    }

    DUKPP03_CBC_WITH_THIS_10(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod10()
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
class ThisConstVoidMethod11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod11(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 11;
    }

    DUKPP03_CBC_WITH_THIS_11(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod11()
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
class ThisConstVoidMethod12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod12(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 12;
    }

    DUKPP03_CBC_WITH_THIS_12(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod12()
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
class ThisConstVoidMethod13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod13(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 13;
    }

    DUKPP03_CBC_WITH_THIS_13(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod13()
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
class ThisConstVoidMethod14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod14(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 14;
    }

    DUKPP03_CBC_WITH_THIS_14(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod14()
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
class ThisConstVoidMethod15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod15(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 15;
    }

    DUKPP03_CBC_WITH_THIS_15(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod15()
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
class ThisConstVoidMethod16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstVoidMethod16(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::ThisConstVoidMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 16;
    }

    DUKPP03_CBC_WITH_THIS_16(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstVoidMethod16()
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
class ThisConstRetMethod0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)() const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod0<_Context, _ClassName, _ReturnType>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_ClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
               
        _ReturnType t = ((_ac._())->*m_callee)();
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod0()
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
class ThisConstRetMethod1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod1<_Context, _ClassName, _ReturnType, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_ClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod1()
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
class ThisConstRetMethod2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 2;
    }

    DUKPP03_CBC_WITH_THIS_2(_ClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod2()
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
class ThisConstRetMethod3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 3;
    }

    DUKPP03_CBC_WITH_THIS_3(_ClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod3()
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
class ThisConstRetMethod4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 4;
    }

    DUKPP03_CBC_WITH_THIS_4(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod4()
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
class ThisConstRetMethod5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 5;
    }

    DUKPP03_CBC_WITH_THIS_5(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod5()
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
class ThisConstRetMethod6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 6;
    }

    DUKPP03_CBC_WITH_THIS_6(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod6()
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
class ThisConstRetMethod7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 7;
    }

    DUKPP03_CBC_WITH_THIS_7(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod7()
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
class ThisConstRetMethod8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 8;
    }

    DUKPP03_CBC_WITH_THIS_8(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod8()
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
class ThisConstRetMethod9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 9;
    }

    DUKPP03_CBC_WITH_THIS_9(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 8, 9);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod9()
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
class ThisConstRetMethod10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 10;
    }

    DUKPP03_CBC_WITH_THIS_10(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod10()
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
class ThisConstRetMethod11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 11;
    }

    DUKPP03_CBC_WITH_THIS_11(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod11()
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
class ThisConstRetMethod12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 12;
    }

    DUKPP03_CBC_WITH_THIS_12(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod12()
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
class ThisConstRetMethod13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 13;
    }

    DUKPP03_CBC_WITH_THIS_13(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod13()
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
class ThisConstRetMethod14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 14;
    }

    DUKPP03_CBC_WITH_THIS_14(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod14()
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
class ThisConstRetMethod15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 15;
    }

    DUKPP03_CBC_WITH_THIS_15(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod15()
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
class ThisConstRetMethod16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisConstRetMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::ThisConstRetMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 16;
    }

    DUKPP03_CBC_WITH_THIS_16(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
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
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisConstRetMethod16()
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
struct bind_method
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
    return new ThisVoidMethod0<_Context, _ClassName>(f);
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
    return new ThisVoidMethod1<_Context, _ClassName, _Arg0>(f);
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
    return new ThisVoidMethod2<_Context, _ClassName, _Arg0, _Arg1>(f);
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
    return new ThisVoidMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(f);
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
    return new ThisVoidMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
    return new ThisVoidMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
    return new ThisVoidMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
    return new ThisVoidMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
    return new ThisVoidMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
    return new ThisVoidMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
    return new ThisVoidMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
    return new ThisVoidMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
    return new ThisVoidMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
    return new ThisVoidMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
    return new ThisVoidMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
    return new ThisVoidMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
    return new ThisVoidMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
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
    return new ThisRetMethod0<_Context, _ClassName, _ReturnType>(f);
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
    return new ThisRetMethod1<_Context, _ClassName, _ReturnType, _Arg0>(f);
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
    return new ThisRetMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(f);
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
    return new ThisRetMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
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
    return new ThisRetMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
    return new ThisRetMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
    return new ThisRetMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
    return new ThisRetMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
    return new ThisRetMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
    return new ThisRetMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
    return new ThisRetMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
    return new ThisRetMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
    return new ThisRetMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
    return new ThisRetMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
    return new ThisRetMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
    return new ThisRetMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
    return new ThisRetMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
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
    return new ThisConstVoidMethod0<_Context, _ClassName>(f);
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
    return new ThisConstVoidMethod1<_Context, _ClassName, _Arg0>(f);
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
    return new ThisConstVoidMethod2<_Context, _ClassName, _Arg0, _Arg1>(f);
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
    return new ThisConstVoidMethod3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>(f);
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
    return new ThisConstVoidMethod4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
    return new ThisConstVoidMethod5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
    return new ThisConstVoidMethod6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
    return new ThisConstVoidMethod7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
    return new ThisConstVoidMethod8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
    return new ThisConstVoidMethod9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
    return new ThisConstVoidMethod10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
    return new ThisConstVoidMethod11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
    return new ThisConstVoidMethod12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
    return new ThisConstVoidMethod13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
    return new ThisConstVoidMethod14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
    return new ThisConstVoidMethod15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
    return new ThisConstVoidMethod16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
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
    return new ThisConstRetMethod0<_Context, _ClassName, _ReturnType>(f);
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
    return new ThisConstRetMethod1<_Context, _ClassName, _ReturnType, _Arg0>(f);
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
    return new ThisConstRetMethod2<_Context, _ClassName, _ReturnType, _Arg0, _Arg1>(f);
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
    return new ThisConstRetMethod3<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
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
    return new ThisConstRetMethod4<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
    return new ThisConstRetMethod5<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
    return new ThisConstRetMethod6<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
    return new ThisConstRetMethod7<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
    return new ThisConstRetMethod8<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
    return new ThisConstRetMethod9<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
    return new ThisConstRetMethod10<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
    return new ThisConstRetMethod11<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
    return new ThisConstRetMethod12<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
    return new ThisConstRetMethod13<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
    return new ThisConstRetMethod14<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
    return new ThisConstRetMethod15<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
    return new ThisConstRetMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


};

}

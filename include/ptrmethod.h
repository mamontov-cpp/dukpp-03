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
class VoidPtrMethod0 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_1(0,_ClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        ((_ac._())->*m_callee)();
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
class VoidPtrMethod1 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_2(0,_ClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        ((_ac._())->*m_callee)(_a0._());
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
class VoidPtrMethod2 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_3(0,_ClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        ((_ac._())->*m_callee)(_a0._(), _a1._());
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
class VoidPtrMethod3 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_4(0,_ClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
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
class VoidPtrMethod4 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_5(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
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
class VoidPtrMethod5 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_6(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
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
class VoidPtrMethod6 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_7(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
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
class VoidPtrMethod7 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_8(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
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
class VoidPtrMethod8 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_9(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
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
class VoidPtrMethod9 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_10(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
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
class VoidPtrMethod10 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_11(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
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
class VoidPtrMethod11 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_12(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
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
class VoidPtrMethod12 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_13(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
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
class VoidPtrMethod13 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_14(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
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
class VoidPtrMethod14 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_15(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
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
class VoidPtrMethod15 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_16(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
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
class VoidPtrMethod16 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_17(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
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
class RetPtrMethod0 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_1(0,_ClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        _ReturnType t = ((_ac._())->*m_callee)();
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod1 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_2(0,_ClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod2 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_3(0,_ClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod3 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_4(0,_ClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod4 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_5(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod5 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_6(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod6 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_7(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod7 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_8(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod8 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_9(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod9 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_10(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod10 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_11(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod11 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_12(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod12 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_13(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod13 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_14(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod14 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_15(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod15 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_16(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class RetPtrMethod16 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_17(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);        
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
class ConstVoidPtrMethod0 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_1(0,_ClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        ((_ac._())->*m_callee)();
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
class ConstVoidPtrMethod1 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_2(0,_ClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        ((_ac._())->*m_callee)(_a0._());
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
class ConstVoidPtrMethod2 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_3(0,_ClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        ((_ac._())->*m_callee)(_a0._(), _a1._());
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
class ConstVoidPtrMethod3 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_4(0,_ClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
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
class ConstVoidPtrMethod4 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_5(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
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
class ConstVoidPtrMethod5 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_6(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
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
class ConstVoidPtrMethod6 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_7(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
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
class ConstVoidPtrMethod7 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_8(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
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
class ConstVoidPtrMethod8 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_9(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
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
class ConstVoidPtrMethod9 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_10(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
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
class ConstVoidPtrMethod10 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_11(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
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
class ConstVoidPtrMethod11 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_12(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
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
class ConstVoidPtrMethod12 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_13(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
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
class ConstVoidPtrMethod13 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_14(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
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
class ConstVoidPtrMethod14 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_15(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
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
class ConstVoidPtrMethod15 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_16(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
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
class ConstVoidPtrMethod16 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()
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

    DUKPP03_CBC_17(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
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
class ConstRetPtrMethod0 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_1(0,_ClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        _ReturnType t = ((_ac._())->*m_callee)();
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod1 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_2(0,_ClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod2 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_3(0,_ClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod3 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_4(0,_ClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod4 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_5(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod5 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_6(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod6 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_7(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod7 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_8(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod8 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_9(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod9 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_10(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 7, 8);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 8, 9);
        DUKPP03_MAYBE_FROM_STACK(_Arg8, 8, 9, 10);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod10 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_11(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod11 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_12(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod12 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_13(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod13 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_14(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod14 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_15(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod15 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_16(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
class ConstRetPtrMethod16 : public dukpp03::FunctionCallable<_Context>
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
    virtual dukpp03::Callable<_Context>* clone()  
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

    DUKPP03_CBC_17(0,_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_STACK(_ClassName*, c, 0, 1);
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
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);   
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)())
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)())
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14))
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15))
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)() const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const)
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
static inline dukpp03::Callable<_Context>* from(void (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)() const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const)
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (_ClassName::*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const)
{
    return new ConstRetPtrMethod16<_Context, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


};

}

/*! \file thisexplicitmethod.h
     
    Defines a simple defines for creating bindings for any kind of method, that will be called from this with specified
    types
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
    typename _Method,
    typename _ClassName
>
class ThisExplicitVoidMethod0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod0(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod0<_Context, _Method,_ClassName>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_ClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        ((_ac._())->*m_callee)();
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisExplicitVoidMethod0() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 1 arguments
 */
template<
    typename _Context,
    typename _Method,
    typename _ClassName,
    typename _Arg0
>
class ThisExplicitVoidMethod1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod1(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod1<_Context, _Method,_ClassName, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_ClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        ((_ac._())->*m_callee)(_a0._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisExplicitVoidMethod1() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 2 arguments
 */
template<
    typename _Context,
    typename _Method,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
class ThisExplicitVoidMethod2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod2(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod2<_Context, _Method,_ClassName, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 2;
    }

    DUKPP03_CBC_WITH_THIS_2(_ClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        ((_ac._())->*m_callee)(_a0._(), _a1._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisExplicitVoidMethod2() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 3 arguments
 */
template<
    typename _Context,
    typename _Method,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class ThisExplicitVoidMethod3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod3(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod3<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 3;
    }

    DUKPP03_CBC_WITH_THIS_3(_ClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod3() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 4 arguments
 */
template<
    typename _Context,
    typename _Method,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class ThisExplicitVoidMethod4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod4(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod4<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 4;
    }

    DUKPP03_CBC_WITH_THIS_4(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod4() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 5 arguments
 */
template<
    typename _Context,
    typename _Method,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class ThisExplicitVoidMethod5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod5(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod5<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 5;
    }

    DUKPP03_CBC_WITH_THIS_5(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod5() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 6 arguments
 */
template<
    typename _Context,
    typename _Method,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class ThisExplicitVoidMethod6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod6(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod6<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 6;
    }

    DUKPP03_CBC_WITH_THIS_6(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod6() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 7 arguments
 */
template<
    typename _Context,
    typename _Method,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
class ThisExplicitVoidMethod7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod7(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod7<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 7;
    }

    DUKPP03_CBC_WITH_THIS_7(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod7() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 8 arguments
 */
template<
    typename _Context,
    typename _Method,
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
class ThisExplicitVoidMethod8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod8(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod8<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 8;
    }

    DUKPP03_CBC_WITH_THIS_8(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod8() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 9 arguments
 */
template<
    typename _Context,
    typename _Method,
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
class ThisExplicitVoidMethod9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod9(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod9<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 9;
    }

    DUKPP03_CBC_WITH_THIS_9(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod9() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 10 arguments
 */
template<
    typename _Context,
    typename _Method,
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
class ThisExplicitVoidMethod10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod10(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod10<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 10;
    }

    DUKPP03_CBC_WITH_THIS_10(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod10() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 11 arguments
 */
template<
    typename _Context,
    typename _Method,
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
class ThisExplicitVoidMethod11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod11(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod11<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 11;
    }

    DUKPP03_CBC_WITH_THIS_11(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod11() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 12 arguments
 */
template<
    typename _Context,
    typename _Method,
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
class ThisExplicitVoidMethod12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod12(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod12<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 12;
    }

    DUKPP03_CBC_WITH_THIS_12(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod12() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 13 arguments
 */
template<
    typename _Context,
    typename _Method,
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
class ThisExplicitVoidMethod13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod13(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod13<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 13;
    }

    DUKPP03_CBC_WITH_THIS_13(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod13() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 14 arguments
 */
template<
    typename _Context,
    typename _Method,
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
class ThisExplicitVoidMethod14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod14(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod14<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 14;
    }

    DUKPP03_CBC_WITH_THIS_14(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod14() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 15 arguments
 */
template<
    typename _Context,
    typename _Method,
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
class ThisExplicitVoidMethod15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod15(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod15<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 15;
    }

    DUKPP03_CBC_WITH_THIS_15(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod15() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns nothing and receives 16 arguments
 */
template<
    typename _Context,
    typename _Method,
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
class ThisExplicitVoidMethod16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitVoidMethod16(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitVoidMethod16<_Context, _Method,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 16;
    }

    DUKPP03_CBC_WITH_THIS_16(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitVoidMethod16() override
    {
    }   
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 0 arguments
 */
template<
    typename _Context, 
    typename _Method,
    typename _ClassName,
    typename _ReturnType
>
class ThisExplicitRetMethod0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod0(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod0<_Context, _Method, _ClassName, _ReturnType>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_ClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        _ReturnType t = ((_ac._())->*m_callee)();
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisExplicitRetMethod0() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 1 arguments
 */
template<
    typename _Context, 
    typename _Method,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0
>
class ThisExplicitRetMethod1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod1(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod1<_Context, _Method, _ClassName, _ReturnType, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_ClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisExplicitRetMethod1() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 2 arguments
 */
template<
    typename _Context, 
    typename _Method,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1
>
class ThisExplicitRetMethod2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod2(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod2<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 2;
    }

    DUKPP03_CBC_WITH_THIS_2(_ClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod2() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 3 arguments
 */
template<
    typename _Context, 
    typename _Method,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class ThisExplicitRetMethod3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod3(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod3<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 3;
    }

    DUKPP03_CBC_WITH_THIS_3(_ClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod3() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 4 arguments
 */
template<
    typename _Context, 
    typename _Method,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class ThisExplicitRetMethod4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod4(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod4<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 4;
    }

    DUKPP03_CBC_WITH_THIS_4(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod4() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 5 arguments
 */
template<
    typename _Context, 
    typename _Method,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class ThisExplicitRetMethod5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod5(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod5<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 5;
    }

    DUKPP03_CBC_WITH_THIS_5(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod5() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 6 arguments
 */
template<
    typename _Context, 
    typename _Method,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class ThisExplicitRetMethod6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod6(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod6<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 6;
    }

    DUKPP03_CBC_WITH_THIS_6(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod6() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 7 arguments
 */
template<
    typename _Context, 
    typename _Method,
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
class ThisExplicitRetMethod7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod7(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod7<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 7;
    }

    DUKPP03_CBC_WITH_THIS_7(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod7() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 8 arguments
 */
template<
    typename _Context, 
    typename _Method,
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
class ThisExplicitRetMethod8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod8(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod8<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 8;
    }

    DUKPP03_CBC_WITH_THIS_8(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod8() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 9 arguments
 */
template<
    typename _Context, 
    typename _Method,
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
class ThisExplicitRetMethod9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod9(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod9<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 9;
    }

    DUKPP03_CBC_WITH_THIS_9(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod9() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 10 arguments
 */
template<
    typename _Context, 
    typename _Method,
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
class ThisExplicitRetMethod10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod10(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod10<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 10;
    }

    DUKPP03_CBC_WITH_THIS_10(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod10() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 11 arguments
 */
template<
    typename _Context, 
    typename _Method,
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
class ThisExplicitRetMethod11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod11(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod11<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 11;
    }

    DUKPP03_CBC_WITH_THIS_11(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod11() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 12 arguments
 */
template<
    typename _Context, 
    typename _Method,
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
class ThisExplicitRetMethod12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod12(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod12<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 12;
    }

    DUKPP03_CBC_WITH_THIS_12(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod12() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 13 arguments
 */
template<
    typename _Context, 
    typename _Method,
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
class ThisExplicitRetMethod13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod13(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod13<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 13;
    }

    DUKPP03_CBC_WITH_THIS_13(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod13() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 14 arguments
 */
template<
    typename _Context, 
    typename _Method,
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
class ThisExplicitRetMethod14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod14(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod14<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 14;
    }

    DUKPP03_CBC_WITH_THIS_14(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod14() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 15 arguments
 */
template<
    typename _Context, 
    typename _Method,
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
class ThisExplicitRetMethod15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod15(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod15<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 15;
    }

    DUKPP03_CBC_WITH_THIS_15(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod15() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

/*! Defines a wrapper for method, which returns some value and receives 16 arguments
 */
template<
    typename _Context, 
    typename _Method,
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
class ThisExplicitRetMethod16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisExplicitRetMethod16(_Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisExplicitRetMethod16<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 16;
    }

    DUKPP03_CBC_WITH_THIS_16(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
    virtual ~ThisExplicitRetMethod16() override
    {
    }
protected:
    /*! A method, which is being wrapped
     */
    _Method m_callee;
};

template<
    typename _Context
>
struct bind_explicit_method
{
template<
    typename _ClassName
>
struct with_args_and_no_return_type0
{

/*! Makes callable from method which returns nothing and receives 0 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod0<_Context, _Method, _ClassName>(f);
}

};


template<
    typename _ClassName,
    typename _Arg0
>
struct with_args_and_no_return_type1
{

/*! Makes callable from method which returns nothing and receives 1 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod1<_Context, _Method, _ClassName, _Arg0>(f);
}

};


template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
struct with_args_and_no_return_type2
{

/*! Makes callable from method which returns nothing and receives 2 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod2<_Context, _Method, _ClassName, _Arg0, _Arg1>(f);
}

};


template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
struct with_args_and_no_return_type3
{

/*! Makes callable from method which returns nothing and receives 3 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod3<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2>(f);
}

};


template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
struct with_args_and_no_return_type4
{

/*! Makes callable from method which returns nothing and receives 4 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod4<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(f);
}

};


template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
struct with_args_and_no_return_type5
{

/*! Makes callable from method which returns nothing and receives 5 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod5<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
}

};


template<
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
struct with_args_and_no_return_type6
{

/*! Makes callable from method which returns nothing and receives 6 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod6<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
}

};


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
struct with_args_and_no_return_type7
{

/*! Makes callable from method which returns nothing and receives 7 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod7<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
}

};


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
struct with_args_and_no_return_type8
{

/*! Makes callable from method which returns nothing and receives 8 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod8<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
}

};


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
struct with_args_and_no_return_type9
{

/*! Makes callable from method which returns nothing and receives 9 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod9<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
}

};


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
struct with_args_and_no_return_type10
{

/*! Makes callable from method which returns nothing and receives 10 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod10<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
}

};


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
struct with_args_and_no_return_type11
{

/*! Makes callable from method which returns nothing and receives 11 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod11<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
}

};


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
struct with_args_and_no_return_type12
{

/*! Makes callable from method which returns nothing and receives 12 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod12<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
}

};


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
struct with_args_and_no_return_type13
{

/*! Makes callable from method which returns nothing and receives 13 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod13<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
}

};


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
struct with_args_and_no_return_type14
{

/*! Makes callable from method which returns nothing and receives 14 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod14<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
}

};


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
struct with_args_and_no_return_type15
{

/*! Makes callable from method which returns nothing and receives 15 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod15<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
}

};


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
struct with_args_and_no_return_type16
{

/*! Makes callable from method which returns nothing and receives 16 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitVoidMethod16<_Context, _Method, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}

};




template<
    typename _ClassName,
    typename _ReturnType
>
struct with_args_and_and_return_type0
{

/*! Makes callable from method which returns value and receives 0 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod0<_Context, _Method, _ClassName, _ReturnType>(f);
}

};


template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0
>
struct with_args_and_and_return_type1
{

/*! Makes callable from method which returns value and receives 1 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod1<_Context, _Method, _ClassName, _ReturnType, _Arg0>(f);
}

};


template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1
>
struct with_args_and_and_return_type2
{

/*! Makes callable from method which returns value and receives 2 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod2<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1>(f);
}

};


template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
struct with_args_and_and_return_type3
{

/*! Makes callable from method which returns value and receives 3 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod3<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
}

};


template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
struct with_args_and_and_return_type4
{

/*! Makes callable from method which returns value and receives 4 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod4<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
}

};


template<
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
struct with_args_and_and_return_type5
{

/*! Makes callable from method which returns value and receives 5 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod5<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
}

};


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
struct with_args_and_and_return_type6
{

/*! Makes callable from method which returns value and receives 6 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod6<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
}

};


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
struct with_args_and_and_return_type7
{

/*! Makes callable from method which returns value and receives 7 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod7<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
}

};


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
struct with_args_and_and_return_type8
{

/*! Makes callable from method which returns value and receives 8 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod8<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
}

};


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
struct with_args_and_and_return_type9
{

/*! Makes callable from method which returns value and receives 9 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod9<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
}

};


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
struct with_args_and_and_return_type10
{

/*! Makes callable from method which returns value and receives 10 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod10<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
}

};


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
struct with_args_and_and_return_type11
{

/*! Makes callable from method which returns value and receives 11 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod11<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
}

};


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
struct with_args_and_and_return_type12
{

/*! Makes callable from method which returns value and receives 12 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod12<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
}

};


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
struct with_args_and_and_return_type13
{

/*! Makes callable from method which returns value and receives 13 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod13<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
}

};


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
struct with_args_and_and_return_type14
{

/*! Makes callable from method which returns value and receives 14 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod14<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
}

};


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
struct with_args_and_and_return_type15
{

/*! Makes callable from method which returns value and receives 15 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod15<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
}

};


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
struct with_args_and_and_return_type16
{

/*! Makes callable from method which returns value and receives 16 arguments
    \param[in] f method
    \return callable version
 */
template<typename _Method>
static inline dukpp03::Callable<_Context>* from(_Method f)
{
    return new ThisExplicitRetMethod16<_Context, _Method, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}

};


};

}

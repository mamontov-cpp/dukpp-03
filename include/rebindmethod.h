/*! \file rebindmethod.h
     
    Defines a simple defines for creating bindings for any kind of method, that will be called from this but with another class
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
    typename _RebindedClassName,
    typename _ClassName
>
class RebindedThisVoidMethod0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)();
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod0<_Context, _RebindedClassName, _ClassName>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_RebindedClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        ((_ac._())->*m_callee)();
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisVoidMethod0() override
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0
>
class RebindedThisVoidMethod1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod1<_Context, _RebindedClassName, _ClassName, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_RebindedClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        ((_ac._())->*m_callee)(_a0._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisVoidMethod1() override
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
class RebindedThisVoidMethod2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod2<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 2;
    }

    DUKPP03_CBC_WITH_THIS_2(_RebindedClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        ((_ac._())->*m_callee)(_a0._(), _a1._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisVoidMethod2() override
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class RebindedThisVoidMethod3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod3<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 3;
    }

    DUKPP03_CBC_WITH_THIS_3(_RebindedClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisVoidMethod3() override
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class RebindedThisVoidMethod4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod4<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 4;
    }

    DUKPP03_CBC_WITH_THIS_4(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisVoidMethod4() override
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class RebindedThisVoidMethod5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod5<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 5;
    }

    DUKPP03_CBC_WITH_THIS_5(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod5() override
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class RebindedThisVoidMethod6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod6<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 6;
    }

    DUKPP03_CBC_WITH_THIS_6(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod6() override
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
class RebindedThisVoidMethod7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod7<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 7;
    }

    DUKPP03_CBC_WITH_THIS_7(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod7() override
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
    typename _RebindedClassName,
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
class RebindedThisVoidMethod8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod8<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 8;
    }

    DUKPP03_CBC_WITH_THIS_8(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod8() override
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
    typename _RebindedClassName,
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
class RebindedThisVoidMethod9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod9<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 9;
    }

    DUKPP03_CBC_WITH_THIS_9(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod9() override
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
    typename _RebindedClassName,
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
class RebindedThisVoidMethod10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod10<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 10;
    }

    DUKPP03_CBC_WITH_THIS_10(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod10() override
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
    typename _RebindedClassName,
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
class RebindedThisVoidMethod11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod11<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 11;
    }

    DUKPP03_CBC_WITH_THIS_11(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod11() override
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
    typename _RebindedClassName,
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
class RebindedThisVoidMethod12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod12<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 12;
    }

    DUKPP03_CBC_WITH_THIS_12(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod12() override
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
    typename _RebindedClassName,
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
class RebindedThisVoidMethod13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod13<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 13;
    }

    DUKPP03_CBC_WITH_THIS_13(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod13() override
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
    typename _RebindedClassName,
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
class RebindedThisVoidMethod14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod14<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 14;
    }

    DUKPP03_CBC_WITH_THIS_14(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod14() override
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
    typename _RebindedClassName,
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
class RebindedThisVoidMethod15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod15<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 15;
    }

    DUKPP03_CBC_WITH_THIS_15(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod15() override
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
    typename _RebindedClassName,
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
class RebindedThisVoidMethod16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisVoidMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisVoidMethod16<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 16;
    }

    DUKPP03_CBC_WITH_THIS_16(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisVoidMethod16() override
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType
>
class RebindedThisRetMethod0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)();
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod0<_Context, _RebindedClassName, _ClassName, _ReturnType>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_RebindedClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        _ReturnType t = ((_ac._())->*m_callee)();
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisRetMethod0()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0
>
class RebindedThisRetMethod1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod1<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_RebindedClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisRetMethod1()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1
>
class RebindedThisRetMethod2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod2<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 2;
    }

    DUKPP03_CBC_WITH_THIS_2(_RebindedClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisRetMethod2()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class RebindedThisRetMethod3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod3<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 3;
    }

    DUKPP03_CBC_WITH_THIS_3(_RebindedClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisRetMethod3()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class RebindedThisRetMethod4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod4<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 4;
    }

    DUKPP03_CBC_WITH_THIS_4(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod4()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class RebindedThisRetMethod5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod5<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 5;
    }

    DUKPP03_CBC_WITH_THIS_5(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod5()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class RebindedThisRetMethod6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod6<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 6;
    }

    DUKPP03_CBC_WITH_THIS_6(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod6()
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
    typename _RebindedClassName,
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
class RebindedThisRetMethod7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod7<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 7;
    }

    DUKPP03_CBC_WITH_THIS_7(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod7()
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
    typename _RebindedClassName,
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
class RebindedThisRetMethod8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod8<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 8;
    }

    DUKPP03_CBC_WITH_THIS_8(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod8()
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
    typename _RebindedClassName,
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
class RebindedThisRetMethod9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod9<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 9;
    }

    DUKPP03_CBC_WITH_THIS_9(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod9()
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
    typename _RebindedClassName,
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
class RebindedThisRetMethod10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod10<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 10;
    }

    DUKPP03_CBC_WITH_THIS_10(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod10()
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
    typename _RebindedClassName,
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
class RebindedThisRetMethod11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod11<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 11;
    }

    DUKPP03_CBC_WITH_THIS_11(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod11()
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
    typename _RebindedClassName,
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
class RebindedThisRetMethod12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod12<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 12;
    }

    DUKPP03_CBC_WITH_THIS_12(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod12()
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
    typename _RebindedClassName,
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
class RebindedThisRetMethod13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod13<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 13;
    }

    DUKPP03_CBC_WITH_THIS_13(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod13()
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
    typename _RebindedClassName,
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
class RebindedThisRetMethod14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod14<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 14;
    }

    DUKPP03_CBC_WITH_THIS_14(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod14()
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
    typename _RebindedClassName,
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
class RebindedThisRetMethod15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod15<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 15;
    }

    DUKPP03_CBC_WITH_THIS_15(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod15()
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
    typename _RebindedClassName,
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
class RebindedThisRetMethod16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisRetMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override 
    {
        return new dukpp03::RebindedThisRetMethod16<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 16;
    }

    DUKPP03_CBC_WITH_THIS_16(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisRetMethod16()
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
    typename _RebindedClassName,
    typename _ClassName
>
class RebindedThisConstVoidMethod0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)() const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod0(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod0<_Context, _RebindedClassName, _ClassName>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_RebindedClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
              
        ((_ac._())->*m_callee)();
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisConstVoidMethod0()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0
>
class RebindedThisConstVoidMethod1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod1(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod1<_Context, _RebindedClassName, _ClassName, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_RebindedClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
              
        ((_ac._())->*m_callee)(_a0._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisConstVoidMethod1()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
class RebindedThisConstVoidMethod2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod2(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod2<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 2;
    }

    DUKPP03_CBC_WITH_THIS_2(_RebindedClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
              
        ((_ac._())->*m_callee)(_a0._(), _a1._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisConstVoidMethod2()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class RebindedThisConstVoidMethod3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod3(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod3<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 3;
    }

    DUKPP03_CBC_WITH_THIS_3(_RebindedClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisConstVoidMethod3()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class RebindedThisConstVoidMethod4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod4(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod4<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 4;
    }

    DUKPP03_CBC_WITH_THIS_4(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
              
        ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._(), _a3._());
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisConstVoidMethod4()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class RebindedThisConstVoidMethod5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod5(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod5<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 5;
    }

    DUKPP03_CBC_WITH_THIS_5(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod5()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class RebindedThisConstVoidMethod6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod6(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod6<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 6;
    }

    DUKPP03_CBC_WITH_THIS_6(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod6()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
class RebindedThisConstVoidMethod7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod7(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod7<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 7;
    }

    DUKPP03_CBC_WITH_THIS_7(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod7()
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
    typename _RebindedClassName,
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
class RebindedThisConstVoidMethod8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod8(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod8<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 8;
    }

    DUKPP03_CBC_WITH_THIS_8(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod8()
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
    typename _RebindedClassName,
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
class RebindedThisConstVoidMethod9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod9(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod9<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 9;
    }

    DUKPP03_CBC_WITH_THIS_9(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod9()
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
    typename _RebindedClassName,
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
class RebindedThisConstVoidMethod10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod10(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod10<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 10;
    }

    DUKPP03_CBC_WITH_THIS_10(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod10()
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
    typename _RebindedClassName,
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
class RebindedThisConstVoidMethod11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod11(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod11<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 11;
    }

    DUKPP03_CBC_WITH_THIS_11(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod11()
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
    typename _RebindedClassName,
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
class RebindedThisConstVoidMethod12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod12(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod12<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 12;
    }

    DUKPP03_CBC_WITH_THIS_12(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod12()
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
    typename _RebindedClassName,
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
class RebindedThisConstVoidMethod13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod13(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod13<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 13;
    }

    DUKPP03_CBC_WITH_THIS_13(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod13()
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
    typename _RebindedClassName,
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
class RebindedThisConstVoidMethod14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod14(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod14<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 14;
    }

    DUKPP03_CBC_WITH_THIS_14(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod14()
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
    typename _RebindedClassName,
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
class RebindedThisConstVoidMethod15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod15(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod15<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 15;
    }

    DUKPP03_CBC_WITH_THIS_15(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod15()
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
    typename _RebindedClassName,
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
class RebindedThisConstVoidMethod16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstVoidMethod16(Method f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::RebindedThisConstVoidMethod16<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 16;
    }

    DUKPP03_CBC_WITH_THIS_16(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstVoidMethod16()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType
>
class RebindedThisConstRetMethod0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)() const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod0(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod0<_Context, _RebindedClassName, _ClassName, _ReturnType>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_RebindedClassName*)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
               
        _ReturnType t = ((_ac._())->*m_callee)();
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisConstRetMethod0()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0
>
class RebindedThisConstRetMethod1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod1(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod1<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_RebindedClassName*,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisConstRetMethod1()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1
>
class RebindedThisConstRetMethod2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod2(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod2<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 2;
    }

    DUKPP03_CBC_WITH_THIS_2(_RebindedClassName*,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisConstRetMethod2()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class RebindedThisConstRetMethod3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod3(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod3<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 3;
    }

    DUKPP03_CBC_WITH_THIS_3(_RebindedClassName*,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
               
        _ReturnType t = ((_ac._())->*m_callee)(_a0._(), _a1._(), _a2._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RebindedThisConstRetMethod3()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class RebindedThisConstRetMethod4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod4(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod4<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 4;
    }

    DUKPP03_CBC_WITH_THIS_4(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod4()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class RebindedThisConstRetMethod5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod5(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod5<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 5;
    }

    DUKPP03_CBC_WITH_THIS_5(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod5()
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
    typename _RebindedClassName,
    typename _ClassName,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class RebindedThisConstRetMethod6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod6(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod6<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 6;
    }

    DUKPP03_CBC_WITH_THIS_6(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod6()
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
    typename _RebindedClassName,
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
class RebindedThisConstRetMethod7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod7(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod7<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 7;
    }

    DUKPP03_CBC_WITH_THIS_7(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod7()
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
    typename _RebindedClassName,
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
class RebindedThisConstRetMethod8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod8(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod8<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 8;
    }

    DUKPP03_CBC_WITH_THIS_8(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod8()
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
    typename _RebindedClassName,
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
class RebindedThisConstRetMethod9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod9(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod9<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 9;
    }

    DUKPP03_CBC_WITH_THIS_9(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod9()
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
    typename _RebindedClassName,
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
class RebindedThisConstRetMethod10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod10(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod10<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 10;
    }

    DUKPP03_CBC_WITH_THIS_10(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod10()
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
    typename _RebindedClassName,
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
class RebindedThisConstRetMethod11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod11(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod11<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 11;
    }

    DUKPP03_CBC_WITH_THIS_11(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod11()
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
    typename _RebindedClassName,
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
class RebindedThisConstRetMethod12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod12(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod12<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 12;
    }

    DUKPP03_CBC_WITH_THIS_12(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod12()
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
    typename _RebindedClassName,
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
class RebindedThisConstRetMethod13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod13(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod13<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 13;
    }

    DUKPP03_CBC_WITH_THIS_13(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod13()
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
    typename _RebindedClassName,
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
class RebindedThisConstRetMethod14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod14(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod14<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 14;
    }

    DUKPP03_CBC_WITH_THIS_14(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod14()
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
    typename _RebindedClassName,
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
class RebindedThisConstRetMethod15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod15(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod15<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 15;
    }

    DUKPP03_CBC_WITH_THIS_15(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod15()
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
    typename _RebindedClassName,
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
class RebindedThisConstRetMethod16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (_ClassName::*Method)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15) const;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RebindedThisConstRetMethod16(Method f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RebindedThisConstRetMethod16<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 16;
    }

    DUKPP03_CBC_WITH_THIS_16(_RebindedClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {
        DUKPP03_MAYBE_FROM_THIS(_RebindedClassName*);
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
    virtual ~RebindedThisConstRetMethod16()
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
struct rebind_method
{

template<
	typename _RebindedClassName
>
struct to
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
    return new RebindedThisVoidMethod0<_Context, _RebindedClassName, _ClassName>(f);
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
    return new RebindedThisVoidMethod1<_Context, _RebindedClassName, _ClassName, _Arg0>(f);
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
    return new RebindedThisVoidMethod2<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1>(f);
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
    return new RebindedThisVoidMethod3<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2>(f);
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
    return new RebindedThisVoidMethod4<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
    return new RebindedThisVoidMethod5<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
    return new RebindedThisVoidMethod6<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
    return new RebindedThisVoidMethod7<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
    return new RebindedThisVoidMethod8<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
    return new RebindedThisVoidMethod9<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
    return new RebindedThisVoidMethod10<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
    return new RebindedThisVoidMethod11<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
    return new RebindedThisVoidMethod12<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
    return new RebindedThisVoidMethod13<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
    return new RebindedThisVoidMethod14<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
    return new RebindedThisVoidMethod15<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
    return new RebindedThisVoidMethod16<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
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
    return new RebindedThisRetMethod0<_Context, _RebindedClassName, _ClassName, _ReturnType>(f);
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
    return new RebindedThisRetMethod1<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0>(f);
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
    return new RebindedThisRetMethod2<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1>(f);
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
    return new RebindedThisRetMethod3<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
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
    return new RebindedThisRetMethod4<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
    return new RebindedThisRetMethod5<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
    return new RebindedThisRetMethod6<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
    return new RebindedThisRetMethod7<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
    return new RebindedThisRetMethod8<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
    return new RebindedThisRetMethod9<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
    return new RebindedThisRetMethod10<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
    return new RebindedThisRetMethod11<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
    return new RebindedThisRetMethod12<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
    return new RebindedThisRetMethod13<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
    return new RebindedThisRetMethod14<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
    return new RebindedThisRetMethod15<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
    return new RebindedThisRetMethod16<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
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
    return new RebindedThisConstVoidMethod0<_Context, _RebindedClassName, _ClassName>(f);
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
    return new RebindedThisConstVoidMethod1<_Context, _RebindedClassName, _ClassName, _Arg0>(f);
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
    return new RebindedThisConstVoidMethod2<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1>(f);
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
    return new RebindedThisConstVoidMethod3<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2>(f);
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
    return new RebindedThisConstVoidMethod4<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
    return new RebindedThisConstVoidMethod5<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
    return new RebindedThisConstVoidMethod6<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
    return new RebindedThisConstVoidMethod7<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
    return new RebindedThisConstVoidMethod8<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
    return new RebindedThisConstVoidMethod9<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
    return new RebindedThisConstVoidMethod10<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
    return new RebindedThisConstVoidMethod11<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
    return new RebindedThisConstVoidMethod12<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
    return new RebindedThisConstVoidMethod13<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
    return new RebindedThisConstVoidMethod14<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
    return new RebindedThisConstVoidMethod15<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
    return new RebindedThisConstVoidMethod16<_Context, _RebindedClassName, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
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
    return new RebindedThisConstRetMethod0<_Context, _RebindedClassName, _ClassName, _ReturnType>(f);
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
    return new RebindedThisConstRetMethod1<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0>(f);
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
    return new RebindedThisConstRetMethod2<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1>(f);
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
    return new RebindedThisConstRetMethod3<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
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
    return new RebindedThisConstRetMethod4<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
    return new RebindedThisConstRetMethod5<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
    return new RebindedThisConstRetMethod6<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
    return new RebindedThisConstRetMethod7<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
    return new RebindedThisConstRetMethod8<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
    return new RebindedThisConstRetMethod9<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
    return new RebindedThisConstRetMethod10<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
    return new RebindedThisConstRetMethod11<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
    return new RebindedThisConstRetMethod12<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
    return new RebindedThisConstRetMethod13<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
    return new RebindedThisConstRetMethod14<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
    return new RebindedThisConstRetMethod15<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
    return new RebindedThisConstRetMethod16<_Context, _RebindedClassName, _ClassName, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


};

};

}

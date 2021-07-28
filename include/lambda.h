/*! \file lambda.h
     
    Defines a simple defines for creating bindings for lambdas
 */
#pragma once
#include "callable.h"
#include "decay.h"
#include "getvalue.h"
#include "pushvalue.h"
#include "errorcodes.h"
#include "context.h"

#include <functional>

namespace dukpp03
{

/*! Defines a wrapper for lambda function, which returns nothing and receives 0 arguments
 */
template<
    typename _Context
>
class VoidLambda0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void()> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda0(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda0<_Context>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 0;
    }
    
    DUKPP03_CBC_0
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        m_callee();        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda0() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 1 arguments
 */
template<
    typename _Context,
    typename _Arg0
>
class VoidLambda1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda1(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda1<_Context, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 1;
    }
    
    DUKPP03_CBC_1(0,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        m_callee(_a0._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda1() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 2 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1
>
class VoidLambda2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda2(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda2<_Context, _Arg0,_Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 2;
    }
    
    DUKPP03_CBC_2(0,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        m_callee(_a0._(), _a1._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda2() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 3 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2
>
class VoidLambda3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda3(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda3<_Context, _Arg0,_Arg1,_Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 3;
    }
    
    DUKPP03_CBC_3(0,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        m_callee(_a0._(), _a1._(), _a2._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda3() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 4 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3
>
class VoidLambda4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda4(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda4<_Context, _Arg0,_Arg1,_Arg2,_Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 4;
    }
    
    DUKPP03_CBC_4(0,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        m_callee(_a0._(), _a1._(), _a2._(), _a3._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda4() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 5 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4
>
class VoidLambda5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda5(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda5<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 5;
    }
    
    DUKPP03_CBC_5(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda5() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 6 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5
>
class VoidLambda6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda6(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda6<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 6;
    }
    
    DUKPP03_CBC_6(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda6() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 7 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6
>
class VoidLambda7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda7(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda7<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 7;
    }
    
    DUKPP03_CBC_7(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda7() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 8 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7
>
class VoidLambda8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda8(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda8<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 8;
    }
    
    DUKPP03_CBC_8(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda8() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 9 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8
>
class VoidLambda9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda9(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda9<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 9;
    }
    
    DUKPP03_CBC_9(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda9() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 10 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9
>
class VoidLambda10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda10(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda10<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 10;
    }
    
    DUKPP03_CBC_10(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda10() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 11 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10
>
class VoidLambda11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda11(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda11<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 11;
    }
    
    DUKPP03_CBC_11(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda11() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 12 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11
>
class VoidLambda12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda12(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda12<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 12;
    }
    
    DUKPP03_CBC_12(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda12() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 13 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12
>
class VoidLambda13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda13(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda13<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 13;
    }
    
    DUKPP03_CBC_13(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda13() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 14 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12,    typename _Arg13
>
class VoidLambda14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda14(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda14<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 14;
    }
    
    DUKPP03_CBC_14(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda14() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 15 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12,    typename _Arg13,    typename _Arg14
>
class VoidLambda15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda15(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda15<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 15;
    }
    
    DUKPP03_CBC_15(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda15() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda function, which returns nothing and receives 16 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12,    typename _Arg13,    typename _Arg14,    typename _Arg15
>
class VoidLambda16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidLambda16(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::VoidLambda16<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 16;
    }
    
    DUKPP03_CBC_16(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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
        m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidLambda16() override
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 0 arguments
 */
template<
    typename _Context,
    typename _ReturnType
>
class RetLambda0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType()> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda0(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda0<_Context, _ReturnType>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 0;
    }
    
    DUKPP03_CBC_0
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        

        _ReturnType t = m_callee();
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda0() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 1 arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _Arg0
>
class RetLambda1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda1(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda1<_Context, _ReturnType,_Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 1;
    }
    
    DUKPP03_CBC_1(0,_Arg0)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);

        _ReturnType t = m_callee(_a0._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda1() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 2 arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1
>
class RetLambda2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda2(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda2<_Context, _ReturnType,_Arg0,_Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 2;
    }
    
    DUKPP03_CBC_2(0,_Arg0,_Arg1)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);

        _ReturnType t = m_callee(_a0._(), _a1._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda2() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 3 arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class RetLambda3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda3(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda3<_Context, _ReturnType,_Arg0,_Arg1,_Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 3;
    }
    
    DUKPP03_CBC_3(0,_Arg0,_Arg1,_Arg2)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda3() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 4 arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class RetLambda4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda4(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda4<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 4;
    }
    
    DUKPP03_CBC_4(0,_Arg0,_Arg1,_Arg2,_Arg3)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda4() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 5 arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class RetLambda5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda5(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda5<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 5;
    }
    
    DUKPP03_CBC_5(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda5() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 6 arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class RetLambda6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda6(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda6<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 6;
    }
    
    DUKPP03_CBC_6(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda6() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 7 arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
class RetLambda7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda7(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda7<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 7;
    }
    
    DUKPP03_CBC_7(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda7() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 8 arguments
 */
template<
    typename _Context,
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
class RetLambda8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda8(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda8<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 8;
    }
    
    DUKPP03_CBC_8(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);
        DUKPP03_MAYBE_FROM_STACK(_Arg7, 7, 7, 8);

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda8() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 9 arguments
 */
template<
    typename _Context,
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
class RetLambda9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda9(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda9<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 9;
    }
    
    DUKPP03_CBC_9(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda9() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 10 arguments
 */
template<
    typename _Context,
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
class RetLambda10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda10(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda10<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 10;
    }
    
    DUKPP03_CBC_10(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda10() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 11 arguments
 */
template<
    typename _Context,
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
class RetLambda11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda11(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda11<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 11;
    }
    
    DUKPP03_CBC_11(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda11() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 12 arguments
 */
template<
    typename _Context,
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
class RetLambda12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda12(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda12<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 12;
    }
    
    DUKPP03_CBC_12(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda12() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 13 arguments
 */
template<
    typename _Context,
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
class RetLambda13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda13(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda13<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 13;
    }
    
    DUKPP03_CBC_13(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda13() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 14 arguments
 */
template<
    typename _Context,
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
class RetLambda14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda14(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda14<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 14;
    }
    
    DUKPP03_CBC_14(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda14() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 15 arguments
 */
template<
    typename _Context,
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
class RetLambda15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda15(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda15<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 15;
    }
    
    DUKPP03_CBC_15(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda15() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for lambda, which returns some value and receives 16 arguments
 */
template<
    typename _Context,
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
class RetLambda16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetLambda16(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::RetLambda16<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return 16;
    }
    
    DUKPP03_CBC_16(0,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c) override
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

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetLambda16() override
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

template<
    typename _Context
>
struct make_lambda 
{
/*! Makes callable from function which returns nothing and receives 0 arguments
    \param[in] f function
    \return callable version
 */
static inline dukpp03::Callable<_Context>* from(std::function<void()> f)
{
    return new VoidLambda0<_Context>(f);
}

/*! Makes callable from function which returns nothing and receives 1 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0)> f)
{
    return new VoidLambda1<_Context, _Arg0>(f);
}

/*! Makes callable from function which returns nothing and receives 2 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1)> f)
{
    return new VoidLambda2<_Context, _Arg0, _Arg1>(f);
}

/*! Makes callable from function which returns nothing and receives 3 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2)> f)
{
    return new VoidLambda3<_Context, _Arg0, _Arg1, _Arg2>(f);
}

/*! Makes callable from function which returns nothing and receives 4 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3)> f)
{
    return new VoidLambda4<_Context, _Arg0, _Arg1, _Arg2, _Arg3>(f);
}

/*! Makes callable from function which returns nothing and receives 5 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4)> f)
{
    return new VoidLambda5<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
}

/*! Makes callable from function which returns nothing and receives 6 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5)> f)
{
    return new VoidLambda6<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
}

/*! Makes callable from function which returns nothing and receives 7 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6)> f)
{
    return new VoidLambda7<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
}

/*! Makes callable from function which returns nothing and receives 8 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6,
    typename _Arg7
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7)> f)
{
    return new VoidLambda8<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
}

/*! Makes callable from function which returns nothing and receives 9 arguments
    \param[in] f function
    \return callable version
 */
template<
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8)> f)
{
    return new VoidLambda9<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
}

/*! Makes callable from function which returns nothing and receives 10 arguments
    \param[in] f function
    \return callable version
 */
template<
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9)> f)
{
    return new VoidLambda10<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
}

/*! Makes callable from function which returns nothing and receives 11 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10)> f)
{
    return new VoidLambda11<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
}

/*! Makes callable from function which returns nothing and receives 12 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1,
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11)> f)
{
    return new VoidLambda12<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
}

/*! Makes callable from function which returns nothing and receives 13 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1,
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12)> f)
{
    return new VoidLambda13<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
}

/*! Makes callable from function which returns nothing and receives 14 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1,
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13)> f)
{
    return new VoidLambda14<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
}

/*! Makes callable from function which returns nothing and receives 15 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1,
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14)> f)
{
    return new VoidLambda15<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
}

/*! Makes callable from function which returns nothing and receives 16 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1,
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15)> f)
{
    return new VoidLambda16<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


/*! Makes callable from function which returns value and receives 0 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType()> f)
{
    return new RetLambda0<_Context, _ReturnType>(f);
}

/*! Makes callable from function which returns value and receives 1 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _Arg0
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0)> f)
{
    return new RetLambda1<_Context, _ReturnType, _Arg0>(f);
}

/*! Makes callable from function which returns value and receives 2 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1)> f)
{
    return new RetLambda2<_Context, _ReturnType, _Arg0, _Arg1>(f);
}

/*! Makes callable from function which returns value and receives 3 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2)> f)
{
    return new RetLambda3<_Context, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
}

/*! Makes callable from function which returns value and receives 4 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3)> f)
{
    return new RetLambda4<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
}

/*! Makes callable from function which returns value and receives 5 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4)> f)
{
    return new RetLambda5<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
}

/*! Makes callable from function which returns value and receives 6 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5)> f)
{
    return new RetLambda6<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
}

/*! Makes callable from function which returns value and receives 7 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6)> f)
{
    return new RetLambda7<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
}

/*! Makes callable from function which returns value and receives 8 arguments
    \param[in] f function
    \return callable version
 */
template<
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7)> f)
{
    return new RetLambda8<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
}

/*! Makes callable from function which returns value and receives 9 arguments
    \param[in] f function
    \return callable version
 */
template<
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8)> f)
{
    return new RetLambda9<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
}

/*! Makes callable from function which returns value and receives 10 arguments
    \param[in] f function
    \return callable version
 */
template<
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9)> f)
{
    return new RetLambda10<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
}

/*! Makes callable from function which returns value and receives 11 arguments
    \param[in] f function
    \return callable version
 */
template<
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10)> f)
{
    return new RetLambda11<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
}

/*! Makes callable from function which returns value and receives 12 arguments
    \param[in] f function
    \return callable version
 */
template<
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11)> f)
{
    return new RetLambda12<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
}

/*! Makes callable from function which returns value and receives 13 arguments
    \param[in] f function
    \return callable version
 */
template<
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12)> f)
{
    return new RetLambda13<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
}

/*! Makes callable from function which returns value and receives 14 arguments
    \param[in] f function
    \return callable version
 */
template<
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13)> f)
{
    return new RetLambda14<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
}

/*! Makes callable from function which returns value and receives 15 arguments
    \param[in] f function
    \return callable version
 */
template<
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14)> f)
{
    return new RetLambda15<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
}

/*! Makes callable from function which returns value and receives 16 arguments
    \param[in] f function
    \return callable version
 */
template<
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15)> f)
{
    return new RetLambda16<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


};

}

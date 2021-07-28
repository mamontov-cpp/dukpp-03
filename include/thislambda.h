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
    typename _Context,
    typename _ClassName
>
class ThisVoidLambda0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda0(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda0<_Context,_ClassName>(m_callee);
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
        m_callee((_ac._()));        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda0() override
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
    typename _ClassName,
    typename _Arg0
>
class ThisVoidLambda1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda1(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda1<_Context,_ClassName, _Arg0>(m_callee);
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
        m_callee((_ac._()),_a0._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda1() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1
>
class ThisVoidLambda2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda2(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda2<_Context,_ClassName, _Arg0,_Arg1>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda2() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2
>
class ThisVoidLambda3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda3(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda3<_Context,_ClassName, _Arg0,_Arg1,_Arg2>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda3() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3
>
class ThisVoidLambda4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda4(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda4<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda4() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4
>
class ThisVoidLambda5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda5(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda5<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda5() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5
>
class ThisVoidLambda6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda6(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda6<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda6() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6
>
class ThisVoidLambda7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda7(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda7<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda7() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7
>
class ThisVoidLambda8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda8(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda8<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda8() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8
>
class ThisVoidLambda9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda9(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda9<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda9() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9
>
class ThisVoidLambda10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda10(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda10<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda10() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10
>
class ThisVoidLambda11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda11(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda11<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda11() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11
>
class ThisVoidLambda12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda12(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda12<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda12() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12
>
class ThisVoidLambda13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda13(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda13<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda13() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12,    typename _Arg13
>
class ThisVoidLambda14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda14(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda14<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda14() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12,    typename _Arg13,    typename _Arg14
>
class ThisVoidLambda15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda15(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda15<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda15() override
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
    typename _ClassName,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12,    typename _Arg13,    typename _Arg14,    typename _Arg15
>
class ThisVoidLambda16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<void(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisVoidLambda16(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ThisVoidLambda16<_Context,_ClassName, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15>(m_callee);
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
        m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~ThisVoidLambda16() override
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
    typename _ReturnType,
    typename _ClassName
>
class ThisRetLambda0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda0(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda0<_Context, _ReturnType,_ClassName>(m_callee);
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
        _ReturnType t = m_callee((_ac._()));         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda0() override
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
    typename _ClassName,
    typename _Arg0
>
class ThisRetLambda1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda1(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda1<_Context, _ReturnType,_ClassName,_Arg0>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda1() override
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
class ThisRetLambda2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda2(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda2<_Context, _ReturnType,_ClassName,_Arg0,_Arg1>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda2() override
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class ThisRetLambda3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda3(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda3<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda3() override
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class ThisRetLambda4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda4(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda4<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda4() override
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
class ThisRetLambda5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda5(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda5<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda5() override
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
class ThisRetLambda6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda6(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda6<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda6() override
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
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
class ThisRetLambda7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda7(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda7<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda7() override
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
class ThisRetLambda8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda8(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda8<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda8() override
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
class ThisRetLambda9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda9(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda9<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda9() override
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
class ThisRetLambda10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda10(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda10<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda10() override
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
class ThisRetLambda11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda11(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda11<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda11() override
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
class ThisRetLambda12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda12(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda12<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda12() override
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
class ThisRetLambda13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda13(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda13<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda13() override
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
class ThisRetLambda14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda14(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda14<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda14() override
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
class ThisRetLambda15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda15(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda15<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda15() override
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
class ThisRetLambda16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef std::function<_ReturnType(_ClassName*,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15)> Function;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ThisRetLambda16(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override  
    {
        return new dukpp03::ThisRetLambda16<_Context, _ReturnType,_ClassName,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15>(m_callee);
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
        _ReturnType t = m_callee((_ac._()),_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._(), _a7._(), _a8._(), _a9._(), _a10._(), _a11._(), _a12._(), _a13._(), _a14._(), _a15._());         
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ThisRetLambda16() override
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
struct bind_lambda 
{
/*! Makes callable from function which returns nothing and receives 0 arguments
    \param[in] f function
    \return callable version
 */
template<
typename _ClassName
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*)> f)
{
    return new ThisVoidLambda0<_Context,_ClassName>(f);
}

/*! Makes callable from function which returns nothing and receives 1 arguments
    \param[in] f function
    \return callable version
 */
template<
typename _ClassName,
    typename _Arg0
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0)> f)
{
    return new ThisVoidLambda1<_Context,_ClassName, _Arg0>(f);
}

/*! Makes callable from function which returns nothing and receives 2 arguments
    \param[in] f function
    \return callable version
 */
template<
typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1)> f)
{
    return new ThisVoidLambda2<_Context,_ClassName, _Arg0, _Arg1>(f);
}

/*! Makes callable from function which returns nothing and receives 3 arguments
    \param[in] f function
    \return callable version
 */
template<
typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2)> f)
{
    return new ThisVoidLambda3<_Context,_ClassName, _Arg0, _Arg1, _Arg2>(f);
}

/*! Makes callable from function which returns nothing and receives 4 arguments
    \param[in] f function
    \return callable version
 */
template<
typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3)> f)
{
    return new ThisVoidLambda4<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(f);
}

/*! Makes callable from function which returns nothing and receives 5 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4)> f)
{
    return new ThisVoidLambda5<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
}

/*! Makes callable from function which returns nothing and receives 6 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5)> f)
{
    return new ThisVoidLambda6<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
}

/*! Makes callable from function which returns nothing and receives 7 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6)> f)
{
    return new ThisVoidLambda7<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
}

/*! Makes callable from function which returns nothing and receives 8 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7)> f)
{
    return new ThisVoidLambda8<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
}

/*! Makes callable from function which returns nothing and receives 9 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8)> f)
{
    return new ThisVoidLambda9<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
}

/*! Makes callable from function which returns nothing and receives 10 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9)> f)
{
    return new ThisVoidLambda10<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
}

/*! Makes callable from function which returns nothing and receives 11 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10)> f)
{
    return new ThisVoidLambda11<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
}

/*! Makes callable from function which returns nothing and receives 12 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11)> f)
{
    return new ThisVoidLambda12<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
}

/*! Makes callable from function which returns nothing and receives 13 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12)> f)
{
    return new ThisVoidLambda13<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
}

/*! Makes callable from function which returns nothing and receives 14 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13)> f)
{
    return new ThisVoidLambda14<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
}

/*! Makes callable from function which returns nothing and receives 15 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14)> f)
{
    return new ThisVoidLambda15<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
}

/*! Makes callable from function which returns nothing and receives 16 arguments
    \param[in] f function
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
static inline dukpp03::Callable<_Context>* from(std::function<void(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15)> f)
{
    return new ThisVoidLambda16<_Context,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


/*! Makes callable from function which returns value and receives 0 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _ClassName
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*)> f)
{
    return new ThisRetLambda0<_Context, _ReturnType,_ClassName>(f);
}

/*! Makes callable from function which returns value and receives 1 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _ClassName,
    typename _Arg0
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0)> f)
{
    return new ThisRetLambda1<_Context, _ReturnType,_ClassName, _Arg0>(f);
}

/*! Makes callable from function which returns value and receives 2 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1)> f)
{
    return new ThisRetLambda2<_Context, _ReturnType,_ClassName, _Arg0, _Arg1>(f);
}

/*! Makes callable from function which returns value and receives 3 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2)> f)
{
    return new ThisRetLambda3<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2>(f);
}

/*! Makes callable from function which returns value and receives 4 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3)> f)
{
    return new ThisRetLambda4<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3>(f);
}

/*! Makes callable from function which returns value and receives 5 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4)> f)
{
    return new ThisRetLambda5<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
}

/*! Makes callable from function which returns value and receives 6 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5)> f)
{
    return new ThisRetLambda6<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
}

/*! Makes callable from function which returns value and receives 7 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _ClassName,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3,
    typename _Arg4,
    typename _Arg5,
    typename _Arg6
>
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6)> f)
{
    return new ThisRetLambda7<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
}

/*! Makes callable from function which returns value and receives 8 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7)> f)
{
    return new ThisRetLambda8<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
}

/*! Makes callable from function which returns value and receives 9 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8)> f)
{
    return new ThisRetLambda9<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
}

/*! Makes callable from function which returns value and receives 10 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9)> f)
{
    return new ThisRetLambda10<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
}

/*! Makes callable from function which returns value and receives 11 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10)> f)
{
    return new ThisRetLambda11<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
}

/*! Makes callable from function which returns value and receives 12 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11)> f)
{
    return new ThisRetLambda12<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
}

/*! Makes callable from function which returns value and receives 13 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12)> f)
{
    return new ThisRetLambda13<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
}

/*! Makes callable from function which returns value and receives 14 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13)> f)
{
    return new ThisRetLambda14<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
}

/*! Makes callable from function which returns value and receives 15 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14)> f)
{
    return new ThisRetLambda15<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
}

/*! Makes callable from function which returns value and receives 16 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
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
static inline dukpp03::Callable<_Context>* from(std::function<_ReturnType(_ClassName*,_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15)> f)
{
    return new ThisRetLambda16<_Context, _ReturnType,_ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


};

}

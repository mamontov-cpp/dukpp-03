/*! \file function.h
     
    Defines a simple defines for creating bindings for any kind of function
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

/*! Defines a wrapper for function, which returns nothing and receives 0 arguments
 */
template<
    typename _Context
>
class VoidFunction0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)();
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction0(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction0<_Context>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 0;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {        
        m_callee();        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidFunction0()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 1 arguments
 */
template<
    typename _Context,
    typename _Arg0
>
class VoidFunction1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction1(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction1<_Context, _Arg0>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 1;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        m_callee(_a0._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidFunction1()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 2 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1
>
class VoidFunction2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction2(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction2<_Context, _Arg0,_Arg1>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 2;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        m_callee(_a0._(), _a1._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidFunction2()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 3 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2
>
class VoidFunction3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction3(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction3<_Context, _Arg0,_Arg1,_Arg2>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 3;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        m_callee(_a0._(), _a1._(), _a2._());        
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~VoidFunction3()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 4 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3
>
class VoidFunction4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction4(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction4<_Context, _Arg0,_Arg1,_Arg2,_Arg3>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 4;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction4()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 5 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4
>
class VoidFunction5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction5(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction5<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 5;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction5()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 6 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5
>
class VoidFunction6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction6(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction6<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 6;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction6()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 7 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6
>
class VoidFunction7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction7(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction7<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 7;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction7()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 8 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7
>
class VoidFunction8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction8(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction8<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 8;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction8()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 9 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8
>
class VoidFunction9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction9(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction9<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 9;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction9()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 10 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9
>
class VoidFunction10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction10(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction10<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 10;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction10()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 11 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10
>
class VoidFunction11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction11(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction11<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 11;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction11()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 12 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11
>
class VoidFunction12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction12(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction12<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 12;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction12()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 13 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12
>
class VoidFunction13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction13(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction13<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 13;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction13()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 14 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12,    typename _Arg13
>
class VoidFunction14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction14(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction14<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 14;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction14()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 15 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12,    typename _Arg13,    typename _Arg14
>
class VoidFunction15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction15(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction15<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 15;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction15()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns nothing and receives 16 arguments
 */
template<
    typename _Context,
    typename _Arg0,    typename _Arg1,    typename _Arg2,    typename _Arg3,    typename _Arg4,    typename _Arg5,    typename _Arg6,    typename _Arg7,    typename _Arg8,    typename _Arg9,    typename _Arg10,    typename _Arg11,    typename _Arg12,    typename _Arg13,    typename _Arg14,    typename _Arg15
>
class VoidFunction16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef void (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    VoidFunction16(Function f): m_callee(f)   
    {
    
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual  dukpp03::Callable<_Context>* clone()
    {
        return new dukpp03::VoidFunction16<_Context, _Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15>(m_callee);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  
    {
        return 16;
    }
    /*! Performs call of object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
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
    virtual ~VoidFunction16()
    {

    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 0 arguments
 */
template<
    typename _Context,
    typename _ReturnType
>
class RetFunction0 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)();
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction0(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction0<_Context, _ReturnType>(m_callee);
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
    virtual int _call(_Context* c)
    {        

        _ReturnType t = m_callee();
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction0()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 1 arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _Arg0
>
class RetFunction1 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction1(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction1<_Context, _ReturnType,_Arg0>(m_callee);
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
    virtual int _call(_Context* c)
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);

        _ReturnType t = m_callee(_a0._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction1()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 2 arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1
>
class RetFunction2 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction2(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction2<_Context, _ReturnType,_Arg0,_Arg1>(m_callee);
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
    virtual int _call(_Context* c)
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);

        _ReturnType t = m_callee(_a0._(), _a1._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction2()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 3 arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2
>
class RetFunction3 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction3(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction3<_Context, _ReturnType,_Arg0,_Arg1,_Arg2>(m_callee);
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
    virtual int _call(_Context* c)
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction3()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 4 arguments
 */
template<
    typename _Context,
    typename _ReturnType,
    typename _Arg0,
    typename _Arg1,
    typename _Arg2,
    typename _Arg3
>
class RetFunction4 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction4(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction4<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3>(m_callee);
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
    virtual int _call(_Context* c)
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction4()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 5 arguments
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
class RetFunction5 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction5(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction5<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4>(m_callee);
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
    virtual int _call(_Context* c)
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction5()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 6 arguments
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
class RetFunction6 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction6(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction6<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5>(m_callee);
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
    virtual int _call(_Context* c)
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction6()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 7 arguments
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
class RetFunction7 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction7(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction7<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6>(m_callee);
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
    virtual int _call(_Context* c)
    {        
        DUKPP03_MAYBE_FROM_STACK(_Arg0, 0, 0, 1);
        DUKPP03_MAYBE_FROM_STACK(_Arg1, 1, 1, 2);
        DUKPP03_MAYBE_FROM_STACK(_Arg2, 2, 2, 3);
        DUKPP03_MAYBE_FROM_STACK(_Arg3, 3, 3, 4);
        DUKPP03_MAYBE_FROM_STACK(_Arg4, 4, 4, 5);
        DUKPP03_MAYBE_FROM_STACK(_Arg5, 5, 5, 6);
        DUKPP03_MAYBE_FROM_STACK(_Arg6, 6, 6, 7);

        _ReturnType t = m_callee(_a0._(), _a1._(), _a2._(), _a3._(), _a4._(), _a5._(), _a6._());
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction7()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 8 arguments
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
class RetFunction8 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction8(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction8<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7>(m_callee);
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
    virtual int _call(_Context* c)
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
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction8()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 9 arguments
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
class RetFunction9 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction9(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction9<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8>(m_callee);
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
    virtual int _call(_Context* c)
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
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction9()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 10 arguments
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
class RetFunction10 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction10(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction10<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9>(m_callee);
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
    virtual int _call(_Context* c)
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
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction10()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 11 arguments
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
class RetFunction11 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction11(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction11<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10>(m_callee);
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
    virtual int _call(_Context* c)
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
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction11()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 12 arguments
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
class RetFunction12 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction12(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction12<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11>(m_callee);
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
    virtual int _call(_Context* c)
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
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction12()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 13 arguments
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
class RetFunction13 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction13(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction13<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12>(m_callee);
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
    virtual int _call(_Context* c)
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
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction13()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 14 arguments
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
class RetFunction14 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction14(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction14<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13>(m_callee);
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
    virtual int _call(_Context* c)
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
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction14()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 15 arguments
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
class RetFunction15 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction15(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction15<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14>(m_callee);
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
    virtual int _call(_Context* c)
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
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction15()
    {
    }
protected:
    /*! A function, which is being wrapped
     */
    Function m_callee;
};

/*! Defines a wrapper for function, which returns some value and receives 16 arguments
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
class RetFunction16 : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    RetFunction16(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::RetFunction16<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15>(m_callee);
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
    virtual int _call(_Context* c)
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
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~RetFunction16()
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
struct make_fun 
{
/*! Makes callable from function which returns nothing and receives 0 arguments
    \param[in] f function
    \return callable version
 */
static inline dukpp03::Callable<_Context>* from(void (*f)())
{
    return new VoidFunction0<_Context>(f);
}

/*! Makes callable from function which returns nothing and receives 1 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0
>
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0))
{
    return new VoidFunction1<_Context, _Arg0>(f);
}

/*! Makes callable from function which returns nothing and receives 2 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _Arg0,
    typename _Arg1
>
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1))
{
    return new VoidFunction2<_Context, _Arg0, _Arg1>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2))
{
    return new VoidFunction3<_Context, _Arg0, _Arg1, _Arg2>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3))
{
    return new VoidFunction4<_Context, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4))
{
    return new VoidFunction5<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5))
{
    return new VoidFunction6<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6))
{
    return new VoidFunction7<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7))
{
    return new VoidFunction8<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8))
{
    return new VoidFunction9<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9))
{
    return new VoidFunction10<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10))
{
    return new VoidFunction11<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11))
{
    return new VoidFunction12<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12))
{
    return new VoidFunction13<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13))
{
    return new VoidFunction14<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14))
{
    return new VoidFunction15<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
static inline dukpp03::Callable<_Context>* from(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15))
{
    return new VoidFunction16<_Context, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


/*! Makes callable from function which returns value and receives 0 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType
>
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)())
{
    return new RetFunction0<_Context, _ReturnType>(f);
}

/*! Makes callable from function which returns value and receives 1 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType,
    typename _Arg0
>
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0))
{
    return new RetFunction1<_Context, _ReturnType, _Arg0>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1))
{
    return new RetFunction2<_Context, _ReturnType, _Arg0, _Arg1>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2))
{
    return new RetFunction3<_Context, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3))
{
    return new RetFunction4<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4))
{
    return new RetFunction5<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5))
{
    return new RetFunction6<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6))
{
    return new RetFunction7<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7))
{
    return new RetFunction8<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8))
{
    return new RetFunction9<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9))
{
    return new RetFunction10<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10))
{
    return new RetFunction11<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11))
{
    return new RetFunction12<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12))
{
    return new RetFunction13<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13))
{
    return new RetFunction14<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14))
{
    return new RetFunction15<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15))
{
    return new RetFunction16<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


};

}

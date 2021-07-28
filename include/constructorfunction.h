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


/*! Defines a wrapper for function, which returns some value and receives 0 arguments
 */
template<
    typename _Context,
    typename _ReturnType
>
class ConstructorFunction0 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)();
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction0(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction0<_Context, _ReturnType>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction0() override
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
class ConstructorFunction1 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction1(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction1<_Context, _ReturnType,_Arg0>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction1() override
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
class ConstructorFunction2 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction2(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction2<_Context, _ReturnType,_Arg0,_Arg1>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction2() override
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
class ConstructorFunction3 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction3(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction3<_Context, _ReturnType,_Arg0,_Arg1,_Arg2>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction3() override
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
class ConstructorFunction4 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction4(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction4<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction4() override
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
class ConstructorFunction5 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction5(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction5<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction5() override
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
class ConstructorFunction6 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction6(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction6<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction6() override
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
class ConstructorFunction7 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction7(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction7<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction7() override
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
class ConstructorFunction8 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction8(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction8<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction8() override
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
class ConstructorFunction9 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction9(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction9<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction9() override
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
class ConstructorFunction10 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction10(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction10<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction10() override
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
class ConstructorFunction11 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction11(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction11<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction11() override
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
class ConstructorFunction12 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction12(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction12<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction12() override
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
class ConstructorFunction13 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction13(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction13<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction13() override
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
class ConstructorFunction14 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction14(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction14<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction14() override
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
class ConstructorFunction15 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction15(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction15<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction15() override
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
class ConstructorFunction16 : public dukpp03::Callable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType (*Function)(_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15);
    /*! Constructs new function wrapper
        \param[in] f function
     */
    ConstructorFunction16(Function f): m_callee(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::ConstructorFunction16<_Context, _ReturnType,_Arg0,_Arg1,_Arg2,_Arg3,_Arg4,_Arg5,_Arg6,_Arg7,_Arg8,_Arg9,_Arg10,_Arg11,_Arg12,_Arg13,_Arg14,_Arg15>(m_callee);
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
        duk_push_current_function(c->context());
        duk_set_prototype(c->context(), -2);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~ConstructorFunction16() override
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
struct make_constructor_fun 
{

/*! Makes callable from function which returns value and receives 0 arguments
    \param[in] f function
    \return callable version
 */
template<
    typename _ReturnType
>
static inline dukpp03::Callable<_Context>* from(_ReturnType (*f)())
{
    return new ConstructorFunction0<_Context, _ReturnType>(f);
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
    return new ConstructorFunction1<_Context, _ReturnType, _Arg0>(f);
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
    return new ConstructorFunction2<_Context, _ReturnType, _Arg0, _Arg1>(f);
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
    return new ConstructorFunction3<_Context, _ReturnType, _Arg0, _Arg1, _Arg2>(f);
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
    return new ConstructorFunction4<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3>(f);
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
    return new ConstructorFunction5<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>(f);
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
    return new ConstructorFunction6<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>(f);
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
    return new ConstructorFunction7<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>(f);
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
    return new ConstructorFunction8<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>(f);
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
    return new ConstructorFunction9<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>(f);
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
    return new ConstructorFunction10<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>(f);
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
    return new ConstructorFunction11<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>(f);
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
    return new ConstructorFunction12<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>(f);
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
    return new ConstructorFunction13<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>(f);
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
    return new ConstructorFunction14<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>(f);
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
    return new ConstructorFunction15<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>(f);
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
    return new ConstructorFunction16<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


};

}

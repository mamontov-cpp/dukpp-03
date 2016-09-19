/*! \file duktapefunction.h
     
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
class VoidFunction0 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 0)
        {
            c->throwInvalidArgumentCountError(0, c->getTop());
            return 0;
        }
        
        
        try
        {
            m_callee();
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction1 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 1)
        {
            c->throwInvalidArgumentCountError(1, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction2 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 2)
        {
            c->throwInvalidArgumentCountError(2, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction3 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 3)
        {
            c->throwInvalidArgumentCountError(3, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction4 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 4)
        {
            c->throwInvalidArgumentCountError(4, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction5 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 5)
        {
            c->throwInvalidArgumentCountError(5, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction6 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 6)
        {
            c->throwInvalidArgumentCountError(6, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction7 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 7)
        {
            c->throwInvalidArgumentCountError(7, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction8 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 8)
        {
            c->throwInvalidArgumentCountError(8, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction9 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 9)
        {
            c->throwInvalidArgumentCountError(9, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction10 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 10)
        {
            c->throwInvalidArgumentCountError(10, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction11 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 11)
        {
            c->throwInvalidArgumentCountError(11, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction12 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 12)
        {
            c->throwInvalidArgumentCountError(12, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
      
        if (_a11.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg11>::Type >::type();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction13 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 13)
        {
            c->throwInvalidArgumentCountError(13, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
      
        if (_a11.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg11>::Type >::type();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
      
        if (_a12.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg12>::Type >::type();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction14 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 14)
        {
            c->throwInvalidArgumentCountError(14, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 13);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
      
        if (_a11.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg11>::Type >::type();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
      
        if (_a12.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg12>::Type >::type();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
      
        if (_a13.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg13>::Type >::type();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction15 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 15)
        {
            c->throwInvalidArgumentCountError(15, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 14);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
      
        if (_a11.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg11>::Type >::type();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
      
        if (_a12.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg12>::Type >::type();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
      
        if (_a13.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg13>::Type >::type();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
      
        if (_a14.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg14>::Type >::type();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class VoidFunction16 : public dukpp03::Callable
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
    virtual  dukpp03::Callable* clone()
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 16)
        {
            c->throwInvalidArgumentCountError(16, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 14);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg15>::Type > _a15 = dukpp03::GetValue< typename dukpp03::Decay<_Arg15>::Type, _Context >::perform(c, 15);
      
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
      
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
      
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
      
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
      
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
      
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
      
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
      
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
      
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
      
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
      
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
      
        if (_a11.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg11>::Type >::type();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
      
        if (_a12.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg12>::Type >::type();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
      
        if (_a13.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg13>::Type >::type();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
      
        if (_a14.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg14>::Type >::type();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
      
        if (_a15.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg15>::Type >::type();
            c->throwInvalidTypeError(16, name);
            return 0;
        }
        
        try
        {
            m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue(), _a15.mutableValue());
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
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
class RetFunction0 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 0)
        {
            c->throwInvalidArgumentCountError(0, c->getTop());
            return 0;
        }
        
        try
        {
            _ReturnType t = m_callee();
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction1 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 1)
        {
            c->throwInvalidArgumentCountError(1, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction2 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 2)
        {
            c->throwInvalidArgumentCountError(2, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction3 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 3)
        {
            c->throwInvalidArgumentCountError(3, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction4 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 4)
        {
            c->throwInvalidArgumentCountError(4, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction5 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 5)
        {
            c->throwInvalidArgumentCountError(5, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction6 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 6)
        {
            c->throwInvalidArgumentCountError(6, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction7 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 7)
        {
            c->throwInvalidArgumentCountError(7, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction8 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 8)
        {
            c->throwInvalidArgumentCountError(8, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction9 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 9)
        {
            c->throwInvalidArgumentCountError(9, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction10 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 10)
        {
            c->throwInvalidArgumentCountError(10, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction11 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 11)
        {
            c->throwInvalidArgumentCountError(11, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction12 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 12)
        {
            c->throwInvalidArgumentCountError(12, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
        if (_a11.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg11>::Type >::type();
            c->throwInvalidTypeError(12, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction13 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 13)
        {
            c->throwInvalidArgumentCountError(13, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
        if (_a11.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg11>::Type >::type();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
        if (_a12.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg12>::Type >::type();
            c->throwInvalidTypeError(13, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction14 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 14)
        {
            c->throwInvalidArgumentCountError(14, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 13);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
        if (_a11.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg11>::Type >::type();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
        if (_a12.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg12>::Type >::type();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
        if (_a13.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg13>::Type >::type();
            c->throwInvalidTypeError(14, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction15 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 15)
        {
            c->throwInvalidArgumentCountError(15, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 14);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
        if (_a11.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg11>::Type >::type();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
        if (_a12.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg12>::Type >::type();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
        if (_a13.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg13>::Type >::type();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
        if (_a14.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg14>::Type >::type();
            c->throwInvalidTypeError(15, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
class RetFunction16 : public dukpp03::Callable
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
    virtual dukpp03::Callable* clone()  
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
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != 16)
        {
            c->throwInvalidArgumentCountError(16, c->getTop());
            return 0;
        }
        
        dukpp03::Maybe< typename dukpp03::Decay<_Arg0>::Type > _a0 = dukpp03::GetValue< typename dukpp03::Decay<_Arg0>::Type, _Context >::perform(c, 0);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg1>::Type > _a1 = dukpp03::GetValue< typename dukpp03::Decay<_Arg1>::Type, _Context >::perform(c, 1);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg2>::Type > _a2 = dukpp03::GetValue< typename dukpp03::Decay<_Arg2>::Type, _Context >::perform(c, 2);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg3>::Type > _a3 = dukpp03::GetValue< typename dukpp03::Decay<_Arg3>::Type, _Context >::perform(c, 3);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg4>::Type > _a4 = dukpp03::GetValue< typename dukpp03::Decay<_Arg4>::Type, _Context >::perform(c, 4);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg5>::Type > _a5 = dukpp03::GetValue< typename dukpp03::Decay<_Arg5>::Type, _Context >::perform(c, 5);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg6>::Type > _a6 = dukpp03::GetValue< typename dukpp03::Decay<_Arg6>::Type, _Context >::perform(c, 6);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg7>::Type > _a7 = dukpp03::GetValue< typename dukpp03::Decay<_Arg7>::Type, _Context >::perform(c, 7);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg8>::Type > _a8 = dukpp03::GetValue< typename dukpp03::Decay<_Arg8>::Type, _Context >::perform(c, 8);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg9>::Type > _a9 = dukpp03::GetValue< typename dukpp03::Decay<_Arg9>::Type, _Context >::perform(c, 9);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg10>::Type > _a10 = dukpp03::GetValue< typename dukpp03::Decay<_Arg10>::Type, _Context >::perform(c, 10);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg11>::Type > _a11 = dukpp03::GetValue< typename dukpp03::Decay<_Arg11>::Type, _Context >::perform(c, 11);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg12>::Type > _a12 = dukpp03::GetValue< typename dukpp03::Decay<_Arg12>::Type, _Context >::perform(c, 12);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg13>::Type > _a13 = dukpp03::GetValue< typename dukpp03::Decay<_Arg13>::Type, _Context >::perform(c, 13);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg14>::Type > _a14 = dukpp03::GetValue< typename dukpp03::Decay<_Arg14>::Type, _Context >::perform(c, 14);
        dukpp03::Maybe< typename dukpp03::Decay<_Arg15>::Type > _a15 = dukpp03::GetValue< typename dukpp03::Decay<_Arg15>::Type, _Context >::perform(c, 15);
        
        if (_a0.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg0>::Type >::type();
            c->throwInvalidTypeError(1, name);
            return 0;
        }
        if (_a1.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg1>::Type >::type();
            c->throwInvalidTypeError(2, name);
            return 0;
        }
        if (_a2.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg2>::Type >::type();
            c->throwInvalidTypeError(3, name);
            return 0;
        }
        if (_a3.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg3>::Type >::type();
            c->throwInvalidTypeError(4, name);
            return 0;
        }
        if (_a4.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg4>::Type >::type();
            c->throwInvalidTypeError(5, name);
            return 0;
        }
        if (_a5.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg5>::Type >::type();
            c->throwInvalidTypeError(6, name);
            return 0;
        }
        if (_a6.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg6>::Type >::type();
            c->throwInvalidTypeError(7, name);
            return 0;
        }
        if (_a7.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg7>::Type >::type();
            c->throwInvalidTypeError(8, name);
            return 0;
        }
        if (_a8.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg8>::Type >::type();
            c->throwInvalidTypeError(9, name);
            return 0;
        }
        if (_a9.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg9>::Type >::type();
            c->throwInvalidTypeError(10, name);
            return 0;
        }
        if (_a10.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg10>::Type >::type();
            c->throwInvalidTypeError(11, name);
            return 0;
        }
        if (_a11.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg11>::Type >::type();
            c->throwInvalidTypeError(12, name);
            return 0;
        }
        if (_a12.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg12>::Type >::type();
            c->throwInvalidTypeError(13, name);
            return 0;
        }
        if (_a13.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg13>::Type >::type();
            c->throwInvalidTypeError(14, name);
            return 0;
        }
        if (_a14.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg14>::Type >::type();
            c->throwInvalidTypeError(15, name);
            return 0;
        }
        if (_a15.exists() == false) 
        {
            std::string name = typename _Context::VariantUtils::template TypeName< typename dukpp03::Decay<_Arg15>::Type >::type();
            c->throwInvalidTypeError(16, name);
            return 0;
        }

        try
        {
            _ReturnType t = m_callee(_a0.mutableValue(), _a1.mutableValue(), _a2.mutableValue(), _a3.mutableValue(), _a4.mutableValue(), _a5.mutableValue(), _a6.mutableValue(), _a7.mutableValue(), _a8.mutableValue(), _a9.mutableValue(), _a10.mutableValue(), _a11.mutableValue(), _a12.mutableValue(), _a13.mutableValue(), _a14.mutableValue(), _a15.mutableValue());
            dukpp03::PushValue<_ReturnType, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwError("Caught exception while calling function");
            return 0;
        }
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
struct BindFunctionTo 
{
/*! Makes callable from function which returns nothing and receives 0 arguments
    \param[in] f function
    \return callable version
 */
static inline dukpp03::Callable* _using(void (*f)())
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14))
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
static inline dukpp03::Callable* _using(void (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)())
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14))
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
static inline dukpp03::Callable* _using(_ReturnType (*f)(_Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15))
{
    return new RetFunction16<_Context, _ReturnType, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>(f);
}


};

}

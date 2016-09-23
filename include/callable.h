/*! \file callable.h
    

    Contains definition of function wrapper, callable from Duktape, which will be used as substitution object, used
    to produce template bindings.
 */
#pragma once
#include "abstractcallable.h"
#include "decay.h"
#include "maybe.h"
#include <utility>
#include <stdexcept>
    
namespace dukpp03
{


template<
    typename _Value,
    typename _Context
>
class GetValue;

/*! A context-dependent callable
 */
template<
   typename _Context
>
class Callable: public dukpp03::AbstractCallable
{
public:
    /*! Must return copy of callable object
        \return copy of callable object
     */
    virtual Callable<_Context>* clone() = 0;
    /*! Performs check, whether callable can be called, without actually calling an object in context
        \param[in] c context
        \return pair
     */
    virtual std::pair<int, bool> canBeCalled(_Context* c)
    {
        return std::make_pair(0, false);
    }
    /* Returns whther it could be called as constructor
       \return true if can
     */
    virtual bool canBeCalledAsConstructor()
    {
        return true;
    }
    /* Returns whther it could be called as function
       \return true if can
     */
    virtual bool canBeCalledAsFunction()
    {
        return true;
    }
    /*! Performs call on object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(_Context* c)
    {
        int required_args = this->requiredArguments();
        if (c->getTop() != required_args)
        {
            c->throwInvalidArgumentCountError(required_args, c->getTop());
            return 0;
        }
        
        if (duk_is_constructor_call(c->context()))
        {
            if (this->canBeCalledAsConstructor() == false)
            {
                c->throwFunctionCallShouldNotBeCalledAsConstructor();
                return 0;
            }
        }
        else
        {
            if (this->canBeCalledAsFunction() == false)
            {
                c->throwFunctionCallShouldBeACalledOnlyAsConstructor();
                return 0;               
            }
        }
        
        try
        {
            return this->_call(c);
        }
        catch(dukpp03::ArgumentException e)
        {
            return 0;
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
        return 0;
    }
    /*! Performs actual function call
     */
    virtual int _call(_Context* c)
    {
        return 0;
    }
    
    /*! Checks specified argument by type for callable
     */
    template<
        typename _Arg
    >
    struct CheckArgument
    {
        /*! Checks argument on stack, filling a if needed
            \param[in] c conext
            \param[in] a an argument
            \param[in] stackValue a value index on stack
            \param[in] argnumber number of argument
         */ 
        static void onStack(_Context* c, dukpp03::Maybe< typename dukpp03::Decay<_Arg>::Type >& a, int stackValue, int argnumber)
        {
            a = dukpp03::GetValue< typename dukpp03::Decay<_Arg>::Type, _Context >::perform(c, stackValue);
            if (a.exists() == false)
            {
                std::string name = _Context::template typeName< _Arg >();
                c->throwInvalidTypeError(argnumber, name);
                throw dukpp03::ArgumentException();
            }
        }
    
    };
};

/*! Defines a callable, that can be called only as function
 */
template<
    typename _Context
>
class FunctionCallable: public Callable<_Context>
{
public: 
    /* Returns whther it could be called as constructor
       \return true if can
     */
    virtual bool canBeCalledAsConstructor()
    {
        return false;
    }
};

/*! Defines a callable, that can be called only as constructor
 */
template<
    typename _Context
>
class ConstructorCallable: public Callable<_Context>
{
public: 
    /* Returns whther it could be called as constructor
       \return true if can
     */
    virtual bool canBeCalledAsFunction()
    {
        return false;
    }
};

}

#define DUKPP03_TYPE(TYPE) TYPE
/*! A macro for getting maybe value from stack
 */
#define DUKPP03_MAYBE_FROM_STACK(TYPE, NAME, STACKV, NUMBER)  dukpp03::Maybe< typename dukpp03::Decay< DUKPP03_TYPE(TYPE) >::Type > _a##NAME; Callable<_Context>::template CheckArgument< DUKPP03_TYPE(TYPE) >::onStack(c, _a##NAME, STACKV, NUMBER)
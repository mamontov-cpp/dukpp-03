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

        /*! Checks argument, passed as this, filling a if needed
            \param[in] c context
            \param[out] a an argument
         */ 
        static void passedAsThis(_Context* c, dukpp03::Maybe< typename dukpp03::Decay<_Arg>::Type >& a)
        {
            dukpp03::IsNotPODReference<_Arg>::typeMustBe();
            duk_push_this(c->context());
            a = dukpp03::GetValue< typename dukpp03::Decay<_Arg>::Type, _Context >::perform(c, -1);
            duk_pop(c->context());
            if (a.exists() == false)
            {
                std::string name = _Context::template typeName< _Arg >();
                c->throwInvalidTypeForThisError(name);
                throw dukpp03::ArgumentException();
            }
        }

        /*! Checks argument on stack, filling a if needed
            \param[in] c context
            \param[out] a an argument
            \param[in] stackValue a value index on stack
            \param[in] argnumber number of argument
         */ 
        static void onStack(_Context* c, dukpp03::Maybe< typename dukpp03::Decay<_Arg>::Type >& a, int stackValue, int argnumber)
        {
            dukpp03::IsNotPODReference<_Arg>::typeMustBe();
            a = dukpp03::GetValue< typename dukpp03::Decay<_Arg>::Type, _Context >::perform(c, stackValue);
            if (a.exists() == false)
            {
                std::string name = _Context::template typeName< _Arg >();
                c->throwInvalidTypeError(argnumber, name);
                throw dukpp03::ArgumentException();
            }
        }
        
        /*! Check this value to find value for specified type
            \param[in] c context
            \return 1 if exists, otherwise 0
         */
        static int checkThis(_Context* c)
        {
            dukpp03::IsNotPODReference<_Arg>::typeMustBe();
            duk_push_this(c->context());
            dukpp03::Maybe< typename dukpp03::Decay<_Arg>::Type > a = dukpp03::GetValue< typename dukpp03::Decay<_Arg>::Type, _Context >::perform(c, -1);
            duk_pop(c->context());
            return (a.exists()) ? 1 : 0;
        }
    
        /*! Check stack to find value for specified type
            \param[in] c context
            \param[in] stackValue a value index on stack
            \return 1 if exists, otherwise 0
         */
        static int checkStack(_Context* c, int stackValue)
        {
            dukpp03::IsNotPODReference<_Arg>::typeMustBe();
            dukpp03::Maybe< typename dukpp03::Decay<_Arg>::Type > a = dukpp03::GetValue< typename dukpp03::Decay<_Arg>::Type, _Context >::perform(c, stackValue);
            return (a.exists()) ? 1 : 0;
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

/*! A macro for getting maybe value from this stack
 */
#define DUKPP03_MAYBE_FROM_THIS(TYPE)  dukpp03::Maybe< typename dukpp03::Decay< DUKPP03_TYPE(TYPE) >::Type > _ac; Callable<_Context>::template CheckArgument< DUKPP03_TYPE(TYPE) >::passedAsThis(c, _ac)
/*! A macro for getting maybe value from stack
 */
#define DUKPP03_MAYBE_FROM_STACK(TYPE, NAME, STACKV, NUMBER)  dukpp03::Maybe< typename dukpp03::Decay< DUKPP03_TYPE(TYPE) >::Type > _a##NAME; Callable<_Context>::template CheckArgument< DUKPP03_TYPE(TYPE) >::onStack(c, _a##NAME, STACKV, NUMBER)
/*! A macro for checking arguments on stack
 */
#define DUKPP03_CS(TYPE, STACKV) Callable<_Context>::template CheckArgument< DUKPP03_TYPE(TYPE) >::checkStack(c, STACKV);
/*! A macro for beginning checking  whether function can be called
 */
#define DUKPP03_CBC_BEGIN virtual std::pair<int, bool> canBeCalled(_Context* c) { int required_args = this->requiredArguments(); if (c->getTop() != required_args) { return std::make_pair(-1, false); }
/*! A macro for ending checking  whether function  can be called
 */
#define DUKPP03_CBC_END }
/*! An extended beginning for determining whether function can be called
 */ 
#define DUKPP03_CBC_BEGIN_EX DUKPP03_CBC_BEGIN int a = 0;
/*! An extended ending for determining whether function can be called
 */
#define DUKPP03_CBC_END_EX return std::make_pair(a, a == required_args); DUKPP03_CBC_END
/*! A can be called for zero args
 */ 
#define DUKPP03_CBC_0 DUKPP03_CBC_BEGIN return std::make_pair(0, true); DUKPP03_CBC_END
#define DUKPP03_CBC_1(BEGIN, A0)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_2(BEGIN, A0, A1)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_3(BEGIN, A0, A1, A2)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_4(BEGIN, A0, A1, A2, A3)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_5(BEGIN, A0, A1, A2, A3, A4)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_6(BEGIN, A0, A1, A2, A3, A4, A5)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_7(BEGIN, A0, A1, A2, A3, A4, A5, A6)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); a += DUKPP03_CS(A6, BEGIN + 6); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_8(BEGIN, A0, A1, A2, A3, A4, A5, A6, A7)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); a += DUKPP03_CS(A7, BEGIN + 7); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_9(BEGIN, A0, A1, A2, A3, A4, A5, A6, A7, A8)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); a += DUKPP03_CS(A7, BEGIN + 7);  a += DUKPP03_CS(A8, BEGIN + 8); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_10(BEGIN, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); a += DUKPP03_CS(A7, BEGIN + 7);  a += DUKPP03_CS(A8, BEGIN + 8); a += DUKPP03_CS(A9, BEGIN + 9); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_11(BEGIN, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); a += DUKPP03_CS(A7, BEGIN + 7);  a += DUKPP03_CS(A8, BEGIN + 8); a += DUKPP03_CS(A9, BEGIN + 9); a += DUKPP03_CS(A10, BEGIN + 10); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_12(BEGIN, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); a += DUKPP03_CS(A7, BEGIN + 7);  a += DUKPP03_CS(A8, BEGIN + 8); a += DUKPP03_CS(A9, BEGIN + 9); a += DUKPP03_CS(A10, BEGIN + 10); a += DUKPP03_CS(A11, BEGIN + 11); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_13(BEGIN, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); a += DUKPP03_CS(A7, BEGIN + 7);  a += DUKPP03_CS(A8, BEGIN + 8); a += DUKPP03_CS(A9, BEGIN + 9); a += DUKPP03_CS(A10, BEGIN + 10); a += DUKPP03_CS(A11, BEGIN + 11); a += DUKPP03_CS(A12, BEGIN + 12); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_14(BEGIN, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); a += DUKPP03_CS(A7, BEGIN + 7);  a += DUKPP03_CS(A8, BEGIN + 8); a += DUKPP03_CS(A9, BEGIN + 9); a += DUKPP03_CS(A10, BEGIN + 10); a += DUKPP03_CS(A11, BEGIN + 11); a += DUKPP03_CS(A12, BEGIN + 12); a += DUKPP03_CS(A13, BEGIN + 13); DUKPP03_CBC_END_EX
#define DUKPP03_CBC_15(BEGIN, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); a += DUKPP03_CS(A7, BEGIN + 7);  a += DUKPP03_CS(A8, BEGIN + 8); a += DUKPP03_CS(A9, BEGIN + 9); a += DUKPP03_CS(A10, BEGIN + 10); a += DUKPP03_CS(A11, BEGIN + 11); a += DUKPP03_CS(A12, BEGIN + 12); a += DUKPP03_CS(A13, BEGIN + 13); a += DUKPP03_CS(A14, BEGIN + 14);  DUKPP03_CBC_END_EX
#define DUKPP03_CBC_16(BEGIN, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); a += DUKPP03_CS(A7, BEGIN + 7);  a += DUKPP03_CS(A8, BEGIN + 8); a += DUKPP03_CS(A9, BEGIN + 9); a += DUKPP03_CS(A10, BEGIN + 10); a += DUKPP03_CS(A11, BEGIN + 11); a += DUKPP03_CS(A12, BEGIN + 12); a += DUKPP03_CS(A13, BEGIN + 13); a += DUKPP03_CS(A14, BEGIN + 14); DUKPP03_CS(A15, BEGIN + 15);  DUKPP03_CBC_END_EX
#define DUKPP03_CBC_17(BEGIN, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16)  DUKPP03_CBC_BEGIN_EX a += DUKPP03_CS(A0, BEGIN); a += DUKPP03_CS(A1, BEGIN + 1); a += DUKPP03_CS(A2, BEGIN + 2); a += DUKPP03_CS(A3, BEGIN + 3); a += DUKPP03_CS(A4, BEGIN + 4); a += DUKPP03_CS(A5, BEGIN + 5); a += DUKPP03_CS(A7, BEGIN + 7);  a += DUKPP03_CS(A8, BEGIN + 8); a += DUKPP03_CS(A9, BEGIN + 9); a += DUKPP03_CS(A10, BEGIN + 10); a += DUKPP03_CS(A11, BEGIN + 11); a += DUKPP03_CS(A12, BEGIN + 12); a += DUKPP03_CS(A13, BEGIN + 13); a += DUKPP03_CS(A14, BEGIN + 14); DUKPP03_CS(A15, BEGIN + 15);  DUKPP03_CS(A16, BEGIN + 16);  DUKPP03_CBC_END_EX


#define DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) DUKPP03_CBC_BEGIN_EX a +=  Callable<_Context>::template CheckArgument< DUKPP03_TYPE(TYPE) >::checkThis(c);
#define DUKPP03_CBC_WITH_THIS_END return std::make_pair(a, a == required_args + 1); DUKPP03_CBC_END
#define DUKPP03_CBC_WITH_THIS_0(TYPE) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_1(TYPE, A0) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0);  DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_2(TYPE, A0, A1) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1);  DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_3(TYPE, A0, A1, A2) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2);  DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_4(TYPE, A0, A1, A2, A3) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3);  DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_5(TYPE, A0, A1, A2, A3, A4) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4);  DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_6(TYPE, A0, A1, A2, A3, A4, A5) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_7(TYPE, A0, A1, A2, A3, A4, A5, A6) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  a += DUKPP03_CS(A6, 6); DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_8(TYPE, A0, A1, A2, A3, A4, A5, A6, A7) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  a += DUKPP03_CS(A6, 6); a += DUKPP03_CS(A7, 7); DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_9(TYPE, A0, A1, A2, A3, A4, A5, A6, A7, A8) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  a += DUKPP03_CS(A6, 6); a += DUKPP03_CS(A7, 7); a += DUKPP03_CS(A8, 8); DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_10(TYPE, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  a += DUKPP03_CS(A6, 6); a += DUKPP03_CS(A7, 7); a += DUKPP03_CS(A8, 8); a += DUKPP03_CS(A9, 9); DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_11(TYPE, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  a += DUKPP03_CS(A6, 6); a += DUKPP03_CS(A7, 7); a += DUKPP03_CS(A8, 8); a += DUKPP03_CS(A9, 9); a += DUKPP03_CS(A10, 10); DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_12(TYPE, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  a += DUKPP03_CS(A6, 6); a += DUKPP03_CS(A7, 7); a += DUKPP03_CS(A8, 8); a += DUKPP03_CS(A9, 9); a += DUKPP03_CS(A10, 10); a += DUKPP03_CS(A11, 11); DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_13(TYPE, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  a += DUKPP03_CS(A6, 6); a += DUKPP03_CS(A7, 7); a += DUKPP03_CS(A8, 8); a += DUKPP03_CS(A9, 9); a += DUKPP03_CS(A10, 10); a += DUKPP03_CS(A11, 11); a += DUKPP03_CS(A12, 12); DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_14(TYPE, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  a += DUKPP03_CS(A6, 6); a += DUKPP03_CS(A7, 7); a += DUKPP03_CS(A8, 8); a += DUKPP03_CS(A9, 9); a += DUKPP03_CS(A10, 10); a += DUKPP03_CS(A11, 11); a += DUKPP03_CS(A12, 12); a += DUKPP03_CS(A13, 13); DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_15(TYPE, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  a += DUKPP03_CS(A6, 6); a += DUKPP03_CS(A7, 7); a += DUKPP03_CS(A8, 8); a += DUKPP03_CS(A9, 9); a += DUKPP03_CS(A10, 10); a += DUKPP03_CS(A11, 11); a += DUKPP03_CS(A12, 12); a += DUKPP03_CS(A13, 13); a += DUKPP03_CS(A14, 14); DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_16(TYPE, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  a += DUKPP03_CS(A6, 6); a += DUKPP03_CS(A7, 7); a += DUKPP03_CS(A8, 8); a += DUKPP03_CS(A9, 9); a += DUKPP03_CS(A10, 10); a += DUKPP03_CS(A11, 11); a += DUKPP03_CS(A12, 12); a += DUKPP03_CS(A13, 13); a += DUKPP03_CS(A14, 14); a += DUKPP03_CS(A15, 15); DUKPP03_CBC_WITH_THIS_END
#define DUKPP03_CBC_WITH_THIS_17(TYPE, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16) DUKPP03_CBC_WITH_THIS_BEGIN(TYPE) a += DUKPP03_CS(A0, 0); a += DUKPP03_CS(A1, 1); a += DUKPP03_CS(A2, 2); a += DUKPP03_CS(A3, 3); a += DUKPP03_CS(A4, 4); a += DUKPP03_CS(A5, 5);  a += DUKPP03_CS(A6, 6); a += DUKPP03_CS(A7, 7); a += DUKPP03_CS(A8, 8); a += DUKPP03_CS(A9, 9); a += DUKPP03_CS(A10, 10); a += DUKPP03_CS(A11, 11); a += DUKPP03_CS(A12, 12); a += DUKPP03_CS(A13, 13); a += DUKPP03_CS(A14, 14); a += DUKPP03_CS(A15, 15);  a += DUKPP03_CS(A16, 16); DUKPP03_CBC_WITH_THIS_END

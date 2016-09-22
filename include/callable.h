/*! \file callable.h
    

    Contains definition of function wrapper, callable from Duktape, which will be used as substitution object, used
    to produce template bindings.
 */
#pragma once
#include "abstractcallable.h"
#include <utility>
    
namespace dukpp03
{
    

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
        
    }
};

}

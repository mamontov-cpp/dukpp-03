/*! \file callable.h
    

    Contains definition of function wrapper, callable from Duktape, which will be used as substitution object, used
    to produce template bindings.
 */
#pragma once
    
namespace dukpp03
{
    
class AbstractContext;

/*! A definition of function wrapper, callable from Duktape, which will be used as substitution object, used
    to produce template bindings
 */
class Callable
{
public:
    /*! Must return copy of callable object
        \return copy of callable object
     */
    virtual Callable* clone() = 0;
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() = 0;
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* c);
    /*! Must be inherited
     */
    virtual ~Callable();
};

}

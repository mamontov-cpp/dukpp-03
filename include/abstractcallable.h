/*! \file abstractcallable.h
    
    Defines a basic callable object
 */
#pragma once
#include <stdexcept>

namespace dukpp03
{

/*! A basic exception, related to errors in casting values
 */ 
class ArgumentException: public std::runtime_error
{
public:
    /*! By default makes an exception, which contains string, indicating, that passed argument is bad
     */
    ArgumentException();
    /*! It could be inherited, but there are no reason to do that
     */
    virtual ~ArgumentException() override;
};
    

/*! A definition of function wrapper, callable from Duktape, which will be used as substitution object, used
    to produce template bindings
 */
class AbstractCallable
{
public:
    /*! Returns whether it could be called as constructor
        \return true if can
     */
    virtual bool canBeCalledAsConstructor();
    /*! Returns whether it could be called as function
        \return true if can
     */
    virtual bool canBeCalledAsFunction();
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() = 0;
    /*! Must be inherited
     */
    virtual ~AbstractCallable();
};



}
/*! \file abstractcallable.h
    
	Defines a basic callable object
 */
#pragma once


namespace dukpp03
{


/*! A definition of function wrapper, callable from Duktape, which will be used as substitution object, used
    to produce template bindings
 */
class AbstractCallable
{
public:
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() = 0;
    /*! Must be inherited
     */
    virtual ~AbstractCallable();
};



}
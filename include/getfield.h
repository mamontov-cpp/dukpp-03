/*! \file getfield.h
     
    Defines a simple getter, which allows to a script to get a value of particular field
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

/*! Defines a wrapper for getting field of class
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType
>
class GetField : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType _ClassName::*Field;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    GetField(Field f): m_field(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::GetField<_Context, _ClassName, _ReturnType>(m_field);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_ClassName)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName);
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, ((_ac._()).*m_field));
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~GetField()
    {
    }
protected:
    /*! A field, which is being wrapped
     */
    Field m_field;
};




/*! Defines a wrapper for getting field of class
 */
template<
    typename _Context,
	typename _DestClassName,
    typename _ClassName,
    typename _ReturnType
>
class GetFieldFor : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType _ClassName::*Field;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    GetFieldFor(Field f): m_field(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::GetFieldFor<_Context, _DestClassName, _ClassName, _ReturnType>(m_field);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 0;
    }

    DUKPP03_CBC_WITH_THIS_0(_DestClassName)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_DestClassName);
        dukpp03::PushValue<_ReturnType, _Context>::perform(c, ((_ac._()).*m_field));
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~GetFieldFor()
    {
    }
protected:
    /*! A field, which is being wrapped
     */
    Field m_field;
};

/*! A convenient wrapper for typedefs
 */ 
template<typename _Context> 
struct getter
{
    /*! Returns a getter for specified field
        \param[in] field a field
        \return getter
     */
    template<typename _ClassName, typename _ReturnType>
    static dukpp03::GetField<_Context, _ClassName, _ReturnType>* from(_ReturnType _ClassName::*field)
    {
        return new dukpp03::GetField<_Context, _ClassName, _ReturnType>(field);
    }

/*! Remaps a field to specified class
 */
template<
	typename _DestClass
>
struct to
{
    /*! Returns a getter for specified field
        \param[in] field a field
        \return getter
     */
    template<typename _ClassName, typename _ReturnType>
    static dukpp03::GetFieldFor<_Context, _DestClass,  _ClassName, _ReturnType>* from(_ReturnType _ClassName::*field)
    {
        return new dukpp03::GetFieldFor<_Context, _DestClass,  _ClassName, _ReturnType>(field);
    }	    
};

};

};

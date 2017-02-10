/*! \file setfield.h
     
    Defines a simple setter, which allows to a script to set a value of particular field
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

/*! Defines a wrapper for setting field of class
 */
template<
    typename _Context, 
    typename _ClassName,
    typename _ReturnType
>
class SetField : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType _ClassName::*Field;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    SetField(Field f): m_field(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::SetField<_Context, _ClassName, _ReturnType>(m_field);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_ClassName, _ReturnType)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_ClassName);
        DUKPP03_MAYBE_FROM_STACK(_ReturnType, 0, 0, 1);
        ((_ac._()).*m_field) = _a0._();
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~SetField()
    {
    }
protected:
    /*! A field, which is being wrapped
     */
    Field m_field;
};



/*! Defines a wrapper for setting field of class
 */
template<
    typename _Context, 
    typename _DestClassName, 
    typename _ClassName,
    typename _ReturnType
>
class SetFieldFor : public dukpp03::FunctionCallable<_Context>
{
public:
    /*! A function type, which is being wrapped
     */
    typedef _ReturnType _ClassName::*Field;
    /*! Constructs new function wrapper
        \param[in] f function
     */
    SetFieldFor(Field f): m_field(f)   
    {
    }
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone()  
    {
        return new dukpp03::SetFieldFor<_Context, _DestClassName, _ClassName, _ReturnType>(m_field);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 1;
    }

    DUKPP03_CBC_WITH_THIS_1(_DestClassName, _ReturnType)
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(_Context* c)
    {
        DUKPP03_MAYBE_FROM_THIS(_DestClassName);
        DUKPP03_MAYBE_FROM_STACK(_ReturnType, 0, 0, 1);
        ((_ac._()).*m_field) = _a0._();
        return 0;
    }
    /*! Can be inherited
     */
    virtual ~SetFieldFor()
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
struct setter
{
    /*! Returns a getter for specified field
        \param[in] field a field
        \return getter
     */
    template<typename _ClassName, typename _ReturnType>
    static dukpp03::SetField<_Context, _ClassName, _ReturnType>* from(_ReturnType _ClassName::*field)
    {
        return new dukpp03::SetField<_Context, _ClassName, _ReturnType>(field);
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
    static dukpp03::SetFieldFor<_Context, _DestClass,  _ClassName, _ReturnType>* from(_ReturnType _ClassName::*field)
    {
        return new dukpp03::SetFieldFor<_Context, _DestClass,  _ClassName, _ReturnType>(field);
    }
};

};

};

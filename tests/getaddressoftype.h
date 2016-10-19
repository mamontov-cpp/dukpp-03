/*! \file getaddressoftype.h
    
    Gets address of specified type
 */
#pragma once
#include <boost/any.hpp>
#include <maybe.h>

namespace dukpp03
{

/*! Gets adress fo value of specified type, that is stored in variant.
    Here we try to get plain value (not a pointer type) as and address, so we don't allow such behaviour
 */
template<typename _UnderlyingValue>
struct GetAddressOfType
{
public: 
    /*! Returns address of type, stored in variant - hence nothing for plain types
        \param[in] v value
        \return empty maybe
     */
    static dukpp03::Maybe<_UnderlyingValue> getAddress(boost::any* v)
    {
        return dukpp03::Maybe<_UnderlyingValue>();
    };
};

/*! Returns address of type stored in variant.
 */
template<typename _UnderlyingValue>
struct GetAddressOfType<_UnderlyingValue*>
{
public: 
    /*! Returns address of type, stored in variant.
        \param[in] v value
        \return empty maybe
     */
    static dukpp03::Maybe<_UnderlyingValue*> getAddress(boost::any* v)
    {
        try
        {
            // Make it strict! No pointer casts are permitted
            if (typeid(_UnderlyingValue) != v->type())
            {
                return dukpp03::Maybe<_UnderlyingValue*>();
            }
            _UnderlyingValue* val = boost::any_cast<_UnderlyingValue>(v);
            return dukpp03::Maybe<_UnderlyingValue*>(val);
        }
        catch (boost::bad_any_cast &)
        {
            return dukpp03::Maybe<_UnderlyingValue*>();
        }
        return dukpp03::Maybe<_UnderlyingValue*>();
    };
};

}
/*! \file utils.h
  
    Defines an underlying implementation of VariantInterface, TimerInterface, MapInterface via Boost
 */
#pragma once
#include <boost/any.hpp>
#include <typeinfo>
#include <maybe.h>

namespace dukpp03
{

namespace utils
{

class VariantInterface
{
public:
    typedef boost::any Variant;
    
    /*! Makes variant from value
        \param[in] val value
        \param[in] v variant
     */
    template<
        typename _UnderlyingValue
    >
    static Variant* makeFrom(_UnderlyingValue val)
    {
        return new boost::any(val);
    }
    /*! Fetches underlying value from variant type
        \param[in] v a variant, containing data
        \return an underlying value
     */
    template<
        typename _UnderlyingValue
    >   
    static dukpp03::Maybe<_UnderlyingValue> get(Variant* v)
    {
        try
        {
            _UnderlyingValue* val = boost::any_cast<_UnderlyingValue>(v);
            return dukpp03::Maybe<_UnderlyingValue>(val);
        }
        catch (boost::bad_any_cast &e)
        {
            return dukpp03::Maybe<_UnderlyingValue>();
        }
        return dukpp03::Maybe<_UnderlyingValue>();
    }
    
    /*! A typename interface for variant
     */
    template<
        typename _UnderlyingValue
    >
    class TypeName 
    {
        /*! Returns name of type 
            \return name of type
         */
        static std::string type()
        {
            return typeid(_UnderlyingValue).name();
        }
    };
};


}


}
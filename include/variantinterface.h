/*! \file variantinterface.h
    
    Defines a generic interface for interacting with variants
 */
#pragma once
#include "maybe.h"
#include <string>

namespace dukpp03
{

/*! A generic abstract interface for interacting with variants.
    Variants must be specified by underlying implementation
 */ 
template<typename _VariantType> 
struct VariantInterface
{
public:
    /*! A variant type, which will be used
     */ 
    typedef _VariantType Variant;
    /*! Makes variant from value
        \param[in] val value
        \return variant value
     */
    template<
        typename _UnderlyingValue
    >
    static _VariantType* makeFrom(_UnderlyingValue val);
    /*! Fetches underlying value from variant type. Note,
        that if we are stored T* in variant and requesting value of
        type T this function MUST return empty maybe, because in other cases 
        it will force system to misbehave. For example, this problem can arise,
        if using boost::any as variant wrapping type
        \param[in] v a variant, containing data
        \return an underlying value
     */
    template<
        typename _UnderlyingValue
    >   
    static dukpp03::Maybe<_UnderlyingValue> get(_VariantType* v);
    /*! If objects contains an object, where _UnderlyingValue pointing, should return a pointer to this adress
         \param[in] v value
         \return result
     */
    template<
        typename _UnderlyingValue
    >
    static dukpp03::Maybe<_UnderlyingValue> getAddress(_VariantType* v);
    
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
        static std::string type();
    };
};
    
}

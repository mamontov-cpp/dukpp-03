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
template<typename _VariantType, template<typename, typename> typename _HashMapType>	
struct VariantInterface
{
public:
	/*! A variant type, which will be used
	 */ 
	typedef _VariantType Variant;
	/*! Makes variant from value
		\param[in] val value
		\param[in] v variant
	 */
	template<
		typename _UnderlyingValue
	>
	static _VariantType* makeFrom(_UnderlyingValue val);
	/*! Fetches underlying value from variant type
		\param[in] v a variant, containing data
		\return an underlying value
	 */
	template<
		typename _UnderlyingValue
	>	
	static dukpp03::Maybe<_UnderlyingValue> get(_VariantType* v);			
};
	
}

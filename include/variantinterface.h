/*! \file variantinterface.h
	
	Defines a generic interface for interacting with variants
 */
#pragma once
#include "maybe.h"

namespace dukpp03
{

/*! A generic abstract interface for interacting with variants.
	Variants must be specified by underlying implementation
 */	
template<typename _VariantType>	
struct VariantInterface
{
public:
	/*! Makes variant from value
		\param[in] val value
		\param[in] v variant
	 */
	template<
		typename _UnderlyingValue
	>
	void makeFrom(_UnderlyingValue val, _VariantType& v);
	/*! Fetches underlying value from variant type
		\param[in] v a variant, containing data
		\return an underlying value
	 */
	template<
		typename _UnderlyingValue
	>	
	dukpp03::Maybe<_UnderlyingValue> get(_VariantType& v);		
};
	
}

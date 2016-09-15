/*! \file mapinterface.h
	
	Defines a generic interface for interacting with maps
 */
#pragma once
#include <string>

namespace dukpp03
{

/*! A generic abstract interface for interacting with hash maps.
	Hash maps must be specified by underlying implementation
 */	
template<
	template<typename, typename> typename _HashMapType
>
struct MapInterface
{
	/*! An inner type generator for making maps with various values
	 */
	template<
		typename _Value
	>
	struct Map
	{
		typedef _HashMapType<std::string, _Value> Container;
		typedef _HashMapType<_Value*, _Value*> PointerSet;
	};
	
	/*! Copies map from one place to other
		\param[in] source a source map
		\param[out] dest other map
	 */
	template<
		typename _Value
	>
	static void copy(const _HashMapType<std::string, _Value>& source, _HashMapType<std::string, _Value>& dest);
	/*! Frees map, removing sources
		\param[in, out] a source map
	 */
	template<
		typename _Value
	>	 
	static void destroy(_HashMapType<std::string, _Value>& source);
	
	/*! Frees map, removing sources
		\param[in, out] a source map
	 */
	template<
		typename _Value
	>	 
	static void destroy(_HashMapType<_Value*, _Value*>& source);
	/*! Inserts element to map, replacing existing, if need to
		\param[in, out] dest a  map
		\param[in] k key
		\param[in] v value
	 */
	template<
		typename _Value
	>	 
	static void insert(_HashMapType<std::string, _Value>& dest, const std::string& k, _Value v);
	
	/*! Inserts element to map, replacing existing, if need to
		\param[in, out] dest a  map
		\param[in] k key
		\param[in] v value
	 */
	template<
		typename _Value
	>	 
	static void insert(_HashMapType<_Value*, _Value*>& dest, const _Value* k, _Value* v);
	/*! Returns element by key (NULL if does not exists)
		\param[in] m a map
     	\param[in] k key
		\reutrn value (generic if does not exists)
	 */
	template<
		typename _Value
	>	 
	static _Value get(_HashMapType<std::string, _Value>& map, const std::string& k);
	/*! Clears map
		\param[in, out] dest a  map
	 */
	template<
		typename _Value
	>	 
	static void clear(_HashMapType<_Value*, _Value*>& dest);
};

}

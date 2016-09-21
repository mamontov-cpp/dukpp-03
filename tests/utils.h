/*! \file utils.h
  
    Defines an underlying implementation of VariantInterface, TimerInterface, MapInterface via Boost
 */
#pragma once
#include <boost/any.hpp>
#include <boost/unordered_map.hpp>
#include <typeinfo>
#include <maybe.h>
#include <decay.h>

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

struct MapInterface
{
	/*! An inner type generator for making maps with various values
	 */
	template<
		typename _Value
	>
	struct Map
	{
		typedef boost::unordered_map<std::string, _Value> Container;
		typedef boost::unordered_map<_Value*, _Value*> PointerSet;
	};
	
	
	/*! Copies map from one place to other
		\param[in] source a source map
		\param[out] dest other map
	 */
	template<
		typename _Value
	>
	static void copy(const boost::unordered_map<std::string, _Value>& source,  boost::unordered_map<std::string, _Value>& dest)
	{
		dukpp03::utils::MapInterface::destroy(dest);
		for(boost::unordered_map<std::string, _Value>::iterator it = source.begin(); it != source.end(); ++it)
		{
			dukpp03::utils::MapInterface::insert(dest, it->first, new dukpp03::Decay<_Value>::Type(*(it->second)));
		}
	}
	/*! Frees map, removing sources
		\param[in, out] a source map
	 */
	template<
		typename _Value
	>	 
	static void destroy(boost::unordered_map<std::string, _Value>& source)
	{
		for(boost::unordered_map<std::string, _Value>::iterator it = source.begin(); it != source.end(); ++it)
		{
			delete it->second;
		}
		source.clear();
	};
	/*! Frees map, removing sources
		\param[in, out] a source map
	 */
	template<
		typename _Value
	>	 
	static void destroy(boost::unordered_map<_Value*, _Value*>& source)
	{
		for(boost::unordered_map<std::string, _Value>::iterator it = source.begin(); it != source.end(); ++it)
		{
			delete it->second;
		}
		source.clear();
	}
	/*! Inserts element to map, replacing existing, if need to
		\param[in, out] dest a  map
		\param[in] k key
		\param[in] v value
	 */
	template<
		typename _Value
	>	 
	static void insert(_HashMapType<std::string, _Value>& dest, const std::string& k, _Value v)
	{
		if (dest.count(k) > 0)
		{
			delete dest[k];
			dest.remove(k);
		}
		dest.insert(k, v);
	}
	
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


}
/*! \file pool.h
    

    Describes a pool for variants, which are identified by a very large number,
    stored as binary string.
 */
#pragma once

#include "id.h"
#include "mapinterface.h"
#include "variantinterface.h"


namespace dukpp03
{

/*! Describes a pool of variants, stored in context
 */
template<
	typename _VariantInterface, 
	typename _MapInterface
>
class Pool
{
public:
    /*! Creates default variant pool
     */
    Pool()
	{
		
	}
    /*! Frees variant pool data
     */
    ~Pool()
	{
		_MapInterface::destroy(m_pool);
	}
    /*! Copies state from other pool
        \param[in] p pool
     */
    Pool(const dukpp03::Pool<_VariantInterface, _MapInterface>& p)
	{
		_MapInterface::copy(m_pool, p.m_pool);
	}
    /*! Copies state from other pool
        \param[in] p pool
        \return self-reference
     */
    Pool<_VariantInterface, _MapInterface>& operator=(const dukpp03::Pool<_VariantInterface, _MapInterface>& p)
	{
		_MapInterface::destroy(m_pool);
		_MapInterface::copy(m_pool, p.m_pool);
		return *this;
	}
    /*! Inserts new variant to a pool
        \param[in] v variant
        \return a string, which identifies a variant
     */
    std::string insert(typename _VariantInterface::Variant* v)
	{
		std::string result = m_maxid.bytes();
		_MapInterface::insert(m_pool, result, v);
		m_maxid.next();
		return result;
	}
    /*! Fetches variant by it's key. NULL returned if not found
        \param[in] key key, identifying variant
        \return variant or NULL if not found
     */
    typename _VariantInterface::Variant* get(const std::string& key)
	{
		return _MapInterface::get(m_pool, key);
	}
    /*! Destroys all variant in pool
     */
    void free()
	{
		_MapInterface::destroy(m_pool);
	}
protected:
    /*! Maximal id of pool
     */
    dukpp03::Id m_maxid;
    /*! Pool of variants, which are identified by strings
     */
    typename _MapInterface::template Map<_VariantInterface::Variant>::Container m_pool;
};

}
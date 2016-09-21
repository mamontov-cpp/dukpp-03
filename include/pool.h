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
    template<typename, typename> class _MapInterface
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
        for(typename _MapInterface<std::string, typename _VariantInterface::Variant*>::iterator it = m_pool.begin(); it.end() == false; it.next())
        {
            delete it.value();
        }
        m_pool.clear();
    }
    /*! Copies state from other pool
        \param[in] p pool
     */
    Pool(const dukpp03::Pool<_VariantInterface, _MapInterface>& p)
    {
        for(typename _MapInterface<std::string, typename _VariantInterface::Variant*>::iterator it = p.m_pool.begin(); it.end() == false; it.next())
        {
            m_pool.insert(it.key(), new typename _VariantInterface::Variant(*(it.value())));
        }
        m_maxid = p.m_maxid;
    }
    /*! Copies state from other pool
        \param[in] p pool
        \return self-reference
     */
    Pool<_VariantInterface, _MapInterface>& operator=(const dukpp03::Pool<_VariantInterface, _MapInterface>& p)
    {
        for(typename _MapInterface<std::string, typename  _VariantInterface::Variant*>::iterator it = m_pool.begin(); it.end() == false; it.next())
        {
            delete it.value();
        }
        m_pool.clear();
        for(typename _MapInterface<std::string, typename  _VariantInterface::Variant*>::iterator it = p.m_pool.begin(); it.end() == false; it.next())
        {
            m_pool.insert(it.key(), new typename _VariantInterface::Variant(*(it.value())));
        }
        m_maxid = p.m_maxid;
        return *this;
    }
    /*! Inserts new variant to a pool
        \param[in] v variant
        \return a string, which identifies a variant
     */
    std::string insert(typename _VariantInterface::Variant* v)
    {
        std::string result = m_maxid.bytes();
        m_pool.insert(result, v);
        return result;
    }
    /*! Fetches variant by it's key. NULL returned if not found
        \param[in] key key, identifying variant
        \return variant or NULL if not found
     */
    typename _VariantInterface::Variant* get(const std::string& key)
    {
        if (m_pool.contains(key) == false)
        {
            return NULL;
        }
        return m_pool.get(key);
    }
    /*! Destroys all variant in pool
     */
    void free()
    {
        for(typename _MapInterface<std::string, typename  _VariantInterface::Variant*>::iterator it = m_pool.begin(); it.end() == false; it.next())
        {
            delete it.value();
        }
        m_pool.clear();
    }
protected:
    /*! Maximal id of pool
     */
    dukpp03::Id m_maxid;
    /*! Pool of variants, which are identified by strings
     */
    _MapInterface<std::string, typename _VariantInterface::Variant*> m_pool;
};

}

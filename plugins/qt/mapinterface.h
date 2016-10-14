/*! \file mapinterface.h
    
    Defines a map interface to be used with context
 */
#pragma once
#include <string>
#include <QHash>
#include <QString>

namespace dukpp03
{

namespace qt
{


template<
    typename _Key,
    typename _Value
>
class MapInterface
{
public:
    /*! A basic iterator
     */
    struct iterator
    {
        /*! An inner iterator
         */
        typename QHash<_Key, _Value>::const_iterator it;
        /*! A parent map
         */ 
        QHash<_Key, _Value> const* parent;
        /*! Returns key
            \return key of map
         */
        const _Key& key()
        {
            return it.key();
        }
        /*! Returns value
            \returns value for element of map
         */
        const _Value& value()
        {
            return it.value();
        }
        /*! Proceeds to next value
         */
        void next()
        {
            ++it;
        }
        /*! Returns true on end
            \return end
         */
        bool end()
        {
            return it == parent->end();
        }
    };
    
    MapInterface()
    {
        
    }
    
    
    /*! Returns beginning iterator for container
     */ 
    iterator begin() const
    {
        iterator it;
        it.it = m_map.begin();
        it.parent = &m_map;
        return it;
    }
    /*! Inserts new element into map, erasing old value, if needed
        \param[in] k key value
        \param[in] v value
     */
    void insert(const _Key& k, const _Value& v)
    {
        m_map.insert(k, v);
    }
    /*! Removes value by key
        \param[in] k key value
     */
    void remove(const _Key& k)
    {
        m_map.remove(k);
    }
    /*! Returns true, if map contains key value
        \param[in] k key value
        \return whether map contains value
     */
    bool contains(const _Key& k)
    {
        return m_map.contains(k);
    }
    /*! Returns value by specified key
        \param[in] k key
        \return value
     */
    const _Value& get(const _Key& k)
    {
        return m_map[k];
    }
    /*! Clears value of interface
     */
    void clear()
    {
        m_map.clear();
    }
    /*! Inner map
     */
    QHash<_Key, _Value> m_map;
};



template<
    typename _Value
>
class MapInterface<std::string, _Value>
{
public:
    /*! A basic iterator
     */
    struct iterator
    {
        /*! An inner iterator
         */
        typename QHash<QString, _Value>::const_iterator it;
        /*! A parent map
         */ 
        QHash<QString, _Value> const* parent;
        /*! Returns key
            \return key of map
         */
        std::string key()
        {
            return it.key().toStdString();
        }
        /*! Returns value
            \returns value for element of map
         */
        const _Value& value()
        {
            return it.value();
        }
        /*! Proceeds to next value
         */
        void next()
        {
            ++it;
        }
        /*! Returns true on end
            \return end
         */
        bool end()
        {
            return it == parent->end();
        }
    };
    
    MapInterface()
    {
        
    }
    
    
    /*! Returns beginning iterator for container
     */ 
    iterator begin() const
    {
        iterator it;
        it.it = m_map.begin();
        it.parent = &m_map;
        return it;
    }
    /*! Inserts new element into map, erasing old value, if needed
        \param[in] k key value
        \param[in] v value
     */
    void insert(const std::string& k, const _Value& v)
    {
        m_map.insert(k.c_str(), v);
    }
    /*! Removes value by key
        \param[in] k key value
     */
    void remove(const std::string& k)
    {
        m_map.remove(k.c_str());
    }
    /*! Returns true, if map contains key value
        \param[in] k key value
        \return whether map contains value
     */
    bool contains(const std::string& k)
    {
        return m_map.contains(k.c_str());
    }
    /*! Returns value by specified key
        \param[in] k key
        \return value
     */
    const _Value& get(const std::string& k)
    {
        return m_map[k.c_str()];
    }
    /*! Clears value of interface
     */
    void clear()
    {
        m_map.clear();
    }
    /*! Inner map
     */
    QHash<QString, _Value> m_map;
};


}


}
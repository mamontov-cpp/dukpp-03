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
    typename _Key,
    typename _Value
>
struct MapInterface
{
    /*! A basic iterator
     */
    struct iterator
    {
        /*! Returns key
            \return key of map
         */
        const _Key& key();
        /*! Returns value
            \returns value for element of map
         */
        const _Value& value();
        /*! Proceeds to next value
         */
        void next();
        /*! Returns true on end
            \return end
         */
        bool end();
    };
    /*! Returns beginning iterator for container
     */ 
    iterator begin();
    /*! Inserts new element into map, erasing old value, if needed
        \param[in] k key value
        \param[in] v value
     */
    void insert(const _Key& k, const _Value& v);
    /*! Removes value by key
        \param[in] k key value
     */
    void remove(const _Key& k);
    /*! Returns true, if map contains key value
        \param[in] k key value
        \return whether map contains value
     */
    bool contains(const _Key& k);
    /*! Returns value by specified key
        \param[in] k key
        \return value
     */
    const _Value& get(const _Key& k);
    /*! Clears value of interface
     */
    void clear();
};

}

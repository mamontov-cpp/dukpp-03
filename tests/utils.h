/*! \file utils.h
  
    Defines an underlying implementation of VariantInterface, TimerInterface, MapInterface via Boost
 */
#pragma once
#include <boost/any.hpp>
#include <boost/unordered_map.hpp>
#include <boost/timer/timer.hpp>
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
        typename boost::unordered_map<_Key, _Value>::const_iterator it;
        /*! A parent map
         */ 
        boost::unordered_map<_Key, _Value> const* parent;
        /*! Returns key
            \return key of map
         */
        const _Key& key()
        {
            return it->first;
        }
        /*! Returns value
            \returns value for element of map
         */
        const _Value& value()
        {
            return it->second;
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
        m_map.insert(std::make_pair(k, v));
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
        return m_map.count(k) > 0;
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
    boost::unordered_map<_Key, _Value> m_map;
};

struct TimerInterface
{
    typedef boost::timer::cpu_timer Timer;

    /*! Restarts timer
        \param[in, out] t timer to be restarted
     */ 
    inline static void restart(boost::timer::cpu_timer& t)
    {
        t.start();
    }
    /*! Returns elapsed time for interface in ms
        \param[in] t timer
        \return elapsed time in milliseconds
     */
    inline static double elapsed(boost::timer::cpu_timer& t)
    {
        boost::timer::cpu_times const elapsed_times(t.elapsed());
        boost::timer::nanosecond_type const elapsed(elapsed_times.system + elapsed_times.user);
        return elapsed / 1000000L;
    }
};


}


}
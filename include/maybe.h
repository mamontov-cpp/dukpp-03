/*!  \file maybe.h
     

     Describes a value, that can be absent.
 */
#pragma once
#include <cstdlib>

namespace dukpp03
{
/*! A class, that represents a value or absent value
 */
template<typename T>
class Maybe
{
  private:
      T m_data;        //!< An inner boxed value
      T* m_reference;  //!< A reference part for maybe
      bool m_exists;   //!< Whether value exists
  public:
      /*! Creates new non-existent value
       */
      Maybe() : m_reference(NULL), m_exists(false) { } //-V730
      /*! Creates a new presented value
          \param[in] data an inner data for value
       */
      Maybe(const  T & data) :  m_exists(true), m_data(data), m_reference(NULL) { }
      /*! Creates new value for a reference to data
          \param[in] data a data to be set
       */
      Maybe(T* data) : m_reference(data), m_exists(true) { } //-V730
      /*! Sets maybe into a reference mode to make sure, that mutable value will be returned
       */
      void setReference(T* data) { m_reference = data; m_exists = true; }
      /*! Sets a value for objects, making it behave like with inner value
          \param[in] data data value
       */
      void setValue(const T & data)  { if (m_reference) { *m_reference = m_data; } else { m_data = data; } m_exists = true; }
      /*! Clears a maybe value
       */
      void clear() { m_exists = false; }
      /*! Whether inner value is exists
          \return whether inner value is exists
       */
      bool exists() const { return m_exists; }
      /*! Returns inner value. If value is not set, default value is returned,
          which is undefined for basic POD types.
          \return inner value
       */
      const  T & value() const  { if (m_reference) return *m_reference; return m_data; }
      /*! Returns inner mutable value. If value is not set, default value is returned,
          which is undefined for basic POD types.
          \return inner value
       */
      T& mutableValue() { if (m_reference) return *m_reference; return m_data; }
      /*! A synonym for getting a mutable value
       */
      T& _() { return this->mutableValue(); }
};

}

/*! \file wrapvalue.h
    
    Defines a generic interface for wrapping value
 */
#pragma once
#include "maybe.h"
#include <string>

namespace dukpp03
{

/*! A wrpper for wrapping value for specified context
 */
struct WrapValue
{

/*! Performs wrapping value into specified type
 */
template<typename _Value>
struct Perform
{
    /*! Performs a wrapping, by default does nothing
        \param[in] context a context
     */
    inline static void perform(void * context)
    {
        
    }
};

/*! Performs wrapping for value
    \param[in] context
 */
template<typename _Value>
inline static void perform(void* context)
{
    dukpp03::WrapValue::Perform::perform(context);
}

};
    
}

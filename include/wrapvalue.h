/*! \file wrapvalue.h
    
    Defines a generic interface for wrapping value
 */
#pragma once

namespace dukpp03
{

/*! A wrpper for wrapping value for specified context
 */
struct WrapValue
{

/*! Performs wrapping value for specified variant
    \param[in] context a context
    \param[in] variant a specified variant
    \param[in] wrapped was a value wrapped by generic binding previously
 */
inline static void perform(void* context, void* variant, bool wrapped)
{
    // Does nothing
}

};
    
}

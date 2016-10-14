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
    \parma[in] variant a specified variant
 */
inline static void perform(void* context, void* variant)
{
    // Does nothing
}

};
    
}

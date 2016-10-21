/*! \file wrapvalue.h
 
    A wrapping value class
 */
#pragma once

namespace dukpp03
{

namespace qt
{
    
/*! A wrpper for wrapping value for dukpp03::qt::Context
 */
struct WrapValue
{

/*! Performs wrapping value for specified variant
    \param[in] context a context
    \param[in] variant a specified variant
    \param[in] wrapped whether value has been wrapped
 */
static void perform(void* context, void* variant, bool wrapped);

};

}

}

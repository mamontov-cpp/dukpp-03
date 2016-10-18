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
    \parma[in] variant a specified variant
 */
static void perform(void* context, void* variant);

};

}

}

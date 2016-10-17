/*! \file qobjectfinalizer.h
    
    Declares finalizer for finalizing qobjects inside of variant
 */
#pragma once
#include "context.h"


namespace dukpp03
{

namespace qt
{
/*! A finalizer used to finalize an object variant
    \param[in] ctx context
	\return 0
 */
duk_ret_t qobjectfinalizer(duk_context* ctx);

}

}

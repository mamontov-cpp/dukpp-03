/*! \file basiccontext.h

    Defines a basic context, used with Qt
 */
#pragma once
#include "../../include/dukpp-03.h"

#ifndef HAS_QT5
    #define HAS_QT5 ( QT_VERSION >= 0x050000 )
#endif

#include "variantinterface.h"
#include "mapinterface.h"
#include "timerinterface.h"
#include "wrapvalue.h"

namespace dukpp03
{

namespace qt
{


/*! A basic context to be used with qt. Should not be used, use Context class instead
 */
typedef dukpp03::Context<dukpp03::qt::MapInterface, dukpp03::qt::VariantInterface, dukpp03::qt::TimerInterface, dukpp03::qt::WrapValue> BasicContext;
/*! Makes method bindings to context
 */
typedef dukpp03::bind_method<dukpp03::qt::BasicContext> bind_method;
/*! Makes method calls as calls to functions
 */
typedef dukpp03::make_method<dukpp03::qt::BasicContext> make_method;
/*! Makes functions from context calls
 */
typedef dukpp03::make_fun<dukpp03::qt::BasicContext> make_function;
/*! A getter generator for current context
 */
typedef dukpp03::getter<dukpp03::qt::BasicContext> getter;
/*! A setter generator for current context
 */
typedef dukpp03::setter<dukpp03::qt::BasicContext> setter;
/*! An object, used for basic context
 */
typedef dukpp03::JSObject<dukpp03::qt::BasicContext> JSObject;

}

}


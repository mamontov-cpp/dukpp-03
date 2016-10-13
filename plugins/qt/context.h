/*! \file context.h

    A context to be used with Qt
 */
#pragma once 
#include "../../include/dukpp-03.h"
#include "variantinterface.h"
#include "mapinterface.h"
#include "timerinterface.h"

namespace dukpp03
{

namespace qt
{
/*! A main context to be used with qt
 */
typedef dukpp03::Context<dukpp03::qt::MapInterface, dukpp03::qt::VariantInterface, dukpp03::qt::TimerInterface> Context;


}

}
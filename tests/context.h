/*! \file context.h
   
    Defines base context for our implementation
 */
#pragma once
#include <dukpp-03.h>
#include "utils.h"

namespace dukpp03
{

namespace context
{

typedef dukpp03::Context<dukpp03::utils::MapInterface, dukpp03::utils::VariantInterface, dukpp03::utils::TimerInterface> Context;

}

}

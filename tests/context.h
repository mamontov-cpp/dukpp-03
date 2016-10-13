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

typedef dukpp03::make_fun<dukpp03::context::Context> mkf;
typedef dukpp03::register_constructor<dukpp03::context::Context> register_constructor;
typedef dukpp03::make_method<dukpp03::context::Context> mkm;
typedef dukpp03::bind_method<dukpp03::context::Context> bnd;
typedef dukpp03::CompiledFunction<dukpp03::context::Context> compiledfunc;
typedef dukpp03::getter<dukpp03::context::Context> getter;
typedef dukpp03::setter<dukpp03::context::Context> setter;



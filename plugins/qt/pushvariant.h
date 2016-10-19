/*! \file pushvariant.h
     
    Declares a function for pushing variants on stack
 */
#pragma once
#include "context.h"
#include <QVariant>

namespace dukpp03
{

namespace qt
{

/*! A main context to be used with qt
 */
typedef dukpp03::Context<dukpp03::qt::MapInterface, dukpp03::qt::VariantInterface, dukpp03::qt::TimerInterface, dukpp03::qt::WrapValue> BasicContext;

/*! Performs pushing variant 
    \param[in] ctx context
    \param[in] v value
 */
void pushVariant(dukpp03::qt::BasicContext* ctx, const QVariant& v);

}

}

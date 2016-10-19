/*! \file objectwithownership.h

    Defines an object with ownership
 */
#pragma once
#include <QPair>
#include <QObject>
#include <QMetaType>

#include "valueownership.h"


namespace dukpp03
{

namespace qt
{

/*! A substitute type for object with ownership
 */
typedef QPair<QObject*, dukpp03::qt::ValueOwnership> ObjectWithOwnership;

}

}

Q_DECLARE_METATYPE(dukpp03::qt::ObjectWithOwnership)

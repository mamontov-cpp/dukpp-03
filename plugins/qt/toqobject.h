/** \file toqobject.h

    Converts QVariant to QObject, both in Qt4 and Qt5
 */
#pragma once
#include <QVariant>
#include <QObject>

namespace dukpp03
{

namespace qt
{

/*! Converts variant to QObject
    \param[in] v variant
    \return result or nullptr if cannot be casted
 */
QObject* toQObject(QVariant* v);

}

}

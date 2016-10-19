/*! \file registermetatype.h
 *
 *  A metatype registration file to solve an issues with old Qt code
 */
#pragma once

#include "isqobject.h"

#include <QMetaType>
#include <QString>

namespace dukpp03
{

namespace qt
{
/*! Checks, whether following meta type is pointer to qobject
    \param[in] name a type name
    \return true or false
 */
bool is_metatype_qobject(const QString& name);

/*! Registers qobject as descendant of current type
    \param[in] name a type name
 */
void register_qobject_descendant(const QString& name);

template<typename T>
void registerMetaType()
{
    if (dukpp03::qt::IsQObject<T>::Result) {
        qRegisterMetaType<T*>();
        int type = qMetaTypeId<T*>();
        register_qobject_descendant(QMetaType::typeName(type));
    }
}

}

}


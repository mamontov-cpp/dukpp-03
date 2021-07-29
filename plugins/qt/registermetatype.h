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


/*! Register meta type for specified type. This is common part, which just registers meta type
 */
template<bool IsQObject, typename T>
struct RegisterMetaType
{
public:
    /*! Performs actual type registration
     */
    inline static void perform()
    {
        qRegisterMetaType<T>();
        qRegisterMetaType<T*>();        
    }
};

/*! Register meta type for specified type. This is part for QObjects
 */
template<typename T>
struct RegisterMetaType<true, T>
{
public:
    /*! Performs actual type registration
     */
    inline static void perform()
    {
        qRegisterMetaType<T*>();
        const int type = qMetaTypeId<T*>();
#if ( QT_VERSION >= 0x060000 )
        register_qobject_descendant(QMetaType(type).name());
#else
        register_qobject_descendant(QMetaType::typeName(type));
#endif
    }
};

/*! Registers common data, needed for meta type
 */
template<typename T>
void registerMetaType()
{
    RegisterMetaType<static_cast<bool>(dukpp03::qt::IsQObject<T>::Value::Result), T>::perform();
}

}

}


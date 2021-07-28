/** \file isqobject.h

    Determiness, whether the specified object type is qobject
 */
#pragma once
#include <QObject>


namespace dukpp03
{

namespace qt
{

/*! A probe function to test, whether specified type is QObject
    or it's descendant.

    \param[in] v a value
    \return largets value
 */
static long long is_qobject(...);

/*! A probe function to test, whether specified type is QObject
    \param[in] v a value
    \return char as smallest value size
 */
static char is_qobject(QObject* v);

/*! A structure for defining meta result
 */
struct IsQObjectResult
{
    /*! A type that will determine "Yes" result
     */
    typedef char Yes;
    /*! A type, that will determine "No" result
     */
    typedef long long No;
};

/*! A main meta-function, that will determine, whether object is QObject
    or it's descendant.
 */
template<typename T>
struct IsQObject
{
    enum Value
    {
        Result = sizeof(dukpp03::qt::is_qobject(reinterpret_cast<T*>(NULL))) == sizeof(IsQObjectResult::Yes)
    };
};

}

}

/*! \file convert.h

    A basic converter, that tries to check is specified variant could be converted to type
 */
#pragma once
#include <QString>
#include <QVariant>

namespace dukpp03
{

namespace qt
{

struct Convert
{
    /*! Tests if we can convert from QVariant v
        \param[in] type a source type
        \param[in] v variant
        \return whether we can convert one value to another
     */
    static bool canConvert(const QString& type, const QVariant* v);

    /*! Test if we can convert from QVariant v to other type
        \param[in] type a type
        \param[in] v value
        \param[out] result if result
        \return true on success
     */
    static bool convert(const QString& type, const QVariant* v, QVariant& result);
};

}

}

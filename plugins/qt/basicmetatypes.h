/*! \file basicmetatypes.h

    A basic list of metatypes
 */
#pragma once
#include <QObject>
#include <QVariant>
#include <QMetaType>
#include <string>


#ifndef DUK_QT_NO_DECLARE_METATYPE_FOR_LONG_DOUBLE
    Q_DECLARE_METATYPE(long double)
#endif

#ifndef DUK_QT_NO_DECLARE_METATYPE_FOR_STD_STRING
    Q_DECLARE_METATYPE(std::string)
#endif

Q_DECLARE_METATYPE(QObject**)
Q_DECLARE_METATYPE(QVariant*)

/** \file getadressofcommontypeorqobject.h
 *
 * Describes a common compile-time function for getting adress of stored value
 */
#pragma once
#include "isqobject.h"

#include <QVariant>
#include <QMetaType>

namespace dukpp03
{

namespace qt
{

/*!
 * A compile-time function for getting address of value stored
 * in QVariant
 */
template<
    bool IsUnderlyingTypeAQObject,
    typename _UnderlyingValue
>
struct GetAddressOfCommonTypeOrQObject
{
    /*! For common case we just check if value contains requested type
        and cast data to type, where it's stored
        \param[in] v value
        \return where value is stored
     */
    static dukpp03::Maybe<_UnderlyingValue*> getAddress(QVariant* v)
    {
        if (v->type() == qMetaTypeId<_UnderlyingValue>())
        {
            return dukpp03::Maybe<_UnderlyingValue*>(static_cast<_UnderlyingValue*>(v->data()));
        }
        if (v->canConvert<_UnderlyingValue>())
        {
            return dukpp03::Maybe<_UnderlyingValue*>(static_cast<_UnderlyingValue*>(v->data()));            
        }
        return dukpp03::Maybe<_UnderlyingValue*>();
    }
};

/*!
 * This is specialization for case if QObject could be stored inside
 * of QVariant by value. Since, it's non-copyable we just return empty
 * maybe
 */
template<typename _UnderlyingValue>
struct GetAddressOfCommonTypeOrQObject<true, _UnderlyingValue>
{
    /*! QObject could not be stored by value into QVariant, so just
        return empty Maybe
        \param[in] v value
        \return empty maybe
     */
    static dukpp03::Maybe<_UnderlyingValue*> getAddress(QVariant* v)
    {
        return dukpp03::Maybe<_UnderlyingValue*>();
    }
};

}

}

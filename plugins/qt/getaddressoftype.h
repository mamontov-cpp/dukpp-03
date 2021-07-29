/*! \file getaddressoftype.h

    Get adress of type tries to get adresss of object, stored in QVariant
 */
#pragma once
#include "getadressofcommontypeorqobject.h"


namespace dukpp03
{

namespace qt
{

/*! In common case if plain value is requested (not a pointer),
    return empty maybe
 */
template<typename _UnderlyingValue>
struct GetAddressOfType
{
public:
    /*! Returns an empty maybe, since non-pointer value is requested
       \param[in] v value
       \return
     */
    static dukpp03::Maybe<_UnderlyingValue> getAddress(QVariant* v)
    {
        return dukpp03::Maybe<_UnderlyingValue>();
    }
};


/*! In case of valid request, we should rely on getting or QObject or
    a common type and behave accordingly
 */
template<typename _UnderlyingValue>
struct GetAddressOfType<_UnderlyingValue*>
{
public:
    /*! Returns an address of object or some other stuff if need to
        \param[in] v value
        \return result
     */
    static dukpp03::Maybe<_UnderlyingValue*> getAddress(QVariant* v)
    {
        return dukpp03::qt::GetAddressOfCommonTypeOrQObject<
                   static_cast<bool>(dukpp03::qt::IsQObject<_UnderlyingValue>::Value::Result),
                  _UnderlyingValue
               >::getAddress(v);
    }
};

/*! GetAddressOfType in this case can behave as self-identity function
 */
template<>
struct GetAddressOfType<QObject*>
{
public:
    /*! Returns a QObjec* if current object's type is QObject*
        \param[in] v value
        \return result
     */
    inline static dukpp03::Maybe<QObject*> getAddress(QVariant* v)
    {
        if (v->canConvert<QObject*>())
        {
            return v->value<QObject*>();
        }
        return {};
    }
};

}

}

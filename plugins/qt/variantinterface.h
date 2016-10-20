/*! \file variantinterface.h
    
    Defines a variant interface to be used with context
 */
#pragma once
#include <maybe.h>
#include "getaddressoftype.h"
#include "trygetpointertoqobjectdescendant.h"
#include <QVariant>
#include <QMetaType>
#include <QObject>

namespace dukpp03
{

namespace qt
{


class VariantInterface
{
public:
    typedef QVariant Variant;

    /*! Makes variant from value
        \param[in] val value
        \return new variant
     */
    template<
        typename _UnderlyingValue
    >
    static Variant* makeFrom(_UnderlyingValue val)
    {
        return new QVariant(QVariant::fromValue(val));
    }
    /*! Fetches underlying value from variant type
        \param[in] v a variant, containing data
        \return an underlying value
     */
    template<
        typename _UnderlyingValue
    >   
    static dukpp03::Maybe<_UnderlyingValue> get(Variant* v)
    {
        if (v->canConvert<_UnderlyingValue>())
        {
            return dukpp03::Maybe<_UnderlyingValue>(v->value<_UnderlyingValue>());
        }
        else
        {
            if (v->canConvert<QObject*>())
            {
                return dukpp03::qt::TryToGetPointerToQObjectDescendant<_UnderlyingValue>::perform(v->value<QObject*>());
            }
        }
        return dukpp03::Maybe<_UnderlyingValue>();
    }

    /*! Fetches underlying value adress from variant type
        \param[in] v a variant, containing data
        \return an underlying value
     */
    template<
        typename _UnderlyingValue
    >   
    static dukpp03::Maybe<_UnderlyingValue> getAddress(Variant* v)
    {
        return dukpp03::qt::GetAddressOfType<_UnderlyingValue>::getAddress(v);
    }
    /*! A typename interface for variant
     */
    template<
        typename _UnderlyingValue
    >
    class TypeName 
    {
    public:
        /*! Returns name of type 
            \return name of type
         */
        static std::string type()
        {
            return QMetaType::typeName(qMetaTypeId<_UnderlyingValue>());
        }
    };
};


}


}

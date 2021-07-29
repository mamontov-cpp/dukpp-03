/*! \file trygetpointertoqobjectdescendant.h

    Tries to get a pointer to QObject descendant
 */
#pragma once
#include <isqobject.h>
#include <QVariant>

namespace dukpp03
{

namespace qt
{

/*! Depending on first parameters try to cast this object to it's descendant
   or returns plain value. Note, that this part only returns empty value
 */
template<bool _IsQObjectDescendant, typename _UnderlyingValue>
struct CheckAndTryToGetPointerToQObjectDescendant
{
    /*! Returns empty maybe
        \param[in] v value
        \return empty maybe
     */
    static dukpp03::Maybe<_UnderlyingValue*> perform(QObject* v)
    {
        return dukpp03::Maybe<_UnderlyingValue*>();
    }
};

/*! Depending on first parameters try to cast this object to it's descendant
    or returns plain value.

    This part performs actual check for types
 */
template<typename _UnderlyingValue>
struct CheckAndTryToGetPointerToQObjectDescendant<true, _UnderlyingValue>
{
    /*! Returns a value if QObjects has the same type as needed
        \param[in] v value
        \return empty maybe
     */
    static dukpp03::Maybe<_UnderlyingValue*> perform(QObject* v)
    {
        QString requiredType = _UnderlyingValue::staticMetaObject.className();
        QString passedType = v->metaObject()->className();
        if (requiredType == passedType)
        {
             return dukpp03::Maybe<_UnderlyingValue*>(static_cast<_UnderlyingValue*>(v));
        }
        return dukpp03::Maybe<_UnderlyingValue*>();
    }
};


/*!
 * Performs autoconversion via dynamic cast to a QObject*
 * descendant when QVariant fails it, like in Qt4.
 *
 * By a default returns empty maybe, as plain types is not supported
 */
template<typename _UnderlyingValue>
struct TryToGetPointerToQObjectDescendant
{
    /*! Returns empty maybe
        \param[in] v value
        \return empty maybe
     */
    static dukpp03::Maybe<_UnderlyingValue> perform(QObject* v)
    {
        return dukpp03::Maybe<_UnderlyingValue>();
    }
};


/*!
 * Performs autoconversion via dynamic cast to a QObject*
 * descendant when QVariant fails it, like in Qt4.
 *
 * By a default returns empty maybe, as plain types is not supported
 */
template<typename _UnderlyingValue>
struct TryToGetPointerToQObjectDescendant<_UnderlyingValue*>
{
    /*! Returns empty maybe
        \param[in] v value
        \return empty maybe
     */
    static dukpp03::Maybe<_UnderlyingValue*> perform(QObject* v)
    {
        return dukpp03::qt::CheckAndTryToGetPointerToQObjectDescendant<
            static_cast<bool>(dukpp03::qt::IsQObject<_UnderlyingValue>::Value::Result),
            _UnderlyingValue
        >::perform(v);
    }
};

}

}

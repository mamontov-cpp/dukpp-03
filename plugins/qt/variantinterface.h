/*! \file variantinterface.h
    
    Defines a variant interface to be used with context
 */
#pragma once
#include <maybe.h>
#include <QVariant>
#include <QMetaType>

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
        return new QVariant(val);
    }
	/*! Makes new variant from qobject
	    \param[in] val a value
		\return new variant
	 */
	inline static Variant* makeFrom(QObject* val)
    {
	    QVariant* result = new QVariant();
		result->setValue(val);
		return result;
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
        return dukpp03::Maybe<_UnderlyingValue>();
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
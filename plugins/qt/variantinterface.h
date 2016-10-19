/*! \file variantinterface.h
    
    Defines a variant interface to be used with context
 */
#pragma once
#include <maybe.h>
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


    template<
        typename _UnderlyingValue   
    >
    struct MakeFrom
    {
        static Variant* makeFrom(_UnderlyingValue val)
        {
            return new QVariant(val);
        }       
    };

    template<
        typename _UnderlyingValue   
    >
    struct MakeFrom<_UnderlyingValue*>
    {
        static Variant* makeFrom(_UnderlyingValue* val)
        {
            QVariant* result = new QVariant();
            result->setValue(val);
            return result;
        }       
    };
    
    /*! Makes variant from value
        \param[in] val value
        \return new variant
     */
    template<
        typename _UnderlyingValue
    >
    static Variant* makeFrom(_UnderlyingValue val)
    {
        return MakeFrom<_UnderlyingValue>::makeFrom(val);
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
    
   template<typename _UnderlyingValue>
    struct GetAddress
    {
    public: 
        static dukpp03::Maybe<_UnderlyingValue> getAddress(Variant* v)
        {
            return dukpp03::Maybe<_UnderlyingValue>();
        };
    };
    

    static char is_qobject(QObject* v);
    template<typename T>
    static long long is_qobject(T* v);


    template<bool, typename _UnderlyingValue>
    struct GetAddress2
    {
        static dukpp03::Maybe<_UnderlyingValue*> getAddress(Variant* v)
        {
            if (v->type() == qMetaTypeId<_UnderlyingValue>())
            {
                return dukpp03::Maybe<_UnderlyingValue*>(reinterpret_cast<_UnderlyingValue*>(v->data()));
            }
            return dukpp03::Maybe<_UnderlyingValue*>();
        };
    };

    template<typename _UnderlyingValue>
    struct GetAddress2<true, _UnderlyingValue>
    {
        static dukpp03::Maybe<_UnderlyingValue*> getAddress(Variant* v)
        {
            return dukpp03::Maybe<_UnderlyingValue*>();
        };
    };


    template<typename _UnderlyingValue>
    struct GetAddress<_UnderlyingValue*>
    {
    public: 

        static dukpp03::Maybe<_UnderlyingValue*> getAddress(Variant* v)
        {
            return GetAddress2<sizeof(is_qobject(reinterpret_cast<_UnderlyingValue*>(NULL))) == sizeof(long long), _UnderlyingValue>::getAddress(v);
        };
    };

    template<>
    struct GetAddress<QObject*>
    {
    public: 
        inline static dukpp03::Maybe<QObject*> getAddress(Variant* v)
        {
            if (v->canConvert<QObject*>())
            {
                return v->value<QObject*>();
            }
            return dukpp03::Maybe<QObject*>();
        };
    };

    /*! Fetches underlying value adress from variant type
        \param[in] v a variant, containing data
        \return an underlying value
     */
    template<
        typename _UnderlyingValue
    >   
    static dukpp03::Maybe<_UnderlyingValue> getAddress(Variant* v)
    {
        return GetAddress<_UnderlyingValue>::getAddress(v);
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
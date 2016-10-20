#include "convert.h"
#include "basicmetatypes.h"
#include "registermetatype.h"

#include <QHash>
#include <QMutex>
#include <iostream>

// A simple sets to perform checks
static QString doubleTypes = "float|double|long double";
static QString intTypes = "short|unsigned short|int|unsigned int|long|unsigned long|long long|unsigned long long";


template<typename _To, typename _From>
static QVariant convert(QVariant* v)
{
    return QVariant::fromValue(static_cast<_To>(v->value<_From>()));
}

typedef QVariant (*Converter)(QVariant*);

static QHash<int, QHash<int, Converter> > converters;
static QMutex mtx;

template<typename _To, typename _From>
static void insertConverterToList()
{
    int to = qMetaTypeId<_To>();
    int from = qMetaTypeId<_From>();
    if (converters.contains(to) == false)
    {
        converters.insert(to, QHash<int, Converter>());
    }
    converters[to].insert(from, convert<_To, _From>);
    if (converters.contains(from) == false)
    {
        converters.insert(from, QHash<int, Converter>());
    }
    converters[from].insert(to, convert<_From, _To>);
}

static void initConverters()
{
    mtx.lock();
    if (converters.size() == 0)
    {
        insertConverterToList<float, short>();
        insertConverterToList<float, unsigned short>();
        insertConverterToList<float, int>();
        insertConverterToList<float, unsigned int>();
        insertConverterToList<float, long>();
        insertConverterToList<float, unsigned long>();
        insertConverterToList<float, long long>();
        insertConverterToList<float, unsigned long long>();

        insertConverterToList<double, short>();
        insertConverterToList<double, unsigned short>();
        insertConverterToList<double, int>();
        insertConverterToList<double, unsigned int>();
        insertConverterToList<double, long>();
        insertConverterToList<double, unsigned long>();
        insertConverterToList<double, long long>();
        insertConverterToList<double, unsigned long long>();

        insertConverterToList<long double, short>();
        insertConverterToList<long double, unsigned short>();
        insertConverterToList<long double, int>();
        insertConverterToList<long double, unsigned int>();
        insertConverterToList<long double, long>();
        insertConverterToList<long double, unsigned long>();
        insertConverterToList<long double, long long>();
        insertConverterToList<long double, unsigned long long>();
    }
    mtx.unlock();
}


static Converter getConverter(const QString& destType, const QString& sourceType)
{
    initConverters();
    int destTypeId = QMetaType::type(destType.toStdString().c_str());
    int sourceTypeId = QMetaType::type(sourceType.toStdString().c_str());
    Converter result = NULL;
    mtx.lock();
    if (converters.contains(destTypeId))
    {
        if (converters[destTypeId].contains(sourceTypeId))
        {
            result = converters[destTypeId][sourceTypeId];
        }
    }
    mtx.unlock();
    return result;
}

#if HAS_QT5
    #define UNKNOWN_TYPE QMetaType::UnknownType
#else
    #define UNKNOWN_TYPE QMetaType::Void
#endif

bool dukpp03::qt::Convert::canConvert(const QString& type, const QVariant* v)
{
    QVariant copy = *v;
    QVariant::Type destType = QVariant::nameToType(type.toStdString().c_str());
    QString typeName = copy.typeName();
    if (copy.type() != destType)
    {
        // If we can convert type easily, do it
        if (copy.canConvert(destType))
        {
            return true;
        }

        // If we want a T* -> QObject*, and it's applicable
        if ((type == "QObject*") && dukpp03::qt::is_metatype_qobject(typeName))
        {
            return true;
        }
        // If we want a (QObject*)(T*) -> T* and it's applicable
        if (dukpp03::qt::is_metatype_qobject(type) && copy.canConvert<QObject*>())
        {
            QObject* dest = copy.value<QObject*>();
            if (dest)
            {
                QString className = dest->metaObject()->className();
                className.append("*");
                if (type == className && QMetaType::type(className.toStdString().c_str()) != UNKNOWN_TYPE)
                {
                    return true;
                }
            }
        }
        // If QString -> std::string
        if (type == "std::string" && typeName == "QString")
        {
            return true;
        }

        // std::string -> QString
        if (type == "QString" && typeName == "std::string")
        {
            return true;
        }

        // If we have a plain converter
        if (getConverter(type, typeName))
        {
            return true;
        }

        return false;
    }

    return true;
}

bool dukpp03::qt::Convert::convert(const QString& type, const QVariant* v, QVariant& result)
{
    result = *v;
    QVariant::Type destType = QVariant::nameToType(type.toStdString().c_str());
    QString typeName = result.typeName();

    if (result.type() != destType)
    {
        // If we can convert type easily, do it
        if (result.canConvert(destType))
        {
            result.convert(destType);
            return true;
        }

        // If we want a T* -> QObject*, and it's applicable
        if ((type == "QObject*") && dukpp03::qt::is_metatype_qobject(typeName))
        {
            result = QVariant::fromValue(*reinterpret_cast<QObject**>(const_cast<void*>(v->data())));
            return true;
        }
        // If we want a (QObject*)(T*) -> T* and it's applicable
        if (dukpp03::qt::is_metatype_qobject(type) && result.canConvert<QObject*>())
        {
            QObject* dest = result.value<QObject*>();
            if (dest)
            {
                QString className = dest->metaObject()->className();
                className.append("*");
                int typeId =  QMetaType::type(className.toStdString().c_str());
                if (type == className && typeId != UNKNOWN_TYPE)
                {
                    result = QVariant(typeId, &dest);
                    return true;
                }
            }
        }
        // If QString -> std::string
        if (type == "std::string" && typeName == "QString")
        {
            result = QVariant::fromValue(result.toString().toStdString());
            return true;
        }

        // std::string -> QString
        if (type == "QString" && typeName == "std::string")
        {
            result = QVariant::fromValue(QString(result.value<std::string>().c_str()));
            return true;
        }

        // If we have a plain converter
        Converter cvt = getConverter(type, typeName);
        if (cvt)
        {
            result = cvt(&result);
            return true;
        }

        return false;
    }

    return true;
}

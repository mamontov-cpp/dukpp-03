#include "convert.h"
#include "basicmetatypes.h"
#include "registermetatype.h"
#include "basiccontext.h"

#include <QHash>
#include <QMutex>
// ReSharper disable once CppUnusedIncludeDirective
#include <iostream>


template<typename _To, typename _From>
static QVariant convert(QVariant* v)
{
    return QVariant::fromValue(static_cast<_To>(v->value<_From>()));
}

typedef QVariant (*Converter)(QVariant*);

/**
 * \brief list of converters
 */
static QHash<int, QHash<int, Converter> > converters;  // NOLINT(clang-diagnostic-exit-time-destructors)
/**
 * \brief global init mutex
 */
static QMutex mtx;  // NOLINT(clang-diagnostic-exit-time-destructors)

template<typename _To, typename _From>
static void insertConverterToList()
{
	const int to = qMetaTypeId<_To>();
	const int from = qMetaTypeId<_From>();
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
    if (converters.empty())
    {
        // Weird issue with Qt 4 - char -> char fails
        insertConverterToList<char, char>();
        insertConverterToList<char, unsigned char>();
        insertConverterToList<unsigned char, unsigned char>();

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
        insertConverterToList<long double, double>();
        insertConverterToList<long double, float>();

        insertConverterToList<short, short>();
        insertConverterToList<short, unsigned short>();
        insertConverterToList<short, int>();
        insertConverterToList<short, unsigned int>();
        insertConverterToList<short, long>();
        insertConverterToList<short, unsigned long>();
        insertConverterToList<short, long long>();
        insertConverterToList<short, unsigned long long>();

        insertConverterToList<unsigned short, unsigned short>();
        insertConverterToList<unsigned short, int>();
        insertConverterToList<unsigned short, unsigned int>();
        insertConverterToList<unsigned short, long>();
        insertConverterToList<unsigned short, unsigned long>();
        insertConverterToList<unsigned short, long long>();
        insertConverterToList<unsigned short, unsigned long long>();

        insertConverterToList<int, unsigned int>();
        insertConverterToList<int, long>();
        insertConverterToList<int, unsigned long>();
        insertConverterToList<int, long long>();
        insertConverterToList<int, unsigned long long>();

        insertConverterToList<unsigned int, long>();
        insertConverterToList<unsigned int, unsigned long>();
        insertConverterToList<unsigned int, long long>();
        insertConverterToList<unsigned int, unsigned long long>();

        insertConverterToList<long, unsigned long>();
        insertConverterToList<long, long long>();
        insertConverterToList<long, unsigned long long>();

        insertConverterToList<unsigned long, long long>();
        insertConverterToList<unsigned long, unsigned long>();
        insertConverterToList<unsigned long, unsigned long long>();

        insertConverterToList<float, float>();
        insertConverterToList<double, double>();
        insertConverterToList<long double, long double>();

        insertConverterToList<float, double>();
        insertConverterToList<float, long double>();
        insertConverterToList<double, long double>();

        insertConverterToList<long long, unsigned long long>();
    }
    mtx.unlock();
}


static Converter getConverter(const QString& destType, const QString& sourceType)
{
    initConverters();
#if HAS_QT6
    const int destTypeId = QMetaType::fromName(destType.toStdString().c_str()).id();
    const int sourceTypeId = QMetaType::fromName(sourceType.toStdString().c_str()).id();
#else
    const int destTypeId = QMetaType::type(destType.toStdString().c_str());
    const int sourceTypeId = QMetaType::type(sourceType.toStdString().c_str());
#endif
    Converter result = nullptr;
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
	const QVariant copy = *v;
#if HAS_QT6
    const int destType = QMetaType::fromName(type.toStdString().c_str()).id();
#else
    const int destType = QMetaType::type(type.toStdString().c_str());
#endif
#if HAS_QT6
    const int destType2 = QMetaType::fromName(type.toStdString().c_str()).id();
#else
    const QVariant::Type destType2 = QVariant::nameToType(type.toStdString().c_str());
#endif
    const QString typeName = copy.typeName();

#if HAS_QT6
    if (copy.metaType().id() != destType)
#else
    #if HAS_QT5
        if (copy.type() != destType)
    #else
        if (typeName != type.toStdString().c_str()) // Better use string typing, because of invalid types
    #endif
#endif
    {

        // If we have a plain converter
        if (getConverter(type, typeName))
        {
            return true;
        }

        // If we can convert type easily, do it
#if HAS_QT6
        if (copy.canConvert(QMetaType(destType2)))
#else
        if (copy.canConvert(destType2))
#endif
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
            auto* const dest = copy.value<QObject*>();
            if (dest)
            {
                QString className = dest->metaObject()->className();
                className.append("*");
#if HAS_QT6
                const int classNameType = QMetaType::fromName(className.toStdString().c_str()).id();
#else
                const int classNameType = QMetaType::type(className.toStdString().c_str());
#endif
                if (type == className && classNameType  != UNKNOWN_TYPE)
                {
                    return true;
                }
            }
        }
        // If QString -> std::string
        if ((type == "std::string" ||  type == "std::basic_string<char,std::char_traits<char>,std::allocator<char>>") && typeName == "QString")
        {
            return true;
        }

        // std::string -> QString
        if (type == "QString" && (typeName == "std::string" || typeName == "std::basic_string<char,std::char_traits<char>,std::allocator<char>>"))
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
#if  HAS_QT6
    const int destType = QMetaType::fromName(type.toStdString().c_str()).id();
    const int destType2 = QMetaType::fromName(type.toStdString().c_str()).id();
#else
    int destType = QMetaType::type(type.toStdString().c_str());
    const QVariant::Type destType2 =  QVariant::nameToType(type.toStdString().c_str());
#endif
    const QString typeName = result.typeName();
#if HAS_QT6
    if (v->metaType().id() != destType)
#else
    #if HAS_QT5
        if (v->type() != destType)
    #else
        if (typeName != type.toStdString().c_str()) // Better use string typing, because of invalid types
    #endif
#endif
    {
        // If we have a plain converter
        const Converter cvt = getConverter(type, typeName);
        if (cvt)
        {
            result = cvt(&result);
            return true;
        }

        // If we can convert type easily, do it
#if HAS_QT6
        if (result.canConvert(QMetaType(destType2)))
        {
            result.convert(QMetaType(destType2));
            return true;
        }
#else
        if (result.canConvert(destType2))
        {
            result.convert(destType2);
            return true;
        }
#endif
        // If we want a T* -> QObject*, and it's applicable
        if ((type == "QObject*") && dukpp03::qt::is_metatype_qobject(typeName))
        {
            result = QVariant::fromValue(*static_cast<QObject**>(const_cast<void*>(v->data())));
            return true;
        }
        // If we want a (QObject*)(T*) -> T* and it's applicable
        if (dukpp03::qt::is_metatype_qobject(type) && result.canConvert<QObject*>())
        {
            auto* dest = result.value<QObject*>();
            if (dest)
            {
                QString className = dest->metaObject()->className();
                className.append("*");
#if HAS_QT6
                const int typeId = QMetaType::fromName(className.toStdString().c_str()).id();
#else
                const int typeId = QMetaType::type(className.toStdString().c_str());
#endif
                if (type == className && typeId != UNKNOWN_TYPE)
                {
#if HAS_QT6
                    result = QVariant(QMetaType(typeId), &dest);
#else
                    result = QVariant(typeId, &dest);
#endif                    
                    return true;
                }
            }
        }
        // If QString -> std::string
        if ((type == "std::string" ||  type == "std::basic_string<char,std::char_traits<char>,std::allocator<char>>") && typeName == "QString")
        {
            result = QVariant::fromValue(result.toString().toStdString());
            return true;
        }

        // std::string -> QString
        if (type == "QString" && (typeName == "std::string" || typeName == "std::basic_string<char,std::char_traits<char>,std::allocator<char>>"))
        {
            result = QVariant::fromValue(QString(result.value<std::string>().c_str()));
            return true;
        }
       
        return false;
    }

    return true;
}

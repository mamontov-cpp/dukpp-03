#include "context.h"
#include "dukqt.h"
#include <QMetaType>
#include <QVariantList>

/*! A meta method property for storing index
 */
#define DUK_QT_METAMETHOD_INDEX_PROPERTY "\1_____meta_method_index\1"

/*! A meta method property for storing typename
 */
#define DUK_QT_METAMETHOD_TYPENAME_PROPERTY "\1_____meta_method_typename\1"

/*! A meta method property for storing signature property
 */
#define DUK_QT_METAMETHOD_SIGNATURE_PROPERTY "\1_____meta_method_signature\1"

dukpp03::qt::Context::Context()
{
#if HAS_QT5
    #define UNKNOWN_TYPE QMetaType::UnknownType
#else
    #define UNKNOWN_TYPE QMetaType::Void
#endif
#define REGISTER_METATYPE(TYPE)                                    \
    if (QMetaType::type(#TYPE) == UNKNOWN_TYPE)          \
    {                                                              \
        qRegisterMetaType< DUKPP03_TYPE(TYPE) >(#TYPE);            \
    }
    REGISTER_METATYPE(float)
    REGISTER_METATYPE(double)
    REGISTER_METATYPE(long double)
    REGISTER_METATYPE(std::string)
    REGISTER_METATYPE(dukpp03::qt::ObjectWithOwnership)
    if (QMetaType::type("QPair<QObject*, dukpp03::qt::ValueOwnership>") == UNKNOWN_TYPE)
    {
        qRegisterMetaType<QPair<QObject*, dukpp03::qt::ValueOwnership> >("QPair<QObject*, dukpp03::qt::ValueOwnership>");
    }

}

dukpp03::qt::Context::~Context()
{
    
}

void dukpp03::qt::Context::pushObject(QObject* o, dukpp03::qt::ValueOwnership p)
{
    dukpp03::PushValue<dukpp03::qt::ObjectWithOwnership, dukpp03::qt::BasicContext>::perform(this, dukpp03::qt::ObjectWithOwnership(o, p));
}


void dukpp03::qt::Context::registerGlobal(const QString& name, QObject* o, dukpp03::qt::ValueOwnership p)
{
    duk_push_global_object(m_context);
    pushObject(o, p);
    duk_put_prop_string(m_context, -2, name.toStdString().c_str());
    duk_pop(m_context);
}

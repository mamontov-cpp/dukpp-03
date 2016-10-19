#include "wrapvalue.h"
#include "context.h"
#include "toqobject.h"
#include <iostream>

void dukpp03::qt::WrapValue::perform(void* context, void* variant)
{
    dukpp03::qt::Context* ctx = reinterpret_cast<dukpp03::qt::Context*>(context);
    QVariant* v = reinterpret_cast<QVariant*>(variant);
    QObject* o = dukpp03::qt::toQObject(v);
    if (o)
    {
        const QMetaObject* mo = o->metaObject();
        for(int i = mo->methodOffset(); i < mo->methodCount(); i++)
        {
            QMetaMethod m = mo->method(i);
            if (m.access() == QMetaMethod::Public && 
                (m.methodType() == QMetaMethod::Slot  || m.methodType() == QMetaMethod::Method))
            {
                ctx->pushMetaMethod(i, m);
#if HAS_QT5
                duk_put_prop_string(ctx->context(), -2, m.name());
#else
                QString name = m.signature();
                int index = name.indexOf('(');
                name = name.mid(0, index);
                duk_put_prop_string(ctx->context(), -2, name.toStdString().c_str());
#endif
            }
        }
    }
}

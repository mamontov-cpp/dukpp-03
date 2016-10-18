#include "wrapvalue.h"
#include "context.h"

void dukpp03::qt::WrapValue::perform(void* context, void* variant)
{
    dukpp03::qt::Context* ctx = reinterpret_cast<dukpp03::qt::Context*>(context);
    QVariant* v = reinterpret_cast<QVariant*>(variant);
    if (v->canConvert<QObject*>())
    {
        QObject* o = v->value<QObject*>();
        const QMetaObject* mo = o->metaObject();
        for(int i = mo->methodOffset(); i < mo->methodCount(); i++)
        {
            QMetaMethod m = mo->method(i);
            if (m.access() == QMetaMethod::Public && 
                (m.methodType() == QMetaMethod::Slot  || m.methodType() == QMetaMethod::Method))
            {
                ctx->pushMetaMethod(i, m);
                duk_put_prop_string(ctx->context(), -2, m.name());
            }
        }
    }
}
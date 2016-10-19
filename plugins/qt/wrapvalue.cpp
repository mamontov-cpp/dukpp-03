#include "wrapvalue.h"
#include "context.h"
#include "toqobject.h"
#include "classbinding.h"
#include "getvalue.h"
#include "pushvalue.h"

void dukpp03::qt::WrapValue::perform(void* context, void* variant)
{
    dukpp03::qt::Context* ctx = reinterpret_cast<dukpp03::qt::Context*>(context);
    QVariant* v = reinterpret_cast<QVariant*>(variant);
    QObject* o = dukpp03::qt::toQObject(v);
    if (o)
    {
        const QMetaObject* mo = o->metaObject();
        if (ctx->getClassBinding(mo->className()) == NULL) 
        {
            QString bindingName = mo->className();
            bindingName.append("*");

            dukpp03::qt::ClassBinding* binding = new dukpp03::qt::ClassBinding();
            binding->registerMetaObject(mo, false);
            binding->wrapValue(ctx);
            ctx->addClassBinding(bindingName.toStdString(), binding);
        }
    }
}

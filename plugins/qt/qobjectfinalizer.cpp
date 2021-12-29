#include "qobjectfinalizer.h"
#include <QVariant>
#include "getvalue.h"
#include "pushvalue.h"
#include "toqobject.h"
#include "convert.h"

duk_ret_t dukpp03::qt::qobjectfinalizer(duk_context* ctx)
{
    QVariant* v = dukpp03::Finalizer<dukpp03::qt::BasicContext>::getVariantToFinalize(ctx);
    dukpp03::qt::BasicContext* parent  = static_cast<dukpp03::qt::BasicContext*>(dukpp03::AbstractContext::getContext(ctx));
    if (v)
    {
        if (parent->isVariantRegistered(v))
        {
            QVariant result;
            if (dukpp03::qt::Convert::convert("QObject*", v, result))
            {
                delete result.value<QObject*>();
            }
            parent->unregisterVariant(v);
            delete v;
        }
    }
    return 0;
}

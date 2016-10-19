#include "qobjectfinalizer.h"
#include <QVariant>
#include "getvalue.h"
#include "pushvalue.h"
#include "toqobject.h"

duk_ret_t dukpp03::qt::qobjectfinalizer(duk_context* ctx)
{
    QVariant* v = dukpp03::Finalizer<dukpp03::qt::BasicContext>::getVariantToFinalize(ctx);
    if (v)
    {
        QObject* o = dukpp03::qt::toQObject(v);
        if (o)
        {
            delete o;
        }
        delete v;
    }
    return 0;
}

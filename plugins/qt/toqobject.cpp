#include "toqobject.h"
#include "registermetatype.h"

QObject* dukpp03::qt::toQObject(QVariant* v)
{
    if (!v)
    {
        return nullptr;
    }
    QObject* o = qvariant_cast<QObject*>(*v);
    if (!o)
    {
        if (dukpp03::qt::is_metatype_qobject(v->typeName()))
        {
            o = *static_cast<QObject**>(v->data());
        }
    }
    return o;
}

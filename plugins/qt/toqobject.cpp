#include "toqobject.h"
#include "registermetatype.h"

QObject* dukpp03::qt::toQObject(QVariant* v)
{
    if (!v)
    {
        return NULL;
    }
    QObject* o = qvariant_cast<QObject*>(*v);
    if (!o)
    {
        if (dukpp03::qt::is_metatype_qobject(v->typeName()))
        {
            o = *reinterpret_cast<QObject**>(v->data());
        }
    }
    return o;
}

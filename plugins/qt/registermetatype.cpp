#include "registermetatype.h"
#include <QSet>
#include <QMutex>

static QMutex mtx;
static QSet<QString> descendants;

bool dukpp03::qt::is_metatype_qobject(const QString& name)
{
    return descendants.contains(name);
}

void dukpp03::qt::register_qobject_descendant(const QString& name)
{
    descendants.insert(name);
}

#include "classbinding.h"
#include "metamethod.h"
#include "getvalue.h"
#include "pushvalue.h"

#include <QMetaMethod>

dukpp03::qt::ClassBinding::ClassBinding()
{
    
}

dukpp03::qt::ClassBinding::~ClassBinding()
{
    
}

// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
void dukpp03::qt::ClassBinding::registerMetaObject(const QMetaObject* mo, bool register_constructors)
{
    for(int i = mo->methodOffset(); i < mo->methodCount(); i++)
    {
        QMetaMethod m = mo->method(i);
        if (m.access() == QMetaMethod::Public && 
            (m.methodType() == QMetaMethod::Slot  || m.methodType() == QMetaMethod::Method))
        {
            this->addMethod(dukpp03::qt::MetaMethod::name(m).toStdString(), new dukpp03::qt::MetaMethod(i, m));
        }
    }
}
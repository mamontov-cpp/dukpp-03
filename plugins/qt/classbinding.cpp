#include "classbinding.h"
#include "metaconstructor.h"
#include "metamethod.h"
#include "metapropertyaccessor.h"
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
    int i;
    if (register_constructors)
    {
        for(i = 0; i < mo->constructorCount(); i++)
        {
            QMetaMethod m = mo->constructor(i);
            if (m.access() == QMetaMethod::Public && m.methodType() == QMetaMethod::Constructor) 
            {
                this->addConstructor(mo->className(), new dukpp03::qt::MetaConstructor(mo, m));
            }
        }
    }
    for(i = mo->methodOffset(); i < mo->methodCount(); i++)
    {
        QMetaMethod m = mo->method(i);
        if (m.access() == QMetaMethod::Public && 
            (m.methodType() == QMetaMethod::Slot  || m.methodType() == QMetaMethod::Method))
        {
            this->addMethod(dukpp03::qt::MetaMethod::name(m).toStdString(), new dukpp03::qt::MetaMethod(i, m));
        }
    }
    for(i = mo->propertyOffset(); i < mo->propertyCount(); i++)
    {
        dukpp03::Callable<dukpp03::qt::BasicContext>* getter = NULL;
        dukpp03::Callable<dukpp03::qt::BasicContext>* setter = NULL;
        QMetaProperty prop = mo->property(i);
        if (prop.isReadable())
        {
            getter = new dukpp03::qt::MetaPropertyAccessor(i, prop, dukpp03::qt::MetaPropertyAccessor::MPAM_Get);
        }
        if (prop.isWritable())
        {
            setter = new dukpp03::qt::MetaPropertyAccessor(i, prop, dukpp03::qt::MetaPropertyAccessor::MPAM_Set);
        }
        if (getter || setter)
        {
            this->addAccessor(prop.name(), getter, setter);
        }
    }
}

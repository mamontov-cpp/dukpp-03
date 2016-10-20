#include "metapropertyaccessor.h"

#include "convert.h"
#include "getvalue.h"
#include "pushvalue.h"


// =============================== PUBLIC METHODS ===============================

dukpp03::qt::MetaPropertyAccessor::MetaPropertyAccessor(
    int index,
    const QMetaProperty& m,
    dukpp03::qt::MetaPropertyAccessor::Mode mode
) : m_index(index), m_property(m), m_mode(mode)
{

}

dukpp03::qt::MetaPropertyAccessor::~MetaPropertyAccessor()
{

}


dukpp03::Callable<dukpp03::qt::BasicContext>* dukpp03::qt::MetaPropertyAccessor::clone()
{
    return new dukpp03::qt::MetaPropertyAccessor(m_index, m_property, m_mode);
}

int dukpp03::qt::MetaPropertyAccessor::requiredArguments()
{
    return (m_mode == dukpp03::qt::MetaPropertyAccessor::MPAM_Set) ? 1 : 0;
}

std::pair<int, bool> dukpp03::qt::MetaPropertyAccessor::canBeCalled(dukpp03::qt::BasicContext* c)
{
    if (c->getTop() != this->requiredArguments())
    {
        return std::make_pair(-1, false);
    }
    int matchedargs = 0;
    QObject* obj = this->checkThis(c);
    if (obj)
    {
        matchedargs += 1;
        if (m_mode == dukpp03::qt::MetaPropertyAccessor::MPAM_Set)
        {
            dukpp03::Maybe<QVariant> tmp = dukpp03::GetValue<QVariant, dukpp03::qt::BasicContext>::perform(c, 0);
            if (tmp.exists())
            {
                QVariant arg = tmp.value();
                QString methodTypeName = m_property.typeName();

                if (dukpp03::qt::Convert::canConvert(methodTypeName, &arg))
                {
                    matchedargs += 1;
                }
            }
        }
    }

    return std::make_pair(matchedargs, matchedargs == (this->requiredArguments() + 1));
}

bool dukpp03::qt::MetaPropertyAccessor::canBeCalledAsConstructor()
{
    return false;
}

int dukpp03::qt::MetaPropertyAccessor::_call(dukpp03::qt::BasicContext* c)
{
    QObject* obj = this->checkThis(c);
    if (!obj)
    {
        c->throwInvalidTypeForThisError("QObject*");
        return 0;
    }

    if (m_mode == dukpp03::qt::MetaPropertyAccessor::MPAM_Set)
    {
        dukpp03::Maybe<QVariant> tmp = dukpp03::GetValue<QVariant, dukpp03::qt::BasicContext>::perform(c, 0);
        if (tmp.exists())
        {
            QVariant arg = tmp.value();
            QString propTypeName = m_property.typeName();
            QString argTypeName = arg.typeName();

            bool ok = false;
            if (dukpp03::qt::Convert::canConvert(propTypeName, &arg))
            {
                 QVariant parg;
                 if (dukpp03::qt::Convert::convert(propTypeName, &arg, parg))
                 {
                     ok = true;
                     m_property.write(obj, parg);
                 }
            }

            if (!ok)
            {
                QString error;
                error     = "Cannot convert ";
                error     += argTypeName;
                error     += " to ";
                error     += propTypeName;
                c->throwError(error.toStdString());
                return 0;
            }
        }
        return 0;
    }
    else
    {
        QVariant returnValue = m_property.read(obj);
        dukpp03::qt::pushVariant(c, returnValue);
        return 1;
    }
    return 0;
}

// =============================== PROTECTED METHODS ===============================

QObject* dukpp03::qt::MetaPropertyAccessor::checkThis(dukpp03::qt::BasicContext* c) const
{
    dukpp03::Maybe< QObject* > maybethisobject;

    dukpp03::qt::Context::LocalCallable::CheckArgument< QObject* >::passedAsThis(c, maybethisobject);
    if (maybethisobject.exists())
    {
        QObject* thisobj  = maybethisobject.value();
        const QMetaObject* obj = thisobj->metaObject();
        if (m_index >= obj->propertyOffset() && m_index < obj->propertyCount())
        {
            QMetaProperty prop = obj->property(m_index);
            if (QString(prop.typeName()) == QString(m_property.typeName()))
            {
                return thisobj;
            }
        }
    }
    return NULL;
}

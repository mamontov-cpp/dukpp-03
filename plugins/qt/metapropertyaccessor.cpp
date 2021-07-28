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
= default;


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
    int matched_arguments = 0;
    QObject* obj = this->checkThis(c);
    if (obj)
    {
        matched_arguments += 1;
        if (m_mode == dukpp03::qt::MetaPropertyAccessor::MPAM_Set)
        {
	        const dukpp03::Maybe<QVariant> tmp = dukpp03::GetValue<QVariant, dukpp03::qt::BasicContext>::perform(c, 0);
            if (tmp.exists())
            {
                QVariant arg = tmp.value();
                const QString method_type_name = m_property.typeName();

                if (dukpp03::qt::Convert::canConvert(method_type_name, &arg))
                {
                    matched_arguments += 1;
                }
            }
        }
    }

    return std::make_pair(matched_arguments, matched_arguments == (this->requiredArguments() + 1));
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
                 QVariant parent_variant;
                 if (dukpp03::qt::Convert::convert(propTypeName, &arg, parent_variant))
                 {
                     ok = true;
                     m_property.write(obj, parent_variant);
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
    dukpp03::Maybe< QObject* > maybe_this_object;

    dukpp03::qt::Context::LocalCallable::CheckArgument< QObject* >::passedAsThis(c, maybe_this_object);
    if (maybe_this_object.exists())
    {
        QObject* this_object  = maybe_this_object.value();
        const QMetaObject* obj = this_object->metaObject();
        if (m_index >= obj->propertyOffset() && m_index < obj->propertyCount())
        {
            QMetaProperty property = obj->property(m_index);
            if (QString(property.typeName()) == QString(m_property.typeName()))
            {
                return this_object;
            }
        }
    }
    return nullptr;
}

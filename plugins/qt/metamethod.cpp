#include "metamethod.h"
#include "context.h"
#include "convert.h"
#include "getvalue.h"
#include "pushvalue.h"

// =============================== PUBLIC METHODS ===============================

dukpp03::qt::MetaMethod::MetaMethod(int index, const QMetaMethod& m) : m_index(index), m_method(m)
{
   
}

dukpp03::qt::MetaMethod::~MetaMethod()
= default;


dukpp03::Callable<dukpp03::qt::BasicContext>* dukpp03::qt::MetaMethod::clone()
{
    return new dukpp03::qt::MetaMethod(m_index, m_method);
}

int dukpp03::qt::MetaMethod::requiredArguments()
{
    return m_method.parameterTypes().size();  // NOLINT(clang-diagnostic-shorten-64-to-32)
}

std::pair<int, bool> dukpp03::qt::MetaMethod::canBeCalled(dukpp03::qt::BasicContext* c)
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
        QVariantList lst;
        if (dukpp03::qt::MetaMethod::stackToVariantList(c, lst))
        {
	        const QList<QByteArray> method_types = m_method.parameterTypes();
            for (int i = 0; i < method_types.size(); i++) 
            {
                const QVariant& arg = lst.at(i);

                const  QByteArray& method_type_name = method_types.at(i);
        
                if (dukpp03::qt::Convert::canConvert(method_type_name, &arg))
                {                    
                    matched_arguments += 1;
                }
            }
        }
    }

    return std::make_pair(matched_arguments, matched_arguments == (this->requiredArguments() + 1));
}

bool dukpp03::qt::MetaMethod::canBeCalledAsConstructor()
{
    return false;
}

// Taken from https://gist.github.com/andref/2838534
static QVariant metamethod_call(
	QObject* object, 
	QMetaMethod metaMethod, 
	const QVariantList& variant_list_arguments, 
	QString* error
)
{
    // Convert the arguments
    QVariantList converted;

    // We need enough arguments to perform the conversion.

    const QList<QByteArray> method_types = metaMethod.parameterTypes();
    if (method_types.size() < variant_list_arguments.size()) 
    {

        *error = "Insufficient arguments to call "; 
#if HAS_QT5
        *error += metaMethod.methodSignature();
#else
        *error += metaMethod.signature();
#endif
        return QVariant();
    }

    for (int i = 0; i < method_types.size(); i++) 
    {
        const QVariant& arg = variant_list_arguments.at(i);

        const QByteArray& method_type_name = method_types.at(i);
        const QByteArray argument_type_name = arg.typeName();
#if !HAS_QT6
        QVariant::Type method_type = QVariant::nameToType(method_type_name);
        // ReSharper disable once CppEntityNeverUsed
        QVariant::Type arg_type = arg.type();
#endif
        QVariant copy = QVariant(arg);

        // If the types are not the same, attempt a conversion. If it
        // fails, we cannot proceed.

        if (!dukpp03::qt::Convert::convert(method_type_name, &arg, copy)) {
            *error     = "Cannot convert ";
            *error     += argument_type_name;
            *error     += " to ";
            *error     += method_type_name;
            return QVariant();
        }

        converted << copy;
    }    

    QList<QGenericArgument> arguments;

    for (auto& argument : converted)
    {

        // Notice that we have to take a reference to the argument, else 
        // we'd be pointing to a copy that will be destroyed when this
        // loop exits. 

        // A const_cast is needed because calling data() would detach
        // the QVariant.

#if HAS_QT6
        QGenericArgument genericArgument(
            QMetaType(argument.userType()).name(),
            const_cast<void*>(argument.constData())
        );
#else
        QGenericArgument genericArgument(
            QMetaType::typeName(argument.userType()),
            const_cast<void*>(argument.constData())
        );
#endif

        arguments << genericArgument;
    }

    const QString returnType = metaMethod.typeName();
    QVariant returnValue;
    if (returnType.length() && (returnType != "void"))
    {
#if HAS_QT6
        returnValue = QVariant(QMetaType::fromName(metaMethod.typeName()), 
                               static_cast<void*>(nullptr));
#else
        returnValue = QVariant(QMetaType::type(metaMethod.typeName()), static_cast<void*>(nullptr));
#endif
    }

    const QGenericReturnArgument returnArgument(
        metaMethod.typeName(),
        const_cast<void*>(returnValue.constData())
    );

    // Perform the call

    const bool ok = metaMethod.invoke(
        object,
        Qt::DirectConnection,
        returnArgument,
        arguments.value(0),
        arguments.value(1),
        arguments.value(2),
        arguments.value(3),
        arguments.value(4),
        arguments.value(5),
        arguments.value(6),
        arguments.value(7),
        arguments.value(8),
        arguments.value(9)
    );

    if (!ok) {
        *error = "Calling ";
#if HAS_QT5
        *error += metaMethod.methodSignature();
#else
        *error += metaMethod.signature();
#endif
        *error  = " failed.";
        return QVariant();
    } else {
        return returnValue;
    }
}

int dukpp03::qt::MetaMethod::_call(dukpp03::qt::BasicContext* c)
{
    QObject* obj = this->checkThis(c);
    if (!obj)
    {
        c->throwInvalidTypeForThisError("QObject*");
        return 0;
    }

    QVariantList lst;
    if (dukpp03::qt::MetaMethod::stackToVariantList(c, lst))
    {
	    const QString typeName = m_method.typeName();
        QString call_error;
	    const QVariant returnValue = metamethod_call(obj, m_method, lst, &call_error);
        // If error occurred, throw it
        if (call_error.length())
        {
            c->throwError(call_error.toStdString());
            return 0;
        }
        // If method doesn't return anything, return it
        if (typeName.length() == 0)
        {
            return 0;
        }
                                                
        dukpp03::PushValue<QVariant, dukpp03::qt::BasicContext>::perform(c, returnValue);
        return 1; 
    }    
    c->throwError("Invalid types supplied for a call");    
    return 0;
}

QString dukpp03::qt::MetaMethod::name(QMetaMethod method)
{
#if HAS_QT5
    return method.name();
#else
    QString name = method.signature();
    int index = name.indexOf('(');
    name = name.mid(0, index);
    return QString(name.toStdString().c_str());
#endif
}

// =============================== PROTECTED METHODS ===============================

QObject* dukpp03::qt::MetaMethod::checkThis(dukpp03::qt::BasicContext* c) const
{
    dukpp03::Maybe< QObject* > maybe_this_object; 
    
    dukpp03::qt::Context::LocalCallable::CheckArgument< QObject* >::passedAsThis(c, maybe_this_object);
    if (maybe_this_object.exists())
    {
        QObject* this_obj  = maybe_this_object.value();
        const QMetaObject* obj = this_obj->metaObject();
        if (m_index >= obj->methodOffset() && m_index < obj->methodCount())
        {
	        const QMetaMethod method = obj->method(m_index);
#if HAS_QT5
	        const QString signature = method.methodSignature();
	        const QString sourceSignature = m_method.methodSignature();
#else
            QString signature = method.signature();
            QString sourceSignature = method.signature();
#endif
            if (QString(method.typeName()) == QString(m_method.typeName()) && sourceSignature == signature)
            {
                return this_obj;
            }
        }
    }
    return nullptr;
}

bool dukpp03::qt::MetaMethod::stackToVariantList(dukpp03::qt::BasicContext* c, QVariantList& list)
{
    bool error = false;
    for(::size_t i = 0; i < c->getTop(); i++)
    {
        dukpp03::Maybe<QVariant> tmp = dukpp03::GetValue<QVariant, dukpp03::qt::BasicContext>::perform(c, i);
        if (tmp.exists())
        {
            list << tmp.value();
        }
        else
        {
            error = true;
        }
    }
    return !error;
}

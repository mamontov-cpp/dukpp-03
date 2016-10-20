#include "metamethod.h"
#include "context.h"
#include "getvalue.h"
#include "pushvalue.h"

// =============================== PUBLIC METHODS ===============================

dukpp03::qt::MetaMethod::MetaMethod(int index, const QMetaMethod& m) : m_index(index), m_method(m)
{
    
}

dukpp03::qt::MetaMethod::~MetaMethod()
{
    
}


dukpp03::Callable<dukpp03::qt::BasicContext>* dukpp03::qt::MetaMethod::clone()
{
    return new dukpp03::qt::MetaMethod(m_index, m_method);
}

int dukpp03::qt::MetaMethod::requiredArguments()
{
    return m_method.parameterTypes().size();
}

std::pair<int, bool> dukpp03::qt::MetaMethod::canBeCalled(dukpp03::qt::BasicContext* c)
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
        QVariantList lst;
        if (dukpp03::qt::MetaMethod::stackToVariantList(c, lst))
        {
            QList<QByteArray> methodTypes = m_method.parameterTypes();
            for (int i = 0; i < methodTypes.size(); i++) 
            {
                const QVariant& arg = lst.at(i);
        
                QByteArray methodTypeName = methodTypes.at(i);
                QByteArray argTypeName = arg.typeName();

                QVariant::Type methodType = QVariant::nameToType(methodTypeName);
                // ReSharper disable once CppEntityNeverUsed
                QVariant::Type argType = arg.type();
        
                QVariant copy = QVariant(arg);
                if (copy.type() != methodType) 
                {
                    bool qobject_castable = false;
                    if ((QString(methodTypeName).toStdString() == "QObject*") && dukpp03::qt::is_metatype_qobject(argTypeName))
                    {
                        qobject_castable = true;
                    }
                    if (copy.canConvert(methodType) || qobject_castable) 
                    {
                        matchedargs += 1;
                    }
                }
            }
        }
    }

    return std::make_pair(matchedargs, matchedargs == (this->requiredArguments() + 1));
}

bool dukpp03::qt::MetaMethod::canBeCalledAsConstructor()
{
    return false;
}

// Taken from https://gist.github.com/andref/2838534
static QVariant metamethod_call(QObject* object, QMetaMethod metaMethod, QVariantList args, QString* error)
{
    // Convert the arguments
    QVariantList converted;

    // We need enough arguments to perform the conversion.

    QList<QByteArray> methodTypes = metaMethod.parameterTypes();
    if (methodTypes.size() < args.size()) 
    {

        *error = "Insufficient arguments to call "; 
#if HAS_QT5
        *error += metaMethod.methodSignature();
#else
        *error += metaMethod.signature();
#endif
        return QVariant();
    }

    for (int i = 0; i < methodTypes.size(); i++) 
    {
        const QVariant& arg = args.at(i);
        
        QByteArray methodTypeName = methodTypes.at(i);
        QByteArray argTypeName = arg.typeName();

        QVariant::Type methodType = QVariant::nameToType(methodTypeName);
        // ReSharper disable once CppEntityNeverUsed
        QVariant::Type argType = arg.type();
        
        QVariant copy = QVariant(arg);

        // If the types are not the same, attempt a conversion. If it
        // fails, we cannot proceed.

        if (copy.type() != methodType) {
            if (copy.canConvert(methodType)) {
                bool qobject_castable = false;
                if ((QString(methodTypeName).toStdString() == "QObject*") && dukpp03::qt::is_metatype_qobject(argTypeName))
                {
                    qobject_castable = true;
                }
                if (!copy.convert(methodType)) {
                    if (qobject_castable)
                    {
                        copy = QVariant::fromValue(dukpp03::qt::toQObject(&copy));
                    } 
                    else
                    {
                        *error     = "Cannot convert ";
                        *error     += argTypeName;
                        *error     += " to ";
                        *error     += methodTypeName;
                        return QVariant();
                    }
                }
            }
        }

        converted << copy;
    }    

    QList<QGenericArgument> arguments;

    for (int i = 0; i < converted.size(); i++) 
    {

        // Notice that we have to take a reference to the argument, else 
        // we'd be pointing to a copy that will be destroyed when this
        // loop exits. 

        QVariant& argument = converted[i];

        // A const_cast is needed because calling data() would detach
        // the QVariant.

        QGenericArgument genericArgument(
            QMetaType::typeName(argument.userType()),
            const_cast<void*>(argument.constData())
        );

        arguments << genericArgument;
    }

    QString returnType = metaMethod.typeName();
    QVariant returnValue;
    if (returnType.length() && (returnType != "void"))
    {
        returnValue = QVariant(QMetaType::type(metaMethod.typeName()), 
                               static_cast<void*>(NULL));
    }

    QGenericReturnArgument returnArgument(
        metaMethod.typeName(),
        const_cast<void*>(returnValue.constData())
    );

    // Perform the call

    bool ok = metaMethod.invoke(
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
        QString typeName = m_method.typeName();
        QString callerror;
        QVariant returnValue = metamethod_call(obj, m_method, lst, &callerror);
        // If error occured, throw it
        if (callerror.length())
        {
            c->throwError(callerror.toStdString());
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
    dukpp03::Maybe< QObject* > maybethisobject; 
    
    dukpp03::qt::Context::LocalCallable::CheckArgument< QObject* >::passedAsThis(c, maybethisobject);
    if (maybethisobject.exists())
    {
        QObject* thisobj  = maybethisobject.value();
        const QMetaObject* obj = thisobj->metaObject();
        if (m_index >= obj->methodOffset() && m_index < obj->methodCount())
        {
            QMetaMethod method = obj->method(m_index);
#if HAS_QT5
            QString signature = method.methodSignature();
            QString sourceSignature = m_method.methodSignature();
#else
            QString signature = method.signature();
            QString sourceSignature = method.signature();
#endif
            if (QString(method.typeName()) == QString(m_method.typeName()) && sourceSignature == signature)
            {
                return thisobj;
            }
        }
    }
    return NULL;
}

bool dukpp03::qt::MetaMethod::stackToVariantList(dukpp03::qt::BasicContext* c, QVariantList& list)
{
    bool error = false;
    for(size_t i = 0; i < c->getTop(); i++)
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

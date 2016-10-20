#include "metaconstructor.h"
#include "metamethod.h"
#include "getvalue.h"
#include "pushvalue.h"


// =============================== PUBLIC METHODS ===============================

dukpp03::qt::MetaConstructor::MetaConstructor(const QMetaObject* mo, const QMetaMethod& m) 
: m_meta_object(mo), m_method(m)
{
    
}

dukpp03::qt::MetaConstructor::~MetaConstructor()
{
    
}


dukpp03::Callable<dukpp03::qt::BasicContext>* dukpp03::qt::MetaConstructor::clone()
{
    return new dukpp03::qt::MetaConstructor(m_meta_object, m_method);
}

int dukpp03::qt::MetaConstructor::requiredArguments()
{
    return m_method.parameterTypes().size();
}

std::pair<int, bool> dukpp03::qt::MetaConstructor::canBeCalled(dukpp03::qt::BasicContext* c)
{
    if (c->getTop() != this->requiredArguments())
    {
        return std::make_pair(-1, false);
    }
    int matchedargs = 0;
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

    return std::make_pair(matchedargs, matchedargs == this->requiredArguments());
}

bool dukpp03::qt::MetaConstructor::canBeCalledAsFunction()
{
    return false;
}

// Taken from https://gist.github.com/andref/2838534
static QObject* metaconstructor_call(const QMetaObject* metaObject, QMetaMethod metaMethod, QVariantList args, QString* error)
{
    // Convert the arguments
    QVariantList converted;

    // We need enough arguments to perform the conversion.

    QList<QByteArray> methodTypes = metaMethod.parameterTypes();
    if (methodTypes.size() < args.size()) {

        *error = "Insufficient arguments to call "; 
#if HAS_QT5
        *error += metaMethod.methodSignature();
#else
        *error += metaMethod.signature();
#endif
        return NULL;
    }

    for (int i = 0; i < methodTypes.size(); i++) {
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
                        return NULL;
                    }
                }
            }
        }

        converted << copy;
    }    

    QList<QGenericArgument> arguments;

    for (int i = 0; i < converted.size(); i++) {

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

    // Perform the call
    QObject* o = metaObject->newInstance(
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

    if (!o) {
        *error = "Calling ";
#if HAS_QT5
        *error += metaMethod.methodSignature();
#else
        *error += metaMethod.signature();
#endif
        *error  = " failed.";
        return NULL;
    } else {
        return o;
    }
}

int dukpp03::qt::MetaConstructor::_call(dukpp03::qt::BasicContext* c)
{
    QVariantList lst;
    if (dukpp03::qt::MetaMethod::stackToVariantList(c, lst))
    {
        QString typeName = m_method.typeName();
        QString callerror;
        QObject* returnValue = metaconstructor_call(m_meta_object, m_method, lst, &callerror);
        // If error occured, throw it
        if (callerror.length())
        {
            c->throwError(callerror.toStdString());
            return 0;
        }
                                                        
        dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(c, returnValue);
        return 1; 
    }    
    c->throwError("Invalid types supplied for a call");    
    return 0;
}

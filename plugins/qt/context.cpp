#include "context.h"
#include <QMetaType>
#include <QVariantList>

/*! A meta method property for storing index
 */
#define DUK_QT_METAMETHOD_INDEX_PROPERTY "\1_____meta_method_index\1"

/*! A meta method property for storing typename
 */
#define DUK_QT_METAMETHOD_TYPENAME_PROPERTY "\1_____meta_method_typename\1"

/*! A meta method property for storing signature property
 */
#define DUK_QT_METAMETHOD_SIGNATURE_PROPERTY "\1_____meta_method_signature\1"

#define HAS_QT5  ( QT_VERSION >= 0x050000 )

dukpp03::qt::Context::Context()
{
#define REGISTER_METATYPE(TYPE)                                    \
	if (QMetaType::type(#TYPE) == QMetaType::UnknownType)          \
	{                                                              \
	    qRegisterMetaType< DUKPP03_TYPE(TYPE) >(#TYPE);            \
	}
	REGISTER_METATYPE(long double)
	REGISTER_METATYPE(std::string)
	REGISTER_METATYPE(dukpp03::qt::ObjectWithOwnership)
	if (QMetaType::type("QPair<QObject*, dukpp03::qt::ValueOwnership>") == QMetaType::UnknownType)
	{
		qRegisterMetaType<QPair<QObject*, dukpp03::qt::ValueOwnership> >("QPair<QObject*, dukpp03::qt::ValueOwnership>");
	}
}

dukpp03::qt::Context::~Context()
{
	
}

// Taken from https://gist.github.com/andref/2838534
static QVariant metamethod_call(QObject* object, QMetaMethod metaMethod, QVariantList args, QString* error)
{
    // Convert the arguments
    QVariantList converted;

    // We need enough arguments to perform the conversion.

    QList<QByteArray> methodTypes = metaMethod.parameterTypes();
    if (methodTypes.size() < args.size()) {

        *error = "Insufficient arguments to call "; 
#ifdef HAS_QT5
    	*error += metaMethod.methodSignature();
#else
    	*error += metaMethod.signature();
#endif
        return QVariant();
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
                if (!copy.convert(methodType)) {
                    *error     = "Cannot convert ";
                	*error     += argTypeName;
                    *error     += " to ";
                	*error     += methodTypeName;
                    return QVariant();
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

    QVariant returnValue(QMetaType::type(metaMethod.typeName()), 
        static_cast<void*>(NULL));

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
#ifdef HAS_QT5
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


static int dukqt_metamethod_call(duk_context *ctx) {
    duk_push_current_function(ctx);
    
	duk_get_prop_string(ctx, -1, DUK_QT_METAMETHOD_INDEX_PROPERTY);
    int index = duk_to_int(ctx, -1);
    duk_pop(ctx);

	duk_get_prop_string(ctx, -1, DUK_QT_METAMETHOD_TYPENAME_PROPERTY);
    QString typeName = duk_to_string(ctx, -1);
    duk_pop(ctx);

	duk_get_prop_string(ctx, -1, DUK_QT_METAMETHOD_SIGNATURE_PROPERTY);
    QString sourceSignature = duk_to_string(ctx, -1);
    duk_pop(ctx);

    duk_pop(ctx);


	dukpp03::Maybe< QObject* > maybethisobject; 
	dukpp03::qt::Context* c = reinterpret_cast<dukpp03::qt::Context*>(dukpp03::qt::Context::getContext(ctx));
	if (duk_is_constructor_call(ctx))
	{
		c->throwFunctionCallShouldNotBeCalledAsConstructor();
		return 0;
	}

	dukpp03::qt::Context::LocalCallable::CheckArgument< QObject* >::passedAsThis(c, maybethisobject);
	if (maybethisobject.exists())
	{
		QObject* thisobj  = maybethisobject.value();
		const QMetaObject* obj = thisobj->metaObject();
		bool error = true;
		if (index >= obj->methodOffset() && index < (obj->methodOffset() + obj->methodCount()))
		{
			QMetaMethod method = obj->method(index);
			QString signature;
#ifdef HAS_QT5
			signature = method.methodSignature();
#else
			signature = method.signature();
#endif
			if (method.typeName() == typeName && sourceSignature == signature)
			{
				error = false;
				QVariantList variants;
				for(size_t i = 0; i < c->getTop(); i++)
				{
					dukpp03::Maybe<QVariant> tmp = dukpp03::GetValue<QVariant, dukpp03::qt::Context>::perform(c, i);
					if (tmp.exists())
					{
						variants << tmp.value();
					}
					else
					{
						error = true;
					}
				}
				if (!error)
				{
					QString callerror;
					QVariant returnValue = metamethod_call(thisobj, method, variants, &callerror);
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
						
						
					dukpp03::PushValue<QVariant, dukpp03::qt::Context>::perform(c, returnValue);
					return 1;											
				}
				// If we reaches this point, then some attempt to construct type has failed
				c->throwError("Attempt to call a method on invalid arguments");									
			}
		}
		if (error)
		{
			c->throwError("Attempt to call non-existing method");
		}
	}
	else 
	{
		c->throwError("Cannot call a meta method: object passed as this is not an instance of QObject*");
	}
	return 0;
}


void dukpp03::qt::Context::pushMetaMethod(int index, const QMetaMethod& meta_method) const
{
    duk_push_c_function(m_context, dukqt_metamethod_call, meta_method.parameterTypes().size());
   
	duk_push_string(m_context, DUK_QT_METAMETHOD_INDEX_PROPERTY);   
	duk_push_int(m_context, index);
	duk_def_prop(m_context, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | 0);

	duk_push_string(m_context, DUK_QT_METAMETHOD_TYPENAME_PROPERTY);   
	duk_push_string(m_context, meta_method.typeName());
	duk_def_prop(m_context, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | 0);

	duk_push_string(m_context, DUK_QT_METAMETHOD_SIGNATURE_PROPERTY);   
#ifdef HAS_QT5
	duk_push_string(m_context, meta_method.methodSignature());
#else
	duk_push_string(m_context, meta_method.signature());
#endif
	duk_def_prop(m_context, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | 0);
}

void dukpp03::qt::Context::pushObject(QObject* o, dukpp03::qt::ValueOwnership p)
{
	dukpp03::PushValue<dukpp03::qt::ObjectWithOwnership, dukpp03::qt::BasicContext>::perform(this, dukpp03::qt::ObjectWithOwnership(o, p));
}


void dukpp03::qt::Context::registerGlobal(const QString& name, QObject* o, dukpp03::qt::ValueOwnership p)
{
	duk_push_global_object(m_context);
	pushObject(o, p);
	duk_put_prop_string(m_context, -2, name.toStdString().c_str());
	duk_pop(m_context);
}
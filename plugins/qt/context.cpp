#include "context.h"
#include <QMetaType>

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
	// Provice global finalizer functions to garbage collect and finalize QObjects
	duk_push_global_object(m_context);
	duk_push_string(m_context, "deleteQObject");
	duk_push_c_function(m_context, dukpp03::qt::qobjectfinalizer, 1);
	duk_def_prop(m_context, -2, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | 0);
	duk_pop(m_context); 
}

dukpp03::qt::Context::~Context()
{
	
}

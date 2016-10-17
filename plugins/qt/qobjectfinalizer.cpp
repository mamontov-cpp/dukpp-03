#include "qobjectfinalizer.h"
#include <qvariant.h>

duk_ret_t dukpp03::qt::qobjectfinalizer(duk_context* ctx)
{
	QVariant* v = dukpp03::Finalizer<dukpp03::qt::BasicContext>::getVariantToFinalize(ctx);
	if (v)
	{
		if (v->canConvert<QObject*>())
		{
			delete v->value<QObject*>();
		}
		delete v;
	}
	return 0;
}

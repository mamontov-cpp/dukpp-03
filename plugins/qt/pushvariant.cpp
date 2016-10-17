#include "pushvariant.h"
#include "context.h"

void dukpp03::qt::pushVariant(dukpp03::qt::BasicContext* ctx, const QVariant& v)
{
#define  DUK_IF_PUSH(TYPE)   if (v.typeName() == #TYPE) {  dukpp03::PushValue< DUKPP03_TYPE(TYPE), dukpp03::qt::BasicContext>::perform(ctx, v.value<DUKPP03_TYPE(TYPE)>()); return;  }
        DUK_IF_PUSH(bool)
        DUK_IF_PUSH(char)
        DUK_IF_PUSH(unsigned char)
        DUK_IF_PUSH(short)
        DUK_IF_PUSH(unsigned short)
        DUK_IF_PUSH(int)
        DUK_IF_PUSH(unsigned int)
        DUK_IF_PUSH(long)
        DUK_IF_PUSH(unsigned long)
        DUK_IF_PUSH(long long)
        DUK_IF_PUSH(unsigned long long)
        DUK_IF_PUSH(float)
        DUK_IF_PUSH(double)
        DUK_IF_PUSH(long double)
        DUK_IF_PUSH(std::string)
        DUK_IF_PUSH(QString)
#undef DUK_IF_PUSH
        if (v.typeName() != NULL)
        {
			if (v.canConvert<dukpp03::qt::ObjectWithOwnership>())
			{
				dukpp03::PushValue<dukpp03::qt::ObjectWithOwnership, dukpp03::qt::BasicContext>::perform(ctx, v.value<dukpp03::qt::ObjectWithOwnership>());
			}
			else 
			{  
				ctx->pushUntypedVariant(v.typeName(), new QVariant(v), dukpp03::qt::qobjectfinalizer);
			}
        }
        else
        {
            duk_push_undefined(ctx->context());
        }
}

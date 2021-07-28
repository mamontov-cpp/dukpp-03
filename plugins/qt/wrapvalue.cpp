#include "wrapvalue.h"
#include "context.h"
#include "toqobject.h"
#include "classbinding.h"
#include "getvalue.h"
#include "pushvalue.h"

void dukpp03::qt::WrapValue::perform(void* context, void* variant, bool wrapped)
{
    if (!wrapped)
    {
        dukpp03::qt::Context* ctx = static_cast<dukpp03::qt::Context*>(context);
        auto* v = static_cast<QVariant*>(variant);
        QObject* o = dukpp03::qt::toQObject(v);

        if (o)
        {
            const QMetaObject* mo = o->metaObject();
            const std::string class_name = mo->className();
            std::string ptr_class_name = class_name;
            ptr_class_name.append("*");
            dukpp03::ClassBinding<dukpp03::qt::BasicContext>* ctx_binding = ctx->getClassBinding(ptr_class_name);
            if (ctx_binding == nullptr)
            {
                ctx_binding = ctx->getClassBinding(class_name);                
            }
            if (ctx_binding == nullptr) 
            {
                QString bindingName = mo->className();
                bindingName.append("*");

                auto* binding = new dukpp03::qt::ClassBinding();
                binding->registerMetaObject(mo, false);
                binding->wrapValue(ctx);
                wrapped = true;
                ctx->addClassBinding(bindingName.toStdString(), binding);
            }
            else
            {
                wrapped = true;
                ctx_binding->wrapValue(ctx);                
            }
        }


        if (!wrapped)
        {
            std::string type_name = v->typeName();
            dukpp03::ClassBinding<dukpp03::qt::BasicContext>* ctx_binding = ctx->getClassBinding(type_name);
            if (ctx_binding)
            {
                ctx_binding->wrapValue(ctx);
            }
            else
            {
                if (type_name.length())
                {
                    if (type_name[type_name.length() - 1] == '*')
                    {
	                    const std::string type_name_no_ptr = type_name.substr(0, type_name.length() - 1);
                        ctx_binding = ctx->getClassBinding(type_name_no_ptr);
                        if (ctx_binding)
                        {
                            ctx_binding->wrapValue(ctx);
                        }
                    }
                }
            }
        }
    }    
}

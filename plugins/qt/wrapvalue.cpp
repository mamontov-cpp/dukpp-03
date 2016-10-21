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
        dukpp03::qt::Context* ctx = reinterpret_cast<dukpp03::qt::Context*>(context);
        QVariant* v = reinterpret_cast<QVariant*>(variant);
        QObject* o = dukpp03::qt::toQObject(v);

        if (o)
        {
            const QMetaObject* mo = o->metaObject();
            std::string classname = mo->className();
            std::string ptrclassname = classname;
            ptrclassname.append("*");
            dukpp03::ClassBinding<dukpp03::qt::BasicContext>* ctxbinding = ctx->getClassBinding(ptrclassname);
            if (ctxbinding == NULL)
            {
                ctxbinding = ctx->getClassBinding(classname);                
            }
            if (ctxbinding == NULL) 
            {
                QString bindingName = mo->className();
                bindingName.append("*");

                dukpp03::qt::ClassBinding* binding = new dukpp03::qt::ClassBinding();
                binding->registerMetaObject(mo, false);
                binding->wrapValue(ctx);
                wrapped = true;
                ctx->addClassBinding(bindingName.toStdString(), binding);
            }
            else
            {
                wrapped = true;
                ctxbinding->wrapValue(ctx);                
            }
        }


        if (!wrapped)
        {
            std::string type_name = v->typeName();
            dukpp03::ClassBinding<dukpp03::qt::BasicContext>* ctxbinding = ctx->getClassBinding(type_name);
            if (ctxbinding)
            {
                ctxbinding->wrapValue(ctx);
            }
            else
            {
                if (type_name.length())
                {
                    if (type_name[type_name.length() - 1] == '*')
                    {
                        std::string type_name_no_ptr = type_name.substr(0, type_name.length() - 1);
                        ctxbinding = ctx->getClassBinding(type_name_no_ptr);
                        if (ctxbinding)
                        {
                            ctxbinding->wrapValue(ctx);
                        }
                    }
                }
            }
        }
    }    
}

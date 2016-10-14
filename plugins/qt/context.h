/*! \file context.h

    A context to be used with Qt
 */
#pragma once 
#include "../../include/dukpp-03.h"
#include "variantinterface.h"
#include "mapinterface.h"
#include "timerinterface.h"

namespace dukpp03
{

namespace qt
{
/*! A main context to be used with qt
 */
typedef dukpp03::Context<dukpp03::qt::MapInterface, dukpp03::qt::VariantInterface, dukpp03::qt::TimerInterface> Context;


}


template<>
class GetValue<QVariant, dukpp03::qt::Context>
{
public:
/*! Performs getting value from stack 
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
inline static dukpp03::Maybe<QVariant> perform(
    dukpp03::qt::Context* ctx, 
    duk_idx_t pos
)
{
    dukpp03::Maybe<QVariant> result;
    if (duk_is_string(ctx->context(), pos))
    {
        result.setValue(QString(duk_to_string(ctx->context(), pos)));
    }
    if (duk_is_boolean(ctx->context(), pos))
    {
        result.setValue(static_cast<bool>(duk_to_string(ctx->context(), pos)));
    }
    if (duk_is_number(ctx->context(), pos))
    {
        result.setValue(duk_to_number(ctx->context(), pos));
    }
    if (duk_is_object(ctx->context(), pos))
    {
       duk_get_prop_string(ctx->context(), pos, DUKPP03_VARIANT_PROPERTY_SIGNATURE);
        if (duk_is_pointer(ctx->context(), -1))
        {
            void* ptr = duk_to_pointer(ctx->context(), -1);
            QVariant * v = reinterpret_cast<QVariant *>(ptr);
            if (v)
            {
                result.setValue(*v);
            }
        }
        duk_pop(ctx->context());
    }
    return result;
}

};

}
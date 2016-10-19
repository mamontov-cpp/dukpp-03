/*! \file getvalue.h
 *
 *
 *  Defines various specializations for getting values from stack
 */
#pragma once
#include "basiccontext.h"
#include "registermetatype.h"
#include "toqobject.h"
#include "objectwithownership.h"
#include "basicmetatypes.h"
#include "qobjectfinalizer.h"
#include "pushvariant.h"

namespace dukpp03
{


template<>
class GetValue<QObject*, dukpp03::qt::BasicContext>
{
public:
    /*! Performs getting value from stack
        \param[in] ctx context
        \param[in] pos index for stack
        \return a value if it exists, otherwise empty maybe
     */
    inline static dukpp03::Maybe<QObject*> perform(
        dukpp03::qt::BasicContext* ctx,
        duk_idx_t pos
    )
    {
        dukpp03::Maybe<QObject*> result;
        if (duk_is_object(ctx->context(), pos))
        {
            duk_get_prop_string(ctx->context(), pos, DUKPP03_VARIANT_PROPERTY_SIGNATURE);
            if (duk_is_pointer(ctx->context(), -1))
            {
                void* ptr = duk_to_pointer(ctx->context(), -1);
                QVariant * v = reinterpret_cast<QVariant *>(ptr);
                if (v)
                {
                    QObject* o = dukpp03::qt::toQObject(v);
                    if (o)
                    {
                        result.setValue(o);
                    }
                }
            }
            duk_pop(ctx->context());
        }
        return result;
    }
};


template<>
class GetValue<QString, dukpp03::qt::BasicContext>
{
public:
    /*! Performs getting value from stack
        \param[in] ctx context
        \param[in] pos index for stack
        \return a value if it exists, otherwise empty maybe
     */
    inline static dukpp03::Maybe<QString> perform(
        dukpp03::qt::BasicContext* ctx,
        duk_idx_t pos
    )
    {
        dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::qt::BasicContext>::perform(ctx, pos);
        if (result.exists())
        {
            return dukpp03::Maybe<QString>(QString(result.value().c_str()));
        }
        return dukpp03::Maybe<QString>();
    }
};

template<>
class GetValue<QVariant, dukpp03::qt::BasicContext>
{
public:
/*! Performs getting value from stack
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
inline static dukpp03::Maybe<QVariant> perform(
    dukpp03::qt::BasicContext* ctx,
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

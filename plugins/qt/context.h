/*! \file context.h

    A context to be used with Qt
 */
#pragma once 
#include "../../include/dukpp-03.h"
#include "variantinterface.h"
#include "mapinterface.h"
#include "timerinterface.h"


#ifndef DUK_QT_NO_DECLARE_METATYPE_FOR_LONG_DOUBLE
    Q_DECLARE_METATYPE(long double)
#endif

#ifndef DUK_QT_NO_DECLARE_METATYPE_FOR_STD_STRING
    Q_DECLARE_METATYPE(std::string)
#endif

namespace dukpp03
{

namespace qt
{
/*! A main context to be used with qt
 */
typedef dukpp03::Context<dukpp03::qt::MapInterface, dukpp03::qt::VariantInterface, dukpp03::qt::TimerInterface> Context;


}



template<>
class GetValue<QString, dukpp03::qt::Context>
{
public:
    /*! Performs getting value from stack 
        \param[in] ctx context
        \param[in] pos index for stack
        \return a value if it exists, otherwise empty maybe
     */
    inline static dukpp03::Maybe<QString> perform(
        dukpp03::qt::Context* ctx, 
        duk_idx_t pos
    )
    {
        dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::qt::Context>::perform(ctx, pos);
        if (result.exists())
        {
            return dukpp03::Maybe<QString>(QString(result.value().c_str()));
        }
        return dukpp03::Maybe<QString>();
    }
};

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


template<>
class PushValue<QString, dukpp03::qt::Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(dukpp03::qt::Context* ctx, const QString& v)
    {
        dukpp03::PushValue<std::string, dukpp03::qt::Context>::perform(ctx, v.toStdString());
    }
};

/*! Performs pushing value on stack for every type of value
 */
template<>
class PushValue<QVariant, dukpp03::qt::Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(dukpp03::qt::Context* ctx, const QVariant& v)
    { 
#define  DUK_IF_PUSH(TYPE)   if (v.typeName() == #TYPE) {  dukpp03::PushValue< DUKPP03_TYPE(TYPE), dukpp03::qt::Context>::perform(ctx, v.value<DUKPP03_TYPE(TYPE)>()); return;  }
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
            ctx->pushUntypedVariant(v.typeName(), new QVariant(v));
        }
        else
        {
            duk_push_undefined(ctx->context());
        }
    }
};

}
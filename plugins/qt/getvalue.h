/*! \file getvalue.h
 *
 *
 *  Defines various specializations for getting values from stack
 */
#pragma once
#include "basiccontext.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "registermetatype.h"
#include "toqobject.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "objectwithownership.h"
#include "basicmetatypes.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "qobjectfinalizer.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "pushvariant.h"

#include <QString>
#include <QVector>
#include <QList>
#include <QMap>
#include <QHash>

namespace dukpp03
{

template<
    template<
        typename Value
    > 
    class _LinearStructure,
    typename _ValueType,
    typename _Context
>
class GetLinearStructure
{
public:
     /*! Performs getting value from stack
        \param[in] c context
        \param[in] pos index for stack
        \param[out] result a result value
     */
    inline static void perform(
        _Context* c,
        duk_idx_t pos,
        dukpp03::Maybe<_LinearStructure<_ValueType> >& result
    )
    {
        result.clear();
        duk_context* ctx = c->context();
        if (duk_is_array(ctx, pos))
        {
            result.setValue(_LinearStructure<_ValueType>());        
            // ReSharper disable once CppInitializedValueIsAlwaysRewritten
            duk_size_t i = 0;
            const duk_size_t n = duk_get_length(ctx, pos);

            for (i = 0; i < n; i++) {
                duk_get_prop_index(ctx, pos, i);
                dukpp03::Maybe<_ValueType> val = dukpp03::GetValue<_ValueType, _Context>::perform(c, -1);
                if (val.exists())
                {
                    result.mutableValue().push_back(val.value());
                }
                else
                {
                    result.clear();
                    return;
                }
                duk_pop(ctx);
            }
        }
    }
};

template<
    template<
        typename Key,
        typename Value
    > 
    class _DictionaryStructure,
    typename _ValueType,
    typename _Context
>
class GetDictionaryStructure
{
public:
     /*! Performs getting value from stack
        \param[in] c context
        \param[in] pos index for stack
        \param[out] result a result value
     */
    inline static void perform(
        _Context* c,
        duk_idx_t pos,
        dukpp03::Maybe<_DictionaryStructure<QString, _ValueType> >& result
    )
    {
        result.clear();
        duk_context* ctx = c->context();
        if (duk_is_object(ctx, pos))
        {
            result.setValue(_DictionaryStructure<QString, _ValueType>());
            duk_enum(ctx, pos, DUK_ENUM_OWN_PROPERTIES_ONLY);

            while (duk_next(ctx, -1 /*enum_index*/, 1 /*get_value*/)) 
            {
                QString key = duk_get_string(ctx, -2);
                dukpp03::Maybe<_ValueType> val = dukpp03::GetValue<_ValueType, _Context>::perform(c, -1);
                if (val.exists())
                {
                    result.mutableValue().insert(key, val.value());
                }
                else
                {
                    result.clear();
                    return;
                }
                duk_pop(ctx);
                duk_pop(ctx);
            }            
        }
    }
};

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
                auto* v = static_cast<QVariant*>(ptr);
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
	    const dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::qt::BasicContext>::perform(ctx, pos);
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
            auto* v = static_cast<QVariant *>(ptr);
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

#if !HAS_QT6
template<typename T>
class GetValue<QVector<T>, dukpp03::qt::BasicContext>
{
public:
    /*! Performs getting value from stack
        \param[in] ctx context
        \param[in] pos index for stack
        \return a value if it exists, otherwise empty maybe
     */
    inline static dukpp03::Maybe<QVector<T> > perform(
        dukpp03::qt::BasicContext* ctx,
        duk_idx_t pos
    )
    {
        dukpp03::Maybe<QVector<T> > result;
        dukpp03::GetLinearStructure<QVector, T, dukpp03::qt::BasicContext>::perform(ctx, pos, result);
        return result;
    }
};
#endif

template<typename T>
class GetValue<QList<T>, dukpp03::qt::BasicContext>
{
public:
    /*! Performs getting value from stack
        \param[in] ctx context
        \param[in] pos index for stack
        \return a value if it exists, otherwise empty maybe
     */
    inline static dukpp03::Maybe<QList<T> > perform(
        dukpp03::qt::BasicContext* ctx,
        duk_idx_t pos
    )
    {
        dukpp03::Maybe<QList<T> > result;
        dukpp03::GetLinearStructure<QList, T, dukpp03::qt::BasicContext>::perform(ctx, pos, result);
        return result;
    }
};

template<typename T>
class GetValue<QHash<QString, T>, dukpp03::qt::BasicContext>
{
public:
    /*! Performs getting value from stack
        \param[in] ctx context
        \param[in] pos index for stack
        \return a value if it exists, otherwise empty maybe
     */
    inline static dukpp03::Maybe<QHash<QString, T> > perform(
        dukpp03::qt::BasicContext* ctx,
        duk_idx_t pos
    )
    {
        dukpp03::Maybe<QHash<QString, T> > result;
        dukpp03::GetDictionaryStructure<QHash, T, dukpp03::qt::BasicContext>::perform(ctx, pos, result);
        return result;
    }
};

template<typename T>
class GetValue<QMap<QString, T>, dukpp03::qt::BasicContext>
{
public:
    /*! Performs getting value from stack
        \param[in] ctx context
        \param[in] pos index for stack
        \return a value if it exists, otherwise empty maybe
     */
    inline static dukpp03::Maybe<QMap<QString, T> > perform(
        dukpp03::qt::BasicContext* ctx,
        duk_idx_t pos
    )
    {
        dukpp03::Maybe<QMap<QString, T> > result;
        dukpp03::GetDictionaryStructure<QMap, T, dukpp03::qt::BasicContext>::perform(ctx, pos, result);
        return result;
    }
};

}

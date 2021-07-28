/*! \file pushvalue.h
 *
 *  A specializations for pushing values into context
 */
#pragma once
#include "basiccontext.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "registermetatype.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "toqobject.h"
#include "objectwithownership.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "basicmetatypes.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "qobjectfinalizer.h"
#include "pushvariant.h"

#include <QList>
#include <QVector>
#include <QMap>
#include <QHash>

namespace dukpp03
{

/*! Pushes a linear structure on stack
 */
template<
    template<
        typename Value
    > 
    class _LinearStructure,
    typename _ValueType,
    typename _Context
>
class PushLinearStructure
{
public:
     /*! Performs pushing value from stack
         \param[in] c context
         \param[in] result a result value
     */
    inline static void perform(
        _Context* c,
        const _LinearStructure<_ValueType> & result
    )
    {
        duk_context* ctx = c->context();
        const int arr_idx = duk_push_array(ctx);
        int index = 0;
        for(typename _LinearStructure<_ValueType>::const_iterator it = result.begin(); it != result.end(); ++it)
        {
            dukpp03::PushValue<_ValueType, _Context>::perform(c, *it);
            duk_put_prop_index(ctx, arr_idx, index);
            ++index;
        }        
    }
};


/*! Pushes a linear structure on stack
 */
template<
    template<
        typename Key,
        typename Value
    > 
    class _DictionaryStructure,
    typename _ValueType,
    typename _Context
>
class PushDictionaryStructure
{
public:
     /*! Performs pushing value from stack
         \param[in] c context
         \param[in] result a result value
     */
    inline static void perform(
        _Context* c,
        const _DictionaryStructure<QString, _ValueType> & result
    )
    {
        duk_context* ctx = c->context();
        const int obj_idx = duk_push_object(ctx);
        for(typename _DictionaryStructure<QString, _ValueType>::const_iterator it = result.begin(); it != result.end(); ++it)
        {
            dukpp03::PushValue<_ValueType, _Context>::perform(c, it.value());
            duk_put_prop_string(ctx, obj_idx, it.key().toStdString().c_str());
        }        
    }
};

/*! Pushes QString as basic string on stack
 */
template<>
class PushValue<QString, dukpp03::qt::BasicContext>
{
public:
    /*! Performs pushing value
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(dukpp03::qt::BasicContext* ctx, const QString& v)
    {
        dukpp03::PushValue<std::string, dukpp03::qt::BasicContext>::perform(ctx, v.toStdString());
    }
};

/*! Performs pushing value on stack for every type of value
 */
template<>
class PushValue<QVariant, dukpp03::qt::BasicContext>
{
public:
    /*! Performs pushing value
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(dukpp03::qt::BasicContext* ctx, const QVariant& v)
    {
        dukpp03::qt::pushVariant(ctx, v);
    }
};


template<>
class PushValue<dukpp03::qt::ObjectWithOwnership, dukpp03::qt::BasicContext>
{
public:
    /*! Performs pushing value
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(dukpp03::qt::BasicContext* ctx, const dukpp03::qt::ObjectWithOwnership& v)
    {
        if (v.second == dukpp03::qt::DQ_OWN)
        {
            dukpp03::PushValue<QObject*, dukpp03::qt::BasicContext>::perform(ctx, v.first);
        }
        else
        {
            // QVariant will push a variant with finalizer for qobjects
            QVariant result;
            result.setValue(v.first);
            dukpp03::PushValue<QVariant, dukpp03::qt::BasicContext>::perform(ctx, result);
        }
    }
};


template<typename T>
class PushValue<QVector<T>, dukpp03::qt::BasicContext>
{
public:
    /*! Performs pushing value
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(dukpp03::qt::BasicContext* ctx, const QVector<T>& v)
    {
        dukpp03::PushLinearStructure<QVector, T, dukpp03::qt::BasicContext>::perform(ctx, v);
    }
};

template<typename T>
class PushValue<QList<T>, dukpp03::qt::BasicContext>
{
public:
    /*! Performs pushing value
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(dukpp03::qt::BasicContext* ctx, const QList<T>& v)
    {
        dukpp03::PushLinearStructure<QList, T, dukpp03::qt::BasicContext>::perform(ctx, v);
    }
};


template<typename T>
class PushValue<QMap<QString, T>, dukpp03::qt::BasicContext>
{
public:
    /*! Performs pushing value
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(dukpp03::qt::BasicContext* ctx, const QMap<QString, T>& v)
    {
        dukpp03::PushDictionaryStructure<QMap, T, dukpp03::qt::BasicContext>::perform(ctx, v);
    }
};

template<typename T>
class PushValue<QHash<QString, T>, dukpp03::qt::BasicContext>
{
public:
    /*! Performs pushing value
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(dukpp03::qt::BasicContext* ctx, const QHash<QString, T>& v)
    {
        dukpp03::PushDictionaryStructure<QHash, T, dukpp03::qt::BasicContext>::perform(ctx, v);
    }
};

}

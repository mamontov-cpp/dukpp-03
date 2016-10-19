/*! \file pushvalue.h
 *
 *  A specializations for pushing values into context
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

}

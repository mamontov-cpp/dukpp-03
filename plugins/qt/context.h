/*! \file context.h

    A context to be used with Qt
 */
#pragma once 
#include "../../include/dukpp-03.h"

#include "variantinterface.h"
#include "mapinterface.h"
#include "timerinterface.h"
#include "valueownership.h"
#include "wrapvalue.h"

// ReSharper disable once CppUnusedIncludeDirective
#include <QPair>
#include <QVariant>
#include <QMetaMethod>
#include <QMetaProperty>

#ifndef DUK_QT_NO_DECLARE_METATYPE_FOR_LONG_DOUBLE
    Q_DECLARE_METATYPE(long double)
#endif

#ifndef DUK_QT_NO_DECLARE_METATYPE_FOR_STD_STRING
    Q_DECLARE_METATYPE(std::string)
#endif

Q_DECLARE_METATYPE(QObject**)
Q_DECLARE_METATYPE(QVariant*)


namespace dukpp03
{

namespace qt
{

/*! A substitute type for object with ownership
 */
typedef QPair<QObject*, dukpp03::qt::ValueOwnership> ObjectWithOwnership;

}
    
}

Q_DECLARE_METATYPE(dukpp03::qt::ObjectWithOwnership)

namespace dukpp03
{

namespace qt
{
/*! A basic context to be used with qt. Should not be used, use Context class instead
 */
typedef dukpp03::Context<dukpp03::qt::MapInterface, dukpp03::qt::VariantInterface, dukpp03::qt::TimerInterface, dukpp03::qt::WrapValue> BasicContext;
/*! A class binding for setting bindings for context
 */
typedef dukpp03::ClassBinding<dukpp03::qt::BasicContext> ClassBinding;
/*! Makes method bindings to context
 */
typedef dukpp03::bind_method<dukpp03::qt::BasicContext> bind_method;
/*! Makes method calls as calls to functions
 */
typedef dukpp03::make_method<dukpp03::qt::BasicContext> make_method;
/*! Makes functions from context calls
 */
typedef dukpp03::make_fun<dukpp03::qt::BasicContext> make_function;
/*! A getter generator for current context
 */
typedef dukpp03::getter<dukpp03::qt::BasicContext> getter;
/*! A setter generator for current context
 */
typedef dukpp03::setter<dukpp03::qt::BasicContext> setter;


/*! A context to be used with Qt. This context registers all needed metadata and also provides us with
    with deleteQObject.
 */
class Context: public dukpp03::qt::BasicContext
{
public:
    /*! Initializes metatypes, needed to work within context
     */
    Context();
    /*! A destructor
     */
    virtual ~Context();
    /*! Pushes new meta method as function into stack
        \param[in] index an index of meta_method in object
        \param[in] meta_method a meta method
     */  
    void pushMetaMethod(int index, const QMetaMethod& meta_method) const;
    /*! Pushes new object on stack with defined ownership
        \param[in] o object
        \param[in] p value ownership
     */
    void pushObject(QObject* o, dukpp03::qt::ValueOwnership p);
    /*! Registers new global object on stack with defined ownership
        \param[in] name a name for a global variable
        \param[in] o object
        \param[in] p value ownership
     */
    void registerGlobal(const QString& name, QObject* o, dukpp03::qt::ValueOwnership p);
};


duk_ret_t qobjectfinalizer(duk_context* ctx);

void pushVariant(dukpp03::qt::BasicContext* ctx, const QVariant& v);

}



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

#include "constructor.h"

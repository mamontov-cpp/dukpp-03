/*! \file classbinding.h
    
    Defines a class binding with support for Qt-style data
 */
#pragma once
#include "basiccontext.h"
#include "registermetatype.h"
#include <QMetaObject>

namespace dukpp03
{
    
namespace qt
{

/*! A new class binding with objects
 */    
class ClassBinding: public dukpp03::ClassBinding<dukpp03::qt::BasicContext>
{
public:
    /*! Makes a default binding
     */
    ClassBinding();
    /*! Could be inherited
     */
    virtual ~ClassBinding();
    /*! Registers this class binding as QObject descendant, filling it
        it with metamethods
     */
    template<typename T>
    void registerMetaObject()
    {
        registerMetaObject(&T::staticMetaObject);
    }
    /*! Registers this class binding as QObject descendant
        \param[in] mo object
        \param[in] register_constructors whether we should register constructor metamethods as well
     */
    void registerMetaObject(const QMetaObject* mo, bool register_constructors = true);
};

/*! Registers all method of qt type in context
    \param[in] ctx context
 */
template<
    typename T
>
void registerTypeInContext(dukpp03::qt::BasicContext* ctx)
{
    const QMetaObject* mo = &T::staticMetaObject;
    QString name = mo->className();
    name.append("*");
    dukpp03::qt::registerMetaType<T>();

    dukpp03::qt::ClassBinding* cb = reinterpret_cast<dukpp03::qt::ClassBinding*>(ctx->getClassBinding(name.toStdString()));
    if (!cb)
    {
        cb = new dukpp03::qt::ClassBinding();
        ctx->addClassBinding(name.toStdString(), cb);
    }
    cb->registerMetaObject<T>();
    cb->registerInContext(ctx);
}

}

}
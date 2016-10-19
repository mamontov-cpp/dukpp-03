/*! \file classbinding.h
    
    Defines a class binding with support for Qt-style data
 */
#pragma once
#include "basiccontext.h"
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

}

}
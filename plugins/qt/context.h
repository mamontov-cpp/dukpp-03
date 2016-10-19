/*! \file context.h

    A context to be used with Qt
 */
#pragma once 
#include "basiccontext.h"
#include "registermetatype.h"
#include "toqobject.h"
#include "objectwithownership.h"
#include "basicmetatypes.h"
#include "qobjectfinalizer.h"
#include "pushvariant.h"

// ReSharper disable once CppUnusedIncludeDirective
#include <QMetaMethod>
#include <QMetaProperty>

namespace dukpp03
{

namespace qt
{

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

}

}

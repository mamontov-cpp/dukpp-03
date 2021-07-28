/*! \mainpage dukqt
    
    A C++03 experimental bindings for Duktape library with support for interaction with Qt
 */
/*! \file context.h

    A context to be used with Qt
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
// ReSharper disable once CppUnusedIncludeDirective
#include "pushvariant.h"

// ReSharper disable once CppUnusedIncludeDirective
#include <QMetaMethod>
#include <QMetaProperty>
// ReSharper disable once CppUnusedIncludeDirective
#include <QString>

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
    virtual ~Context() override;
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

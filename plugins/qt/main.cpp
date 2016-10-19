#include "test.h"
#include "../../src/duktape.cpp"
#include <QObject>
#include <QMetaMethod>

#include "dukqt.h"
#include <iostream>

#include "../../src/abstractcallable.cpp"
#include "../../src/abstractcontext.cpp"

Q_DECLARE_METATYPE(int*)
Q_DECLARE_METATYPE(Test*)
Q_DECLARE_METATYPE(Test**)
Q_DECLARE_METATYPE(Test2*)

int main()
{
    dukpp03::qt::Context ctx;
    ctx.setMaximumExecutionTime(30000);

    dukpp03::qt::registerMetaType<Test>();
    dukpp03::qt::registerMetaType<Test2>();



    dukpp03::qt::ClassBinding* testbinding = new dukpp03::qt::ClassBinding();
    testbinding->addConstructor("Test", dukpp03::qt::qobject::construct<Test>());
    testbinding->addConstructor("Test", dukpp03::qt::qobject::construct<Test, int>());
    testbinding->addMethod("speak", dukpp03::qt::bind_method::from(&Test::speak));
    ctx.registerCallable("free_speak", dukpp03::qt::make_method::from(&Test::speak));
    ctx.addClassBinding("Test*", testbinding);
    std::string error;
    ctx.eval("var a = new Test(); a.speak(); a.slot33(2); a.slot2(); a.slot3(); a.slotx(2, 3, \"a\", 4); free_speak(a);", false, &error);
    std::cout << error << "\n";
    Test f;
    QVariant v;
    Test2* vc;
    
    QVariant v1;
    //v1.setValue(f);
    std::cout << "v1: Can convert to QObject " <<  v1.canConvert<QObject*>() << ":" << v1.value<QObject*>() << "\n";
    QVariant v2;
    v2.setValue(&f);
    std::cout << "v2: Can convert to QObject " <<  v2.canConvert<QObject*>() << ":" << v2.value<QObject*>() << "\n";

    return 0;
}

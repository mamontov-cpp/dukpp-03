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
    const QMetaObject mo = Test::staticMetaObject;
    for(int i = 0; i < mo.constructorCount(); i++)
    {
        QMetaMethod m = mo.constructor(i);
        std::cout << "Return type: " << m.typeName()
                  << " Signature: "  << m.methodSignature().toStdString()
                  << "\n";
    }
    for(int i = mo.methodOffset(); i < mo.methodCount(); i++)
    {
        QMetaMethod m = mo.method(i);
        std::cout << "Return type: " << m.typeName()
                  << " Signature: "  << m.methodSignature().toStdString()
                  << "\n";
    }
    std::cout << "===============================\n";
    dukpp03::qt::Context ctx;
    ctx.setMaximumExecutionTime(30000);

    dukpp03::qt::registerMetaType<Test>();
    dukpp03::qt::registerMetaType<Test2>();



    dukpp03::qt::ClassBinding* testbinding = new dukpp03::qt::ClassBinding();
    testbinding->addMethod("speak", dukpp03::qt::bind_method::from(&Test::speak));
    testbinding->registerMetaObject<Test>();
    ctx.registerCallable("free_speak", dukpp03::qt::make_method::from(&Test::speak));
    ctx.addClassBinding("Test*", testbinding);
    std::string error;
    ctx.eval("var a = new Test(); a.speak(); a.slot33(2); a.slot2(); a.slot3(); a.slotx(2, 3, \"a\", 4); free_speak(a);", false, &error);
    std::cout << error << "\n";
    Test f;
    QVariant v;
    Test2* vc;
    
    return 0;
}

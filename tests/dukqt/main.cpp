#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <cstdio>
#include <iostream>
#define _INC_STDIO
#include "../dukpp03/include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)

/*#include "test.h"
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

QVector<int> pushPrint(QVector<int>& v, int d)
{
    v << d;
    std::cout << "===========\n";
    for(size_t i = 0; i < v.size(); i++)
    {
        std::cout << i  << " " << v[i] << "\n";
    }
    std::cout << "===========\n";

    return v;
}

QList<int> pushPrint2(QList<int>& v, int d)
{
    v << d;
    std::cout << "===========\n";
    for(size_t i = 0; i < v.size(); i++)
    {
        std::cout << i  << " " << v[i] << "\n";
    }
    std::cout << "===========\n";

    return v;
}

QHash<QString, int> testHash(QHash<QString, int>& r, const QString& m, int v)
{
    r.insert(m, v);
    std::cout << "===========\n";
    for(QHash<QString, int>::iterator it = r.begin(); it != r.end(); ++it)
    {
        std::cout << it.key().toStdString().c_str()  << " " << it.value() << "\n";
    }
    std::cout << "===========\n";
    return r; 
}

QMap<QString, int> testMap(QMap<QString, int>& r, const QString& m, int v)
{
    r.insert(m, v);
    std::cout << "===========\n";
    for(QMap<QString, int>::iterator it = r.begin(); it != r.end(); ++it)
    {
        std::cout << it.key().toStdString().c_str()  << " " << it.value() << "\n";
    }
    std::cout << "===========\n";
    return r; 
}
*/

int main(int argc, char** argv[])
{
/*    dukpp03::qt::Context ctx;
    ctx.setMaximumExecutionTime(30000);

    dukpp03::qt::registerMetaType<Test>();
    dukpp03::qt::registerMetaType<Test2>();

    ctx.registerCallable("push_print", dukpp03::qt::make_function::from(pushPrint));
    ctx.registerCallable("push_print_list", dukpp03::qt::make_function::from(pushPrint2));

    ctx.registerCallable("testHash", dukpp03::qt::make_function::from(testHash));
    ctx.registerCallable("testMap", dukpp03::qt::make_function::from(testMap));

    dukpp03::qt::ClassBinding* testbinding = new dukpp03::qt::ClassBinding();
    testbinding->addMethod("speak", dukpp03::qt::bind_method::from(&Test::speak));
    testbinding->registerMetaObject<Test>();
    ctx.registerCallable("free_speak", dukpp03::qt::make_method::from(&Test::speak));
    ctx.addClassBinding("Test*", testbinding);
    std::string error;
    ctx.eval("var a = new Test(1.2); a.speak(); a.slot33(2); a.slot2(); a.slot3(); a.slotx(2, 3, \"a\", 4); free_speak(a); a.x = 122; print(a.x); print(a.slot(127).slot(127));", false, &error);
    std::cout << error << "\n";

    ctx.eval("push_print(push_print([1,2,3], 4), 10);", false, &error);
    std::cout << error << "\n";

    ctx.eval("push_print_list(push_print_list([1,2,3], 4), 10);", false, &error);
    std::cout << error << "\n";

    ctx.eval("push_print_list(push_print_list([1,2,3], 4), 10);", false, &error);
    std::cout << error << "\n";

    ctx.eval("testHash(testHash({\"a\" : 1, \"b\" : 2}, \"333\", 82), \"5555\", 10);", false, &error);
    std::cout << error << "\n";

    ctx.eval("testMap(testMap({\"a\" : 1, \"b\" : 2}, \"333\", 82), \"5555\", 10);", false, &error);
    std::cout << error << "\n";
*/
    /**
     * Run all of the registered tpunit++ tests. Returns 0 if
     * all tests are successful, otherwise returns the number
     * of failing assertions.
     */
    int result = tpunit::Tests::Run(); 
    return result;
}

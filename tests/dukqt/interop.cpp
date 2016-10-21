#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <iostream>
#include "context.h"
#include <dukqt.h>
#include "test.h"
#include "test2.h"
#include "math.h"
#include "../dukpp03/include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)


static ::Test* make(int a)
{
    return new ::Test(a); 
}

int printTestAndReturnValue(::Test* v)
{
    std::cout << "Test(" << v->getValue() << ")\n";
    return v->getValue();
}

struct InteropTest : tpunit::TestFixture
{
public:
    InteropTest() : tpunit::TestFixture(
       TEST(InteropTest::testSimpleBind),
       TEST(InteropTest::testConstructors),
       TEST(InteropTest::testPlainFromMetaMethod),
       TEST(InteropTest::testReceiveInteractions),
       TEST(InteropTest::testMultipleObjects)
    ) {}

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testSimpleBind()
    {
        dukpp03::qt::registerMetaType<::Test>();
        dukpp03::qt::registerMetaType<Test2>();

        dukpp03::qt::Context ctx;
        ctx.registerCallable("make", dukpp03::qt::make_function::from(make));

        std::string error;
        bool result = ctx.eval("var t = make(2); t.return3() + t.value", false, &error);
        if (!result)
        {
            std::cout << error;
        }
        ASSERT_TRUE( result );

        dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1);
        ASSERT_TRUE( val.exists() );
        ASSERT_TRUE( val.value() == 5 );
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testConstructors()
    {
        dukpp03::qt::Context ctx;
        dukpp03::qt::registerTypeInContext<::Test>(&ctx);
        dukpp03::qt::registerTypeInContext<Test2>(&ctx);


        std::string error;
        bool result = ctx.eval("var t = new Test(2); t.return3() + t.value", false, &error);
        if (!result)
        {
            std::cout << error;
        }
        ASSERT_TRUE( result );

        dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1);
        ASSERT_TRUE( val.exists() );
        ASSERT_TRUE( val.value() == 5 );
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testPlainFromMetaMethod()
    {
        dukpp03::qt::Context ctx;
        dukpp03::qt::registerTypeInContext<::Test>(&ctx);
        dukpp03::qt::registerTypeInContext<Test2>(&ctx);
        
        dukpp03::qt::registerMetaType<Test::ValueHolder>();

        dukpp03::qt::ClassBinding* binding = new dukpp03::qt::ClassBinding();
        binding->addMethod("printValue", dukpp03::qt::bind_method::from(&Test::ValueHolder::printValue));
        binding->addMethod("getValue", dukpp03::qt::bind_method::from(&Test::ValueHolder::getValue));
        ctx.addClassBinding("Test::ValueHolder", binding);

        ctx.registerCallable("deleteHolder", dukpp03::qt::make_function::from(Test::deleteHolder));

        {
            std::string error;
            bool result = ctx.eval("var t = new Test(2); var b = t.returnHolder(); b.printValue(); b.getValue() ", false, &error);
            if (!result)
            {
                std::cout << error;
            }
            ASSERT_TRUE( result );

            dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1);
            ASSERT_TRUE( val.exists() );
            ASSERT_TRUE( val.value() == 2 );
        }
        {
            std::string error;
            bool result = ctx.eval("var t = new Test(2); var b = t.returnHolderPtr(); b.printValue(); var f = b.getValue(); deleteHolder(b); f", false, &error);
            if (!result)
            {
                std::cout << error;
            }
            ASSERT_TRUE( result );

            dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1);
            ASSERT_TRUE( val.exists() );
            ASSERT_TRUE( val.value() == 2 );
        }
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testReceiveInteractions()
    {
        dukpp03::qt::Context ctx;
        dukpp03::qt::registerTypeInContext<::Test>(&ctx);
        dukpp03::qt::registerTypeInContext<Test2>(&ctx);

        ctx.registerCallable("printTestAndReturnValue", dukpp03::qt::make_function::from(printTestAndReturnValue));

        std::string error;
        bool result = ctx.eval("printTestAndReturnValue( new Test(2) )", false, &error);
        if (!result)
        {
            std::cout << error;
        }
        ASSERT_TRUE( result );

        dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1);
        ASSERT_TRUE( val.exists() );
        ASSERT_TRUE( val.value() == 2 );
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testMultipleObjects()
    {
        dukpp03::qt::Context ctx;
        dukpp03::qt::registerTypeInContext<::Test>(&ctx);

        dukpp03::qt::registerMetaType<Test2>();
        std::string error;
        bool result = ctx.eval("var b = new Test(2); b.returnDerived(2).get()", false, &error);
        if (!result)
        {
            std::cout << error;
        }
        ASSERT_TRUE( result );

        dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1);
        ASSERT_TRUE( val.exists() );
        ASSERT_TRUE( val.value() == 2 );
    }

} _interop_test;

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

#if HAS_QT5
#else
#define HAS_QT4
#endif

#ifdef HAS_QT4
#define MAP_TYPE QMap<QString, int>
#define HASH_TYPE QHash<QString, int>
Q_DECLARE_METATYPE(MAP_TYPE)
Q_DECLARE_METATYPE(HASH_TYPE)
Q_DECLARE_METATYPE(QVector<int>)
Q_DECLARE_METATYPE(QList<int>)
#endif

QVector<int> pushToVector(QVector<int>& v, int d)
{
    v << d;
    return v;
}

QList<int> pushToList(QList<int>& v, int d)
{
    v << d;
    return v;
}

QHash<QString, int> insertToHash(QHash<QString, int>& r, const QString& m, int v)
{
    r.insert(m, v);
    return r; 
}

QMap<QString, int> insertToMap(QMap<QString, int>& r, const QString& m, int v)
{
    r.insert(m, v);
    return r; 
}

struct BindingsTest : tpunit::TestFixture
{
public:
    BindingsTest() : tpunit::TestFixture(
       TEST(BindingsTest::testMethodOverload),
       TEST(BindingsTest::testSlotPropertyOverride),
       TEST(BindingsTest::testFreeMethodCall),
       TEST(BindingsTest::testPushVector),
       TEST(BindingsTest::testPushList),
       TEST(BindingsTest::testInsertHash),
       TEST(BindingsTest::testInsertMap)
    ) {}

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testMethodOverload()
    {
        dukpp03::qt::registerMetaType<::Test>();
        dukpp03::qt::registerMetaType<Test2>();

        dukpp03::qt::Context ctx;
        dukpp03::qt::ClassBinding* binding = new dukpp03::qt::ClassBinding();
        binding->addMethod("setHalfOfValue", dukpp03::qt::bind_method::from(&::Test::setHalfOfValueFromSum));
        binding->registerMetaObject<::Test>();
        ctx.addClassBinding("Test", binding);
        // Call slot
        {
            std::string error;
            bool result = ctx.eval("var t = new Test(2); t.setHalfOfValue(4); t.value", false, &error);
            if (!result)
            {
                std::cout << error;
            }
            ASSERT_TRUE( result );

            dukpp03::Maybe<int> val = dukpp03::GetValue<int, dukpp03::qt::BasicContext>::perform(&ctx, -1);
            ASSERT_TRUE( val.exists() );
            ASSERT_TRUE( val.value() == 2 );
        }
        // Call real method
        {
            std::string error;
            bool result = ctx.eval("var t = new Test(2); t.setHalfOfValue(2, 2); t.value", false, &error);
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
    void testSlotPropertyOverride()
    {
        dukpp03::qt::registerMetaType<::Test>();
        dukpp03::qt::registerMetaType<Test2>();

        dukpp03::qt::Context ctx;
        dukpp03::qt::ClassBinding* binding = new dukpp03::qt::ClassBinding();
        binding->addMethod("value", dukpp03::qt::bind_method::from(&::Test::setHalfOfValueFromSum));
        binding->registerMetaObject<::Test>();
        ctx.addClassBinding("Test", binding);

        std::string error;
        bool result = ctx.eval("var t = new Test(2); t.value", false, &error);
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
    void testFreeMethodCall()
    {
        dukpp03::qt::registerMetaType<::Test>();
        dukpp03::qt::registerMetaType<Test2>();

        dukpp03::qt::Context ctx;
        dukpp03::qt::ClassBinding* binding = new dukpp03::qt::ClassBinding();
       
        binding->registerMetaObject<::Test>();    
        ctx.registerCallable("value", dukpp03::qt::make_method::from(&::Test::getValue));

        ctx.addClassBinding("Test", binding);

        std::string error;
        bool result = ctx.eval("var t = new Test(2); value(t)", false, &error);
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
    void testPushVector()
    {
        dukpp03::qt::Context ctx;

        ctx.registerCallable("push", dukpp03::qt::make_function::from(&pushToVector));

        std::string error;
        bool result = ctx.eval("push(push([0], 1), 2)", false, &error);
        if (!result)
        {
            std::cout << error;
        }
        ASSERT_TRUE( result );

        dukpp03::Maybe<QVector<int> > val = dukpp03::GetValue<QVector<int> , dukpp03::qt::BasicContext>::perform(&ctx, -1);
        ASSERT_TRUE( val.exists() );
        QVector<int> ethalon;
        ethalon << 0 << 1 << 2;
        ASSERT_TRUE( val.value() == ethalon );   
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testPushList()
    {
        dukpp03::qt::Context ctx;

        ctx.registerCallable("push", dukpp03::qt::make_function::from(&pushToList));

        std::string error;
        bool result = ctx.eval("push(push([0], 1), 2)", false, &error);
        if (!result)
        {
            std::cout << error;
        }
        ASSERT_TRUE( result );

        dukpp03::Maybe<QList<int> > val = dukpp03::GetValue<QList<int> , dukpp03::qt::BasicContext>::perform(&ctx, -1);
        ASSERT_TRUE( val.exists() );
        QList<int> ethalon;
        ethalon << 0 << 1 << 2;
        ASSERT_TRUE( val.value() == ethalon );   
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testInsertHash()
    {
        dukpp03::qt::Context ctx;

        ctx.registerCallable("insert", dukpp03::qt::make_function::from(&insertToHash));

        std::string error;
        bool result = ctx.eval("insert(insert({\"1\" : 1}, \"2\", 2), \"3\", 3)", false, &error);
        if (!result)
        {
            std::cout << error;
        }
        ASSERT_TRUE( result );

        dukpp03::Maybe<QHash<QString, int> > val = dukpp03::GetValue<QHash<QString, int>, dukpp03::qt::BasicContext>::perform(&ctx, -1);
        ASSERT_TRUE( val.exists() );
        QHash<QString, int> ethalon;
        ethalon.insert("1", 1);
        ethalon.insert("2", 2);
        ethalon.insert("3", 3);
        ASSERT_TRUE( val.value() == ethalon );  
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testInsertMap()
    {
        dukpp03::qt::Context ctx;

        ctx.registerCallable("insert", dukpp03::qt::make_function::from(&insertToMap));

        std::string error;
        bool result = ctx.eval("insert(insert({\"1\" : 1}, \"2\", 2), \"3\", 3)", false, &error);
        if (!result)
        {
            std::cout << error;
        }
        ASSERT_TRUE( result );

        dukpp03::Maybe<QMap<QString, int> > val = dukpp03::GetValue<QMap<QString, int>, dukpp03::qt::BasicContext>::perform(&ctx, -1);
        ASSERT_TRUE( val.exists() );
        QMap<QString, int> ethalon;
        ethalon.insert("1", 1);
        ethalon.insert("2", 2);
        ethalon.insert("3", 3);
        ASSERT_TRUE( val.value() == ethalon );  
    }


} _bindings_test;

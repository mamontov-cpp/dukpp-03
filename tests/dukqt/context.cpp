#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include "context.h"
#include "gccollectcheck.h"
#include <dukqt.h>
#include "../dukpp03/include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)

struct ContextTest : tpunit::TestFixture
{
public:
    ContextTest() : tpunit::TestFixture(
       TEST(ContextTest::testTimeout),
       TEST(ContextTest::testPushOwnObject),
       TEST(ContextTest::testPushScriptObject),
       TEST(ContextTest::testRegisterOwnObject),
       TEST(ContextTest::testRegisterScriptObject)
    ) {}

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testTimeout()
    {
        dukpp03::qt::Context ctx;
        ctx.setMaximumExecutionTime(1000);
        ctx.eval("while(true) {}");
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testPushOwnObject()
    {
        dukpp03::qt::registerMetaType<GCCollectCheck>(); 

        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();

        ctx->pushObject(new GCCollectCheck(), dukpp03::qt::DQ_OWN);

        GCCollectCheck::clearCounter();

        dukpp03::Maybe<QObject*> result = dukpp03::GetValue<QObject*, dukpp03::qt::BasicContext>::perform(ctx, -1);
        ASSERT_TRUE( result.exists());

        delete ctx;
        // We forcefully pushing QObject - we know that it should not be collected
        ASSERT_TRUE( GCCollectCheck::counter == 0 );
        
        GCCollectCheck::clearCounter();

        delete result.value();        
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testPushScriptObject()
    {
        dukpp03::qt::registerMetaType<GCCollectCheck>(); 

        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();

        ctx->pushObject(new GCCollectCheck(), dukpp03::qt::DQ_SCRIPT);

        GCCollectCheck::clearCounter();

        dukpp03::Maybe<QObject*> result = dukpp03::GetValue<QObject*, dukpp03::qt::BasicContext>::perform(ctx, -1);
        ASSERT_TRUE( result.exists());

        delete ctx;
        // We forcefully pushing QObject - we know that it should not be collected
        ASSERT_TRUE( GCCollectCheck::counter == 1 );
        
        GCCollectCheck::clearCounter();
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testRegisterOwnObject()
    {
        dukpp03::qt::registerMetaType<GCCollectCheck>(); 

        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();

        ctx->registerGlobal("a", new GCCollectCheck(), dukpp03::qt::DQ_OWN);

        GCCollectCheck::clearCounter();

        dukpp03::Maybe<QObject*> result = ctx->getGlobal<QObject*>("a");
        ASSERT_TRUE( result.exists());

        delete ctx;
        // We forcefully pushing QObject - we know that it should not be collected
        ASSERT_TRUE( GCCollectCheck::counter == 0 );
        
        GCCollectCheck::clearCounter();

        delete result.value();        
    }


    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testRegisterScriptObject()
    {
        dukpp03::qt::registerMetaType<GCCollectCheck>(); 

        dukpp03::qt::Context* ctx = new dukpp03::qt::Context();

        ctx->registerGlobal("a", new GCCollectCheck(), dukpp03::qt::DQ_SCRIPT);

        GCCollectCheck::clearCounter();

        dukpp03::Maybe<QObject*> result = ctx->getGlobal<QObject*>("a");
        ASSERT_TRUE( result.exists());

        delete ctx;
        // We forcefully pushing QObject - we know that it should not be collected
        ASSERT_TRUE( GCCollectCheck::counter == 1 );
        
        GCCollectCheck::clearCounter();
    }

} _context_test;

#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <cstdio>
#include <iostream>
#include "context.h"
#include <dukqt.h>
#define _INC_STDIO
#include "../dukpp03/include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)

struct ContextTest : tpunit::TestFixture
{
public:
    ContextTest() : tpunit::TestFixture(
       TEST(ContextTest::testTimeout)
    ) {}

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testTimeout()
    {
        dukpp03::qt::Context ctx;
        ctx.setMaximumExecutionTime(2000);
        ctx.eval("while(true) {}");
    }
} _context_test;
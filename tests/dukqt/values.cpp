#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <cstdio>
#include <iostream>
#include "context.h"
#include <dukqt.h>
#include "test.h"
Q_DECLARE_METATYPE(Test*)

#include "math.h"
#define _INC_STDIO
#include "../dukpp03/include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)


struct ValuesTest : tpunit::TestFixture
{
public:
    ValuesTest() : tpunit::TestFixture(
       TEST(ValuesTest::testConvert)
    ) {}

    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testConvert()
    {

        dukpp03::qt::registerMetaType<::Test>();

#define FLOAT_EQUAL(A, X) ASSERT_TRUE(fabs((A)-(X)) < 0.0001)
        // Sanity checks
        {
            QVariant v(2);
            QVariant result;
            ASSERT_TRUE(dukpp03::qt::Convert::canConvert("int", &v))
            ASSERT_TRUE(dukpp03::qt::Convert::convert("int", &v, result));
            ASSERT_TRUE(result.value<int>() == 2);
        }

        {
            QVariant v(2);
            QVariant result;
            ASSERT_FALSE(dukpp03::qt::Convert::canConvert("QObject*", &v))
            ASSERT_FALSE(dukpp03::qt::Convert::convert("QObject*", &v, result));
            ASSERT_TRUE(result.value<QObject*>() == NULL);

        }

        {
            QVariant v(2);
            QVariant result;
            ASSERT_TRUE(dukpp03::qt::Convert::canConvert("long", &v))
            ASSERT_TRUE(dukpp03::qt::Convert::convert("long", &v, result));
            ASSERT_TRUE(result.value<long>() == 2);
        }

        // Actual tests
        {

        }
#undef FLOAT_EQUAL
    }
} _values_test;

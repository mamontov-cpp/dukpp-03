#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <cstdio>
#include "context.h"
#define _INC_STDIO
#include "include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)

typedef dukpp03::Pool<dukpp03::utils::VariantInterface, dukpp03::utils::MapInterface> Pool;

struct PoolTest : tpunit::TestFixture
{
public:
    PoolTest() : tpunit::TestFixture(
       TEST(PoolTest::testCopyConstructor),
       TEST(PoolTest::testAssignment),
       TEST(PoolTest::testInsert),
       TEST(PoolTest::testGet),
       TEST(PoolTest::testFree)
    ) {}
    
    void testCopyConstructor()
    {
        Pool pool1;
        std::string id = pool1.insert(new boost::any(1));
        ASSERT_TRUE(id == "\x01");

        Pool pool2(pool1);

        *(pool1.get("\x01")) = 2;

        boost::any* other = pool2.get("\x01");
        ASSERT_TRUE(other);
        
        
        int pool2value = boost::any_cast<int>(*other);
        ASSERT_TRUE(pool2value == 1);
    }

    void testAssignment()
    {
        Pool pool1;
        std::string id = pool1.insert(new boost::any(1));
        ASSERT_TRUE(id == "\x01");

        Pool pool2(pool1);

        *(pool1.get("\x01")) = 2;

        pool2 = pool1;
        
        boost::any* other = pool2.get("\x01");
        ASSERT_TRUE(other);
        
        int pool2value = boost::any_cast<int>(*other);
        ASSERT_TRUE(pool2value == 2);
    }

    void testInsert()
    {
        Pool pool1;
        std::string id = pool1.insert(new boost::any(1));

        int pool2value = boost::any_cast<int>(*(pool1.get(id)));
        ASSERT_TRUE(pool2value == 1);
    }

    void testGet()
    {
        Pool pool1;
        std::string id = pool1.insert(new boost::any(1));
        
        boost::any* b = pool1.get(id);
        ASSERT_TRUE(b != NULL);

        int pool2value = boost::any_cast<int>(*(pool1.get(id)));
        ASSERT_TRUE(pool2value == 1);

        boost::any* othervariantptr = pool1.get("22");
        ASSERT_TRUE(othervariantptr == NULL);
    }

    void testFree()
    {
        Pool pool1;
        std::string id = pool1.insert(new boost::any(1));
        pool1.free();

        boost::any* variantptr = pool1.get(id);
        ASSERT_TRUE(variantptr == NULL);
    }

} _pool_test;
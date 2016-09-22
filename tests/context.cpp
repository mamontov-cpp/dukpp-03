#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <cstdio>
#include "context.h"
#include "callable.h"
#include "point.h"
#include <iostream>
#define _INC_STDIO
#include "include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)

/*! A default callable
 */
class MockCallable: public dukpp03::Callable<dukpp03::context::Context>
{
public:
    MockCallable()
    {
        
    }

    Callable* clone()
    {
        return new MockCallable();
    }

    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return 0;
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::context::Context* c)
    {
        dukpp03::PushValue<int, dukpp03::context::Context>::perform(c, 1, false);
        return 1;
    }

};


struct ContextTest : tpunit::TestFixture
{
public:
    ContextTest() : tpunit::TestFixture(
       TEST(ContextTest::testInitGet),
       TEST(ContextTest::testPushGet),
       TEST(ContextTest::testEvalNormal),
       TEST(ContextTest::testEvalFail),
       TEST(ContextTest::testEvalTimeout),
       TEST(ContextTest::testClean),
       TEST(ContextTest::testReset),
       TEST(ContextTest::testThrow),
       TEST(ContextTest::testRegisterGlobal),
       TEST(ContextTest::testRegisterCallable)
    ) {}

    /*! Tests getting and setting reference data
     */
    void testInitGet()
    {
        dukpp03::context::Context ctx;
        ASSERT_TRUE( dukpp03::context::Context::getContext(ctx.context()) == &ctx );
        ASSERT_TRUE( dukpp03::context::Context::getContext(ctx.context()) == &ctx );
    }

    /*! Tests pushing and getting values
     */
    void testPushGet()
    {
        dukpp03::context::Context ctx;

        // Common case
        int test_number = 0;
        {
            Point pts2d(3, 4);
            dukpp03::PushValue<Point, dukpp03::context::Context>::perform(&ctx, pts2d, false);
            dukpp03::Maybe<Point> mbpts2d =
                dukpp03::GetValue<Point, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( mbpts2d.exists() );
            ASSERT_TRUE( is_fuzzy_equal(mbpts2d.value().x(), 3));
            ASSERT_TRUE( is_fuzzy_equal(mbpts2d.value().y(), 4));
        }

        // char
        {
            char c = 121;
            dukpp03::PushValue<char, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<char> maybev = dukpp03::GetValue<char, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( maybev.value() == 121);
        }

        // unsigned char
        {
            unsigned char c = 121;
            dukpp03::PushValue<unsigned char, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<unsigned char> maybev = dukpp03::GetValue<unsigned char, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( maybev.value() == 121);
        }

        // int
        {
            int c = 121;
            dukpp03::PushValue<int, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<int> maybev = dukpp03::GetValue<int, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( maybev.value() == 121);
        }

        // unsigned int
        {
            unsigned int c = 121;
            dukpp03::PushValue<unsigned int, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<unsigned int> maybev = dukpp03::GetValue<unsigned int, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( maybev.value() == 121);
        }

        // long
        {
            long c = 121;
            dukpp03::PushValue<long, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<long> maybev = dukpp03::GetValue<long, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( maybev.value() == 121);
        }

        // unsigned long
        {
            unsigned long c = 121;
            dukpp03::PushValue<unsigned long, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<unsigned long> maybev = dukpp03::GetValue<unsigned long, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( maybev.value() == 121);
        }

        // long long
        {
            long long c = 121;
            dukpp03::PushValue<long long, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<long long> maybev = dukpp03::GetValue<long long, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( maybev.value() == 121);
        }

        // unsigned long
        {
            unsigned long long c = 121;
            dukpp03::PushValue<unsigned long long, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<unsigned long long> maybev = dukpp03::GetValue<unsigned long long, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( maybev.value() == 121);
        }

        // bool
        {
            bool c = false;
            dukpp03::PushValue<bool, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<bool> maybev = dukpp03::GetValue<bool, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( maybev.value() == false);
        }

        // float
        {
            float c = 1.5;
            dukpp03::PushValue<float, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<float> maybev = dukpp03::GetValue<float, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( is_fuzzy_equal(maybev.value(), c));
        }

        // double
        {
            double c = 1.5;
            dukpp03::PushValue<double, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<double> maybev = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( is_fuzzy_equal(maybev.value(), c));
        }

        // long double
        {
            long double c = 1.5;
            dukpp03::PushValue<long double, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<long double> maybev = dukpp03::GetValue<long double, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( is_fuzzy_equal(maybev.value(), c));
        }
        
        // std::string
        {
            const char* c = "23";
            dukpp03::PushValue<std::string, dukpp03::context::Context>::perform(&ctx, c, false);
            dukpp03::Maybe<std::string> maybev = dukpp03::GetValue<std::string, dukpp03::context::Context>::perform(&ctx, test_number++);
            ASSERT_TRUE( maybev.exists());
            ASSERT_TRUE( maybev.value() == "23");
        }
    }
    /*! Test for normal evaluation process
     */
    void testEvalNormal()
    {
        std::string error;
        dukpp03::context::Context ctx;
        bool eval_result = ctx.eval("1 + 1", false, &error);
        ASSERT_TRUE( eval_result );
        ASSERT_TRUE( error.size() == 0 );
        dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == 2);		
    }
    /*! Test for non-compilable code
     */
    void testEvalFail()
    {
        std::string error;
        dukpp03::context::Context ctx;
        bool eval_result = ctx.eval("1 + ;", true, &error);
        ASSERT_TRUE( !eval_result );
        ASSERT_TRUE( error.size() != 0 );
    }
    /*! Test for timeout
     */
    void testEvalTimeout()
    {
        std::string error;
        dukpp03::context::Context ctx;
        ctx.setMaximumExecutionTime(1000);
        bool eval_result = ctx.eval("while(true) {}", true, &error);
        ASSERT_TRUE( !eval_result );
        ASSERT_TRUE( error.size() != 0 );
    }
    
    /*! Test cleaning  of a pool
     */
    void testClean()
    {
        dukpp03::context::Context ctx;
        Point pts2d(3, 4);
        dukpp03::PushValue<Point, dukpp03::context::Context>::perform(&ctx, pts2d, false);
        dukpp03::Maybe<Point> mbpts2d =
            dukpp03::GetValue<Point, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( mbpts2d.exists() );
            
        ctx.clean();

        mbpts2d = dukpp03::GetValue<Point, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( mbpts2d.exists() == false );
    }
    /*! Test cleaning both pools and full reset of context
     */
    void testReset()
    {
        dukpp03::context::Context ctx;
        Point pts2d(3, 4);
        dukpp03::PushValue<Point, dukpp03::context::Context>::perform(&ctx, pts2d, true);
        dukpp03::Maybe<Point> mbpts2d =
            dukpp03::GetValue<Point, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( mbpts2d.exists() );
            
        ctx.reset();

        mbpts2d = dukpp03::GetValue<Point, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( mbpts2d.exists() == false );
        ASSERT_TRUE( dukpp03::context::Context::getContext(ctx.context()) == &ctx );
    }
    /*! Tests throwing for object
     */
    void testThrow()
    {
        dukpp03::context::Context ctx;
        ctx.throwError("Generic Error!");
        const char* s = duk_to_string(ctx.context(), -1);
        ASSERT_TRUE( s != NULL );
        std::string testvalue = s;
        ASSERT_TRUE(  testvalue.size() != 0 );
    }
    /*! Tests registering value as property of global object
     */
    void testRegisterGlobal()
    {
        dukpp03::context::Context ctx;
        ctx.registerGlobal("value", true);
        bool eval_result = ctx.eval(" !value ", false);
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<bool> result = dukpp03::GetValue<bool, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == false );
    }
    /*! Tests registering callable function
     */
    void testRegisterCallable()
    {
        dukpp03::context::Context ctx;
        ctx.registerCallable("f", new MockCallable());
        bool eval_result = ctx.eval(" (f() + f()) * (f() + f()) ; f() + f()*f() ", false);
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == 2 );
    }
    
} _context_test;
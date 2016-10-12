#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <cstdio>
#include "context.h"
#include "point.h"
#include <iostream>
#define _INC_STDIO
#include "include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)


void print_something()
{
    printf("print_something(): zero argments \n");
}

void print_number_1(int a)
{
    printf("print_number_1: %d\n", a);  
}

void print_number_3(int a, int b, int c)
{
    printf("print_number_3: %d %d %d\n", a, b, c ); 
}

int return_something()
{
    return 32;
}


int return_number_1(int a)
{
    return a;
}

int return_number_3(int a, int b, int c)
{
    return a - b - c;
}

int return_number_3_decay(const int& a, int /*& - can't use it here, will be buggy */ b, int c)
{
    return a - b - c;
}

struct CallablesTest : tpunit::TestFixture
{
public:
    CallablesTest() : tpunit::TestFixture(
       TEST(CallablesTest::testRegisterVoidFunctions),
       TEST(CallablesTest::testRegisterReturnFunctions),
       TEST(CallablesTest::testMethods),
       TEST(CallablesTest::testPtrMethods),
       TEST(CallablesTest::testThisMethods)
    ) {}

     /*! Tests registering functions
     */
    void testRegisterVoidFunctions()
    {
        std::string error;  

        dukpp03::context::Context ctx;
        ctx.registerCallable("f00", mkf::from(print_something));
        bool eval_result = ctx.eval(" f00(); f00(); ", true, &error);
        ASSERT_TRUE( eval_result );

        ctx.registerCallable("f01", mkf::from(print_number_1));
        eval_result = ctx.eval(" f01(21); f01(32); ", true);
        ASSERT_TRUE( eval_result );

        ctx.registerCallable("f03", mkf::from(print_number_3));
        eval_result = ctx.eval(" f03(21, 44, 56); f03(32, 88, 93); ", true);
        ASSERT_TRUE( eval_result );

        eval_result = ctx.eval(" f03(21) ", true, &error);
        ASSERT_TRUE( !eval_result );

        eval_result = ctx.eval(" new f03(21, 31, 31) ", true, &error);
        ASSERT_TRUE( !eval_result );

        eval_result = ctx.eval(" f03(undefined, undefined, undefined) ", true, &error);
        ASSERT_TRUE( !eval_result );
    }

    void testRegisterReturnFunctions()
    {
        std::string error;  

        dukpp03::context::Context ctx;
        ctx.registerCallable("f00", mkf::from(return_something));
        bool eval_result = ctx.eval(" f00(); f00(); ", false, &error);
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == 32 );

        ctx.registerCallable("f01", mkf::from(return_number_1));
        eval_result = ctx.eval(" f01(21); f01(32); ", false);
        ASSERT_TRUE( eval_result );
        result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == 32 );

        ctx.registerCallable("f03", mkf::from(return_number_3));
        eval_result = ctx.eval(" f03(21, 44, 56); f03(32, 88, 93); ", false);
        ASSERT_TRUE( eval_result );
        result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == 32 - 88 - 93 );

        ctx.registerCallable("f04", mkf::from(return_number_3_decay));
        eval_result = ctx.eval(" f04(21, 44, 56); f04(32, 88, 93); ", false);
        ASSERT_TRUE( eval_result );
        result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == 32 - 88 - 93 );

        
        eval_result = ctx.eval(" f03(21) ", false, &error);
        ASSERT_TRUE( !eval_result );

        eval_result = ctx.eval("new f03(21, 31, 41) ", false, &error);
        ASSERT_TRUE( !eval_result );

        eval_result = ctx.eval(" f03(undefined, undefined, undefined) ", false, &error);
        ASSERT_TRUE( !eval_result ); 
    }

    void testMethods()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        register_constructor::in_context<Point, double, double>(&ctx, "pnt");
        ctx.registerCallable("x", mkm::from(&Point::x));
        ctx.registerCallable("y", mkm::from(&Point::y));

        ctx.registerCallable("setX", mkm::from(&Point::setX));
        ctx.registerCallable("setY", mkm::from(&Point::setY));

        bool eval_result = ctx.eval(" var f = pnt(3, 4);  setX(f, 55); x(f) ", false);
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( is_fuzzy_equal(result.value(), 55) );
    }

    void testPtrMethods()
    {
        std::string error;  

        Point p(5, 7);
        std::cout << "Point adress is " << &p << "\n";
        dukpp03::context::Context ctx;
        ctx.registerGlobal("pnt", &p);

        ctx.registerCallable("x", mkm::from(&Point::x));
        ctx.registerCallable("y", mkm::from(&Point::y));

        ctx.registerCallable("setX", mkm::from(&Point::setX));
        ctx.registerCallable("setY", mkm::from(&Point::setY));

        bool eval_result = ctx.eval(" setX(pnt, 55); x(pnt) ", false, &error);
        std::cout << error << "\n";
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        if (!is_fuzzy_equal(result.value(), 55)) 
        {
            std::cout << "Point x value is " << result.value() << "\n";
        }
        ASSERT_TRUE( is_fuzzy_equal(result.value(), 55) );
    }
    
    void testThisMethods()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        register_constructor::in_context<Point, double, double>(&ctx, "pnt");
        ctx.registerCallable("x", bnd::from(&Point::x));
        ctx.registerCallable("y", bnd::from(&Point::y));

        ctx.registerCallable("setX", bnd::from(&Point::setX));
        ctx.registerCallable("setY", bnd::from(&Point::setY));

        bool eval_result = ctx.eval(" var f = pnt(3, 4); f.x = x; f.setX = setX;  f.setX(12);  f.x() ", false);
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( is_fuzzy_equal(result.value(), 12) );
    }
    
} _callables_test;
#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <cstdio>
#include "context.h"
#include "callable.h"
#include "point.h"
#include "jsobject.h"
#include <iostream>
#define _INC_STDIO
#include "include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)

JSObject* testFunction()
{
	JSObject* r  = new JSObject();
	r->setProperty("m_x", "10");
	return r;
}

struct JSObjectTest : tpunit::TestFixture
{
public:
    JSObjectTest() : tpunit::TestFixture(
       TEST(JSObjectTest::testPrototype1),
       TEST(JSObjectTest::testInheritance1),
       TEST(JSObjectTest::testInheritance2)
    ) {}

	/*! Tests prototype inheritance for JSObject and garbage collection
	 */
	void testPrototype1()
    {
	    dukpp03::context::Context ctx;
		ctx.registerCallable("Base", mkf::from(testFunction));
        std::string error;

        {
            bool eval_result = ctx.eval(" Base.prototype.f = function() { return 120; }; var a = new Base(); a.f() ", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 120) );
        } 
    }

	/*! A basic inheritance test for JSObject
	 */
	void testInheritance1()
    {
	    dukpp03::context::Context ctx;
		ctx.registerCallable("Base", mkf::from(testFunction));
		std::string error;

		 bool eval_result = ctx.eval(
                "Base.prototype.f = function() { return 120; };"
                "var ChildPoint = function() { }, m = new Base();"
                "ChildPoint.prototype = m;"
                "var a = new ChildPoint(); a.f() ", false,  &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( is_fuzzy_equal(result.value(), 120) );
    }

	/*! A second inheritance test for JSObject
	 */
	void testInheritance2()
    {
	    dukpp03::context::Context ctx;
		ctx.registerCallable("Base", mkf::from(testFunction));
		std::string error;

		{
            bool eval_result = ctx.eval(
                "Base.prototype.f = function() { return this.m_x; };"
                "var ChildPoint = function(a, b) { Object.setPrototypeOf(this, new Base()); };"
                "var a = new ChildPoint(), b = new ChildPoint();"
                "a.f() + b.f() ", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 20) );
        }
    }

} js_object_test;
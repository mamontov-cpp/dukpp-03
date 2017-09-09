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

/*! Amount of allocated marked objects
 */
size_t allocated_objects = 0;

/*! A javascript marked object
 */
class JSMarkedObject: public JSObject
{
public:
	/*! When  constructor is called, amount of allocated objects increases
	 */
	JSMarkedObject()
	{
		++allocated_objects;
	}

	/*! When destructor is called, amount of deallocated object decreases
	 */
	~JSMarkedObject()
	{
		--allocated_objects;
	}
};

namespace dukpp03
{

/*! Makes possible to return a marked object from a function
 */
template<>
class PushValue<JSMarkedObject*, dukpp03::context::Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(dukpp03::context::Context* ctx, const JSMarkedObject* v)
    {
        dukpp03::PushValue<dukpp03::JSObject<dukpp03::context::Context>*, dukpp03::context::Context>::perform(ctx, v);
    }
};	

}


/*! A basic testing functions
 */
JSObject* testFunction()
{
	JSObject* r  = new JSObject();
	r->setEvaluatedProperty("m_x", "10");
	return r;
}

/*! A basic marked function
 */
JSMarkedObject* basicMarkedFunction()
{
	JSMarkedObject* r = new JSMarkedObject();
	r->setEvaluatedProperty("m_x", "10");
	r->setEvaluatedProperty("o", "(function() { return this.m_x; })");
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
    // ReSharper disable once CppMemberFunctionMayBeConst
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
    // ReSharper disable once CppMemberFunctionMayBeConst
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
    // ReSharper disable once CppMemberFunctionMayBeConst
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

	/*! Tests adding objects to two contexts
	 */
    // ReSharper disable once CppMemberFunctionMayBeConst
    void testAddToTwoContexts()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx1 = new dukpp03::context::Context();
        dukpp03::context::Context* ctx2 = new dukpp03::context::Context();

        JSMarkedObject* obj = new JSMarkedObject();
        obj->setProperty("22", 22);
        ASSERT_TRUE( allocated_objects == 1);
    }

} js_object_test;
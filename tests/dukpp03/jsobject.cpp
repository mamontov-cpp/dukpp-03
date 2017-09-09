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


/*! A selected object
 */
JSMarkedObject* selected_object;

/*! Returns a selected object
 */ 
JSMarkedObject* returnSelectedObject()
{
	return selected_object;
}

dukpp03::Maybe<JSMarkedObject*> returnNullOrSelected(bool null)
{
	if (null)
	{
		return dukpp03::Maybe<JSMarkedObject*>();
	}
	else
	{
		return  dukpp03::Maybe<JSMarkedObject*>(selected_object);
	}
}

struct JSObjectTest : tpunit::TestFixture
{
public:
    JSObjectTest() : tpunit::TestFixture(
       TEST(JSObjectTest::testPrototype1),
       TEST(JSObjectTest::testInheritance1),
       TEST(JSObjectTest::testInheritance2),
	   TEST(JSObjectTest::testAddToTwoContexts),
	   TEST(JSObjectTest::testAddToContextTwice),
	   TEST(JSObjectTest::testAddToDifferentContextsSeveralTimes),
	   TEST(JSObjectTest::testReturnSelectedObjectFromFunctionTwice),
	   TEST(JSObjectTest::testNullOrObject),
	   TEST(JSObjectTest::testRegisterAndPushToSeveralContexts),
	   TEST(JSObjectTest::testRegisterAndPushToSeveralContextsSeveralTimes),
	   TEST(JSObjectTest::testRegisterAsComplexProperty)
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
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testAddToTwoContexts()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx1 = new dukpp03::context::Context();
        dukpp03::context::Context* ctx2 = new dukpp03::context::Context();

        JSMarkedObject* obj = new JSMarkedObject();
        obj->setProperty("22", 22);
        ASSERT_TRUE( allocated_objects == 1);

		dukpp03::PushValue<JSObject*, dukpp03::context::Context>::perform(ctx1, obj);
		dukpp03::PushValue<JSObject*, dukpp03::context::Context>::perform(ctx2, obj);

        ASSERT_TRUE( allocated_objects == 1);
		delete ctx1;
		delete ctx2;

        ASSERT_TRUE( allocated_objects == 0);
    }

	/*! Tests adding same object to context twice
	 */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testAddToContextTwice()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        JSMarkedObject* obj = new JSMarkedObject();
        obj->setProperty("22", 22);
        ASSERT_TRUE( allocated_objects == 1);

		obj->registerAsGlobalVariable(ctx, "a");
		obj->registerAsGlobalVariable(ctx, "b");

		ctx->eval("delete b;");

        ASSERT_TRUE( allocated_objects == 1);
		delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

	/*! Tests adding same object to several contexts 
	 */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
	void testAddToDifferentContextsSeveralTimes()
    {
	    allocated_objects = 0;

        dukpp03::context::Context* ctx1 = new dukpp03::context::Context();
        dukpp03::context::Context* ctx2 = new dukpp03::context::Context();

        JSMarkedObject* obj = new JSMarkedObject();
        obj->setProperty("22", 22);
        ASSERT_TRUE( allocated_objects == 1);

		obj->registerAsGlobalVariable(ctx1, "a");
		obj->registerAsGlobalVariable(ctx1, "b");

		obj->registerAsGlobalVariable(ctx2, "a");
		obj->registerAsGlobalVariable(ctx2, "b");

		ctx1->eval("delete a;");
		ctx2->eval("delete b;");

        ASSERT_TRUE( allocated_objects == 1);
		delete ctx1;
		delete ctx2;

        ASSERT_TRUE( allocated_objects == 0);
    }

	/*! Tests returning same object from function twice
	 */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
	void testReturnSelectedObjectFromFunctionTwice()
    {
	    allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();
		selected_object = new JSMarkedObject();
        selected_object->setProperty("me", 22);
        ASSERT_TRUE( allocated_objects == 1);

		ctx->registerCallable("f", mkf::from(testFunction));
        std::string error;

        {
            bool eval_result = ctx->eval("f().me + f().me ", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 44) );
        }
    	delete ctx;

		ASSERT_TRUE( allocated_objects == 0);
    }

	/*! Tests returning null or object values
	 */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
	void testNullOrObject()
    {
	    allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();
		selected_object = new JSMarkedObject();
        selected_object->setProperty("me", 22);
        ASSERT_TRUE( allocated_objects == 1);

		ctx->registerCallable("f", mkf::from(returnNullOrSelected));
        std::string error;

        {
            bool eval_result = ctx->eval("f(false).me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 22) );
        }

		 {
            bool eval_result = ctx->eval("f(true) == null", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<bool> result = dukpp03::GetValue<bool, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == true );
        }
    	delete ctx;

		ASSERT_TRUE( allocated_objects == 0);	    
    }

	/*! Tests registering and pushing values several times to several contexts
	 */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
	void testRegisterAndPushToSeveralContexts()
    {
	    allocated_objects = 0;

        dukpp03::context::Context* ctx1 = new dukpp03::context::Context();
        dukpp03::context::Context* ctx2 = new dukpp03::context::Context();

		selected_object = new JSMarkedObject();
        selected_object->setProperty("me", 22);
        ASSERT_TRUE( allocated_objects == 1);

		ctx1->registerCallable("f", mkf::from(returnSelectedObject));
		selected_object->registerAsGlobalVariable(ctx1, "a");

		ctx2->registerCallable("f", mkf::from(returnSelectedObject));
		selected_object->registerAsGlobalVariable(ctx2, "a");

        std::string error;

        {
            bool eval_result = ctx1->eval("f().me + a.me ", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(ctx1, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 44) );
        }

        {
            bool eval_result = ctx2->eval("f().me + a.me ", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(ctx2, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 44) );
        }

    	delete ctx1;
    	delete ctx2;

		ASSERT_TRUE( allocated_objects == 0);
    }

	/*! Tests registering and pushing values several times several times to several contexts
	 */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
	void testRegisterAndPushToSeveralContextsSeveralTimes()
    {
	    allocated_objects = 0;

        dukpp03::context::Context* ctx1 = new dukpp03::context::Context();
        dukpp03::context::Context* ctx2 = new dukpp03::context::Context();

		selected_object = new JSMarkedObject();
        selected_object->setProperty("me", 22);
        ASSERT_TRUE( allocated_objects == 1);

		ctx1->registerCallable("f", mkf::from(returnSelectedObject));
		selected_object->registerAsGlobalVariable(ctx1, "a");
		selected_object->registerAsGlobalVariable(ctx1, "b");

		ctx2->registerCallable("f", mkf::from(returnSelectedObject));
		selected_object->registerAsGlobalVariable(ctx2, "a");
		selected_object->registerAsGlobalVariable(ctx2, "b");

        std::string error;

        {
            bool eval_result = ctx1->eval("f().me + a.me + f().me + b.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(ctx1, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 88) );
        }

        {
            bool eval_result = ctx2->eval("f().me + a.me  + f().me + b.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(ctx2, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 88) );
        }

    	delete ctx1;
    	delete ctx2;

		ASSERT_TRUE( allocated_objects == 0);	    
    }

	/*! Tests registering complex property
	 */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
	void testRegisterAsComplexProperty()
    {
	    allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

		selected_object = new JSMarkedObject();
        selected_object->setProperty("me", 22);
        ASSERT_TRUE( allocated_objects == 1);

		ctx->eval("E = {}; E.o = {};");
		selected_object->registerAsGlobalVariable(ctx, "E.o.m");

        std::string error;

        {
            bool eval_result = ctx->eval("E.o.m.me + E.o.m.me ", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 44) );
        }

    	delete ctx;

		ASSERT_TRUE( allocated_objects == 0);
    }

} js_object_test;
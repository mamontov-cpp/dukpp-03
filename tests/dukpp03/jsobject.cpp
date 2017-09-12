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
    \return test object
 */
JSObject* testFunction()
{
    JSObject* r  = new JSObject();
    r->setEvaluatedProperty("m_x", "10");
    return r;
}

/*! Returns 22
    \return 22
 */
int return22()
{
    return 22;
}
/*! Returns 22 on context's stack
    \return 1
 */
duk_ret_t dukReturn22(duk_context *ctx) {
    duk_push_int(ctx, 22);
    return 1;
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
       TEST(JSObjectTest::testRegisterAsComplexProperty),
       TEST(JSObjectTest::testDeletePropertyBeforeRegistering),
       TEST(JSObjectTest::testDeletePropertyAfterRegistering),
       TEST(JSObjectTest::testDeletePropertyAfterPush),
       TEST(JSObjectTest::testSetTProperty),
       TEST(JSObjectTest::testSetTPropertyAfterRegister),
       TEST(JSObjectTest::testSetTPropertyAfterPush),
       TEST(JSObjectTest::testSetCallableProperty),
       TEST(JSObjectTest::testSetCallablePropertyAfterRegister),
       TEST(JSObjectTest::testSetCallablePropertyAfterPush),
       TEST(JSObjectTest::testSetNullProperty),
       TEST(JSObjectTest::testSetNullPropertyAfterRegister),
       TEST(JSObjectTest::testSetNullPropertyAfterPush),
       TEST(JSObjectTest::testSetCFunctionProperty),
       TEST(JSObjectTest::testSetCFunctionPropertyAfterRegister),
       TEST(JSObjectTest::testSetCFunctionPropertyAfterPush),
       TEST(JSObjectTest::testSetEvaluatedProperty),
       TEST(JSObjectTest::testSetEvaluatedPropertyAfterRegister),
       TEST(JSObjectTest::testSetEvaluatedPropertyAfterPush),
       TEST(JSObjectTest::testObjectLoop1),
       TEST(JSObjectTest::testObjectLoop2),
       TEST(JSObjectTest::testSetNestedProperty1),
       TEST(JSObjectTest::testSetNestedProperty2),
       TEST(JSObjectTest::testSetNestedProperty3),
       TEST(JSObjectTest::testSetNestedProperty4),
       TEST(JSObjectTest::testSetNestedProperty5),
       TEST(JSObjectTest::testSetNestedProperty6),
       TEST(JSObjectTest::testSetNestedProperty7)
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

    /*! Tests deleting property before registering
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testDeletePropertyBeforeRegistering()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        selected_object->setProperty("me", 22);
        selected_object->deleteProperty("me");
        ASSERT_TRUE( allocated_objects == 1);

        selected_object->registerAsGlobalVariable(ctx, "E");

        std::string error;

        {
            bool eval_result = ctx->eval("(typeof E.me == \"undefined\")", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<bool> result = dukpp03::GetValue<bool, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }


    /*! Tests deleting property after registering
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testDeletePropertyAfterRegistering()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        selected_object->setProperty("me", 22);
        selected_object->registerAsGlobalVariable(ctx, "E");

        ASSERT_TRUE( allocated_objects == 1);

        selected_object->deleteProperty("me");

        std::string error;

        {
            bool eval_result = ctx->eval("(typeof E.me == \"undefined\")", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<bool> result = dukpp03::GetValue<bool, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);  
    }

    /*! Tests deleting property after pushing value on stack
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testDeletePropertyAfterPush()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        selected_object->setProperty("me", 22);

        ASSERT_TRUE( allocated_objects == 1);

        ctx->registerCallable("f", mkf::from(returnSelectedObject));

        std::string error;

        {
            bool eval_result = ctx->eval("var E = f();", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
        }

        selected_object->deleteProperty("me");

        {
            bool eval_result = ctx->eval("(typeof E.me == \"undefined\")", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<bool> result = dukpp03::GetValue<bool, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting property before registering value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetTProperty()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        selected_object->setProperty("me", 22);
        ASSERT_TRUE( allocated_objects == 1);

        selected_object->registerAsGlobalVariable(ctx, "E");

        std::string error;

        {
            bool eval_result = ctx->eval("E.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting property after registering value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetTPropertyAfterRegister()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        ASSERT_TRUE( allocated_objects == 1);

        selected_object->registerAsGlobalVariable(ctx, "E");

        selected_object->setProperty("me", 22);

        std::string error;

        {
            bool eval_result = ctx->eval("E.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting property after pushing value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetTPropertyAfterPush()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();

        ASSERT_TRUE( allocated_objects == 1);

        ctx->registerCallable("f", mkf::from(returnSelectedObject));

        std::string error;

        {
            bool eval_result = ctx->eval("var E = f();", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
        }

        selected_object->setProperty("me", 22);

        {
            bool eval_result = ctx->eval("E.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting callable property before registering value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetCallableProperty()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        selected_object->setProperty("me", mkf::from(return22));
        ASSERT_TRUE( allocated_objects == 1);

        selected_object->registerAsGlobalVariable(ctx, "E");

        std::string error;

        {
            bool eval_result = ctx->eval("E.me()", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting callable property after registering value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetCallablePropertyAfterRegister()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        ASSERT_TRUE( allocated_objects == 1);

        selected_object->registerAsGlobalVariable(ctx, "E");

        selected_object->setProperty("me", mkf::from(return22));

        std::string error;

        {
            bool eval_result = ctx->eval("E.me()", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting callable property after pushing value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetCallablePropertyAfterPush()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();

        ASSERT_TRUE( allocated_objects == 1);

        ctx->registerCallable("f", mkf::from(returnSelectedObject));

        std::string error;

        {
            bool eval_result = ctx->eval("var E = f();", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
        }

        selected_object->setProperty("me", mkf::from(return22));

        {
            bool eval_result = ctx->eval("E.me()", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting null property before registering value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetNullProperty()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        selected_object->setNullProperty("me");
        ASSERT_TRUE( allocated_objects == 1);

        selected_object->registerAsGlobalVariable(ctx, "E");

        std::string error;

        {
            bool eval_result = ctx->eval("E.me == null", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<bool> result = dukpp03::GetValue<bool, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting null property after registering value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetNullPropertyAfterRegister()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        ASSERT_TRUE( allocated_objects == 1);

        selected_object->registerAsGlobalVariable(ctx, "E");

        selected_object->setNullProperty("me");

        std::string error;

        {
            bool eval_result = ctx->eval("E.me == null", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<bool> result = dukpp03::GetValue<bool, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting null property after pushing value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetNullPropertyAfterPush()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();

        ASSERT_TRUE( allocated_objects == 1);

        ctx->registerCallable("f", mkf::from(returnSelectedObject));

        std::string error;

        {
            bool eval_result = ctx->eval("var E = f();", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
        }

        selected_object->setNullProperty("me");

        {
            bool eval_result = ctx->eval("E.me == null", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<bool> result = dukpp03::GetValue<bool, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting c function property before registering value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetCFunctionProperty()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        selected_object->setProperty("me", dukReturn22, DUK_VARARGS);
        ASSERT_TRUE( allocated_objects == 1);

        selected_object->registerAsGlobalVariable(ctx, "E");

        std::string error;

        {
            bool eval_result = ctx->eval("E.me()", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting c function property after registering value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetCFunctionPropertyAfterRegister()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        ASSERT_TRUE( allocated_objects == 1);

        selected_object->registerAsGlobalVariable(ctx, "E");

        selected_object->setProperty("me", dukReturn22, DUK_VARARGS);

        std::string error;

        {
            bool eval_result = ctx->eval("E.me()", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting c function property after pushing value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetCFunctionPropertyAfterPush()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();

        ASSERT_TRUE( allocated_objects == 1);

        ctx->registerCallable("f", mkf::from(returnSelectedObject));

        std::string error;

        {
            bool eval_result = ctx->eval("var E = f();", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
        }

        selected_object->setProperty("me", dukReturn22, DUK_VARARGS);

        {
            bool eval_result = ctx->eval("E.me()", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting evaluated function property before registering value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetEvaluatedProperty()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        selected_object->setEvaluatedProperty("me", "(function() { return 22; })");
        ASSERT_TRUE( allocated_objects == 1);

        selected_object->registerAsGlobalVariable(ctx, "E");

        std::string error;

        {
            bool eval_result = ctx->eval("E.me()", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting evaluated function property after registering value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetEvaluatedPropertyAfterRegister()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();
        ASSERT_TRUE( allocated_objects == 1);

        selected_object->registerAsGlobalVariable(ctx, "E");

        selected_object->setEvaluatedProperty("me", "(function() { return 22; })");

        std::string error;

        {
            bool eval_result = ctx->eval("E.me()", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting evaluated function property after pushing value
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetEvaluatedPropertyAfterPush()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        selected_object = new JSMarkedObject();

        ASSERT_TRUE( allocated_objects == 1);

        ctx->registerCallable("f", mkf::from(returnSelectedObject));

        std::string error;

        {
            bool eval_result = ctx->eval("var E = f();", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
        }

        selected_object->setEvaluatedProperty("me", "(function() { return 22; })");

        {
            bool eval_result = ctx->eval("E.me()", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting property, that makes reference counting impossible, so exception is thrown
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testObjectLoop1()
    {
        JSMarkedObject* o1 = new JSMarkedObject();
        JSMarkedObject* o2 = new JSMarkedObject();
        o1->setProperty("nested", o2);
        try
        {
            o2->setProperty("nested", o1);
        }
        catch(std::logic_error e)
        {
            delete o1;
            delete o2;
            return;
        }

        ASSERT_TRUE( false ); 
    }

    /*! Tests setting property for three objects, that makes reference counting impossible, so exception is thrown
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testObjectLoop2()
    {
        JSMarkedObject* o1 = new JSMarkedObject();
        JSMarkedObject* o2 = new JSMarkedObject();
        JSMarkedObject* o3 = new JSMarkedObject();
        o1->setProperty("nested", o2);
        o2->setProperty("nested", o3);

        try
        {
            o3->setProperty("nested", o1);
        }
        catch(std::logic_error e)
        {
            delete o1;
            delete o2;
            delete o3;
            return;
        }

        ASSERT_TRUE( false ); 
    }

    /*! Tests setting nested property
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetNestedProperty1()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        JSMarkedObject* child = new JSMarkedObject();
        child->setProperty("me", 22);

        selected_object = new JSMarkedObject();
        selected_object->setProperty("nested", child);

        ASSERT_TRUE( allocated_objects == 2);

        selected_object->registerAsGlobalVariable(ctx, "E");

        std::string error;

        {
            bool eval_result = ctx->eval("E.nested.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting nested property
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetNestedProperty2()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        JSMarkedObject* child = new JSMarkedObject();
        child->setProperty("me", 22);

        selected_object->registerAsGlobalVariable(ctx, "E");

        selected_object = new JSMarkedObject();
        selected_object->setProperty("nested", child);

        ASSERT_TRUE( allocated_objects == 2);

        std::string error;

        {
            bool eval_result = ctx->eval("E.nested.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting nested property
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetNestedProperty3()
    {
        allocated_objects = 0;
        std::string error;
        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        JSMarkedObject* child = new JSMarkedObject();
        child->setProperty("me", 22);

        ctx->registerCallable("f", mkf::from(returnSelectedObject));

        selected_object = new JSMarkedObject();

        {
            bool eval_result = ctx->eval("E = f();", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
        }

        ASSERT_TRUE( allocated_objects == 2);

        selected_object->setProperty("nested", child);

        {
            bool eval_result = ctx->eval("E.nested.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting nested property
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetNestedProperty4()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        JSMarkedObject* child = new JSMarkedObject();

        selected_object = new JSMarkedObject();
        selected_object->setProperty("nested", child);

        selected_object->registerAsGlobalVariable(ctx, "E");

        child->setProperty("me", 22);

        ASSERT_TRUE( allocated_objects == 2);

        std::string error;

        {
            bool eval_result = ctx->eval("E.nested.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting nested property
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetNestedProperty5()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        JSMarkedObject* child = new JSMarkedObject();

        selected_object = new JSMarkedObject();
        selected_object->setProperty("nested", child);

        ctx->registerCallable("f", mkf::from(returnSelectedObject));

        std::string error;

        {
            bool eval_result = ctx->eval("E = f();", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
        }

        child->setProperty("me", 22);

        ASSERT_TRUE( allocated_objects == 2);


        {
            bool eval_result = ctx->eval("E.nested.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting nested property
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetNestedProperty6()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        JSMarkedObject* child = new JSMarkedObject();

        selected_object = new JSMarkedObject();
        selected_object->registerAsGlobalVariable(ctx, "E");

        selected_object->setProperty("nested", child);

        child->setProperty("me", 22);

        ASSERT_TRUE( allocated_objects == 2);

        std::string error;

        {
            bool eval_result = ctx->eval("E.nested.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }

    /*! Tests setting nested property
     */
    // ReSharper disable once CppMemberFunctionMayBeConst
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void testSetNestedProperty7()
    {
        allocated_objects = 0;

        dukpp03::context::Context* ctx = new dukpp03::context::Context();

        JSMarkedObject* child = new JSMarkedObject();

        selected_object = new JSMarkedObject();

        ctx->registerCallable("f", mkf::from(returnSelectedObject));

        std::string error;

        {
            bool eval_result = ctx->eval("E = f();", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
        }

        selected_object->setProperty("nested", child);
        child->setProperty("me", 22);

        ASSERT_TRUE( allocated_objects == 2);


        {
            bool eval_result = ctx->eval("E.nested.me", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( result.value() == 22 );
        }

        delete ctx;

        ASSERT_TRUE( allocated_objects == 0);
    }
} js_object_test;
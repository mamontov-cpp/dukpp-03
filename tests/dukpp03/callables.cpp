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

compiledfunc func;

void set_func(const compiledfunc& f)
{
    func = f;
}

struct CallablesTest : tpunit::TestFixture
{
public:
    CallablesTest() : tpunit::TestFixture(
       TEST(CallablesTest::testRegisterVoidFunctions),
       TEST(CallablesTest::testRegisterReturnFunctions),
       TEST(CallablesTest::testMethods),
       TEST(CallablesTest::testPtrMethods),
       TEST(CallablesTest::testThisMethods),
       TEST(CallablesTest::testLocalProperty),
       TEST(CallablesTest::testRegisterAttribute), 
       TEST(CallablesTest::testCompiledFunction),
       TEST(CallablesTest::testCompiledFunction2),
       TEST(CallablesTest::testCompiledFunction3),
       TEST(CallablesTest::testGetterSetter),
       TEST(CallablesTest::testClassBindings),
       TEST(CallablesTest::testRebindMethods),
       TEST(CallablesTest::testPrototypeInheritance),
       TEST(CallablesTest::testSecondPrototypeInheritance),
       TEST(CallablesTest::testBetterInheritance),
       TEST(CallablesTest::testNativeFunctionPrototype)
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
    
    void testLocalProperty()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        Point pts2d(3,4);
        dukpp03::PushValue<Point, dukpp03::context::Context>::perform(&ctx, pts2d);
        ctx.registerImmutableProperty("_x", 2);
        ctx.registerImmutableProperty("x", bnd::from(&Point::x));
        ctx.markTopObjectAsGlobal("pnt");
        ctx.pop();

        bool eval_result = ctx.eval(" pnt._x + pnt.x() ", false,  &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( is_fuzzy_equal(result.value(), 5) );
    }
    
    void testRegisterAttribute()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        Point pts2d(3,4);
        dukpp03::PushValue<Point, dukpp03::context::Context>::perform(&ctx, pts2d);
        ctx.registerAtribute("x", bnd::from(&Point::x), true, bnd::from(&Point::setXS), true);
        ctx.markTopObjectAsGlobal("pnt");
        ctx.pop();

        bool eval_result = ctx.eval(" pnt.x = \"120\"; pnt.x ", false,  &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( is_fuzzy_equal(result.value(), 120) );
    }
    
    void testCompiledFunction()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        ASSERT_TRUE( ctx.getTop() == 0);
        ctx.registerCallable("setFunction", mkf::from(set_func));
        ASSERT_TRUE( ctx.getTop() == 0);

        bool eval_result = ctx.eval(" setFunction(function(a) { print(a); return a;  }); ", false,  &error);
        ctx.cleanStack();
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ASSERT_TRUE( ctx.getTop() == 0);
        ASSERT_TRUE( eval_result );
        ASSERT_TRUE( func.valid() );
        
        dukpp03::PushValue<int, dukpp03::context::Context>::perform(&ctx, 22);
        int evalresult = func.call(&ctx);
        ASSERT_TRUE(evalresult == 1);
        dukpp03::Maybe<int> result = dukpp03::GetValue<int, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == 22 );
    }
    
    void testCompiledFunction2()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        ASSERT_TRUE( ctx.getTop() == 0);
        ctx.registerCallable("setFunction", mkf::from(set_func));
        ASSERT_TRUE( ctx.getTop() == 0);

        bool eval_result = ctx.eval(" setFunction(function(a, b) { }); ", false,  &error);
        ctx.cleanStack();
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ASSERT_TRUE( ctx.getTop() == 0);
        ASSERT_TRUE( eval_result );
        ASSERT_TRUE( func.valid() );
        
        dukpp03::PushValue<int, dukpp03::context::Context>::perform(&ctx, 22);
        dukpp03::PushValue<int, dukpp03::context::Context>::perform(&ctx, 22);
        int evalresult = func.call(&ctx);
        ASSERT_TRUE(evalresult == 0);
    }
    
    void testCompiledFunction3()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        ASSERT_TRUE( ctx.getTop() == 0);
        ctx.registerCallable("setFunction", mkf::from(set_func));
        ASSERT_TRUE( ctx.getTop() == 0);

        bool eval_result = ctx.eval(" setFunction(function(a, b) { f = m + 2; cvrdze(); }); ", false,  &error);
        ctx.cleanStack();
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ASSERT_TRUE( ctx.getTop() == 0);
        ASSERT_TRUE( eval_result );
        ASSERT_TRUE( func.valid() );
        
        dukpp03::PushValue<int, dukpp03::context::Context>::perform(&ctx, 22);
        dukpp03::PushValue<int, dukpp03::context::Context>::perform(&ctx, 22);
        int evalresult = func.call(&ctx);

        ASSERT_TRUE(evalresult != 0 && evalresult != 1);
        dukpp03::Maybe<std::string> data = ctx.errorOnStack(-1);
        if (data.exists())
        {
             std::cout << data.value() << "\n";
        }
        ASSERT_TRUE(data.exists());
    }
    
    void testGetterSetter()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        Point pts2d(3,4);
        dukpp03::PushValue<Point, dukpp03::context::Context>::perform(&ctx, pts2d);
        ctx.registerAtribute("x", getter::from(&Point::m_x), true, setter::from(&Point::m_x), true);
        ctx.markTopObjectAsGlobal("pnt");
        ctx.pop();

        bool eval_result = ctx.eval(" pnt.x = 120; pnt.x ", false,  &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( is_fuzzy_equal(result.value(), 120) );
    }
    
    void testClassBindings()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        ClassBinding* c = new ClassBinding();
        c->addConstructor<Point>("Point");
        c->addConstructor<Point, int, int>("Point");
        c->addMethod("x",  bnd::from(&Point::x));
        c->addMethod("setX",  bnd::from(&Point::setX));

        c->addMethod("y",  bnd::from(&Point::y));
        c->addMethod("setY",  bnd::from(&Point::setY));
        
        c->addAccessor("m_x", getter::from(&Point::m_x), setter::from(&Point::m_x));
        c->addAccessor("m_y", getter::from(&Point::m_y), setter::from(&Point::m_y));
        ctx.addClassBinding(ctx.typeName<Point>(), c);
        
        {
            bool eval_result = ctx.eval(" var a = new Point(); a.setX(120); a.x() ", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 120) );
        }
        {
            bool eval_result = ctx.eval(" var a = new Point(120, 120); a.setY(120); a.y() ", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 120) );
        }
        
        {
            bool eval_result = ctx.eval(" var a = new Point(60, 0); var m = a.m_x; a.m_x = 60; a.m_x + m  ", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 120) );
        }
        
        {
            bool eval_result = ctx.eval(" var a = new Point(); a.m_y = 120; a.m_y ", false,  &error);
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
    
    void testRebindMethods()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        ClassBinding* c = new ClassBinding();
        c->addConstructor<Point3>("Point3");
        c->addConstructor<Point3, double, double, double>("Point3");
        c->addMethod("x",  bnd::from(&Point::x));
        c->addMethod("setX",  bnd::from(&Point::setX));

        c->addMethod("y",  bnd::from(&Point::y));
        c->addMethod("setY",  bnd::from(&Point::setY));
        
        c->addAccessor("x", rebind_method::to<Point3>::from<Point>(&Point::x),  rebind_method::to<Point3>::from<Point>(&Point::setX));
        c->addAccessor("y", rebind_method::to<Point3>::from<Point>(&Point::y),  rebind_method::to<Point3>::from<Point>(&Point::setY));
        c->addAccessor("z", bnd::from(&Point3::z),  bnd::from(&Point3::setZ));

        ctx.addClassBinding(ctx.typeName<Point3>(), c);

        {
            bool eval_result = ctx.eval(" var a = new Point3(2,3,4); a.x + a.y + a.z ", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 9) );
        }
    }

    void testPrototypeInheritance()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        ClassBinding* c = new ClassBinding();
        c->addConstructor<Point>("Point");
        c->addConstructor<Point, int, int>("Point");
        c->addMethod("x",  bnd::from(&Point::x));
        c->addMethod("setX",  bnd::from(&Point::setX));

        c->addMethod("y",  bnd::from(&Point::y));
        c->addMethod("setY",  bnd::from(&Point::setY));
        
        c->addAccessor("m_x", getter::from(&Point::m_x), setter::from(&Point::m_x));
        c->addAccessor("m_y", getter::from(&Point::m_y), setter::from(&Point::m_y));
        ctx.addClassBinding(ctx.typeName<Point>(), c);
        
        {
            bool eval_result = ctx.eval(" Point.prototype.f = function() { return 120; }; var a = new Point(); a.f() ", false,  &error);
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


    void testSecondPrototypeInheritance()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        ClassBinding* c = new ClassBinding();
        c->addConstructor<Point>("Point");
        c->addConstructor<Point, int, int>("Point");
        c->addMethod("x",  bnd::from(&Point::x));
        c->addMethod("setX",  bnd::from(&Point::setX));

        c->addMethod("y",  bnd::from(&Point::y));
        c->addMethod("setY",  bnd::from(&Point::setY));
        
        c->addAccessor("m_x", getter::from(&Point::m_x), setter::from(&Point::m_x));
        c->addAccessor("m_y", getter::from(&Point::m_y), setter::from(&Point::m_y));
        ctx.addClassBinding(ctx.typeName<Point>(), c);
        
        {
            bool eval_result = ctx.eval(
                "Point.prototype.f = function() { return 120; };"
                "var ChildPoint = function() { }, m = new Point();"
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
    }

    void testBetterInheritance()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        ClassBinding* c = new ClassBinding();
        c->addConstructor<Point>("Point");
        c->addConstructor<Point, int, int>("Point");
        c->addMethod("x",  bnd::from(&Point::x));
        c->addMethod("setX",  bnd::from(&Point::setX));

        c->addMethod("y",  bnd::from(&Point::y));
        c->addMethod("setY",  bnd::from(&Point::setY));
        
        c->addAccessor("m_x", getter::from(&Point::m_x), setter::from(&Point::m_x));
        c->addAccessor("m_y", getter::from(&Point::m_y), setter::from(&Point::m_y));
        ctx.addClassBinding(ctx.typeName<Point>(), c);
        
        {
            bool eval_result = ctx.eval(
                "Point.prototype.f = function() { return this.m_x; };"
                "var ChildPoint = function(a, b) { Object.setPrototypeOf(this, new Point(a,b)); };"
                "var a = new ChildPoint(1,2), b = new ChildPoint(9,3);"
                "a.f() + b.f() ", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 10) );
        }
    }

    void testNativeFunctionPrototype()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        ClassBinding* c = new ClassBinding();
        c->addConstructor<Point>("Point");
        c->addConstructor<Point, int, int>("Point");
        c->addMethod("x",  bnd::from(&Point::x));
        c->addMethod("setX",  bnd::from(&Point::setX));

        c->addMethod("y",  bnd::from(&Point::y));
        c->addMethod("setY",  bnd::from(&Point::setY));
        
        c->addAccessor("m_x", getter::from(&Point::m_x), setter::from(&Point::m_x));
        c->addAccessor("m_y", getter::from(&Point::m_y), setter::from(&Point::m_y));
        ctx.addClassBinding(ctx.typeName<Point>(), c);
        
        {
            bool eval_result = ctx.eval("var b = Point.call(0,10,2); b.m_x", false,  &error);
            if (!eval_result)
            {
                std::cout << error << "\n";
            }
            ASSERT_TRUE( eval_result );
            dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
            ASSERT_TRUE( result.exists() );
            ASSERT_TRUE( is_fuzzy_equal(result.value(), 10) );
        }
    }
    
} _callables_test;
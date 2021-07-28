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


//#define TEST_LAMBDA

#ifdef TEST_LAMBDA
    #include "lambda.h"
    #include "thislambda.h"
    typedef dukpp03::make_lambda<dukpp03::context::Context> mkl;
    typedef dukpp03::bind_lambda<dukpp03::context::Context> bl;
#endif

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

Point make()
{
    return Point(2,3);
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
       TEST(CallablesTest::testThisExplicitMethods),
#ifdef TEST_LAMBDA
       TEST(CallablesTest::testThisLambda),
#endif    
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
       TEST(CallablesTest::testNativeFunctionPrototype),
       TEST(CallablesTest::wrapValuePrototype),
#ifdef TEST_LAMBDA
       TEST(CallablesTest::testLambda),
#endif 
       TEST(CallablesTest::testCallGlobal0),
       TEST(CallablesTest::testCallGlobal1),
       TEST(CallablesTest::testCallGlobal2),
       TEST(CallablesTest::testCallGlobal3),
       TEST(CallablesTest::testCallGlobal4),
       TEST(CallablesTest::testCallGlobal5),
       TEST(CallablesTest::testCallGlobal6),
       TEST(CallablesTest::testCallGlobal7),
       TEST(CallablesTest::testCallGlobal8)
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

    void testThisExplicitMethods()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        register_constructor::in_context<Point, double, double>(&ctx, "pnt");
        ctx.registerCallable("x", bnd_exp::with_args_and_and_return_type0<Point, double>::from(&Point::x));
        ctx.registerCallable("y", bnd_exp::with_args_and_and_return_type0<Point, double>::from(&Point::y));

        ctx.registerCallable("setX", bnd_exp::with_args_and_no_return_type1<Point, double>::from(&Point::setX));
        ctx.registerCallable("setY", bnd_exp::with_args_and_no_return_type1<Point, double>::from(&Point::setY));

        bool eval_result = ctx.eval(" var f = pnt(3, 4); f.x = x; f.setX = setX;  f.setX(12);  f.x() ", false);
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( is_fuzzy_equal(result.value(), 12) );
    }

#ifdef TEST_LAMBDA
    void testThisLambda()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        register_constructor::in_context<Point, double, double>(&ctx, "pnt");
        std::function<double(Point*)> xl = [](Point* p) {
            return p->x();
        };
        std::function<double(Point*)> yl = [](Point* p) {
            return p->y();
        };
        ctx.registerCallable("x", bl::from(xl));
        ctx.registerCallable("y", bl::from(yl));

        std::function<void(Point*, double)> setxl = [](Point* p, double v) {
            return p->setX(v);
        };
        std::function<void(Point*, double)> setyl = [](Point* p, double v) {
            return p->setY(v);
        };
        ctx.registerCallable("setX", bl::from(setxl));
        ctx.registerCallable("setY", bl::from(setyl));

        bool eval_result = ctx.eval(" var f = pnt(3, 4); f.x = x; f.setX = setX; f.setX(12);  f.x() ", false, &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( is_fuzzy_equal(result.value(), 12) );
    }
#endif
    
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
        ctx.registerAttribute("x", bnd::from(&Point::x), true, bnd::from(&Point::setXS), true);
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
        if (evalresult != 1)
        {
            dukpp03::Maybe<std::string> val = ctx.errorOnStack(-1);
            if (val.exists())
            {
                std::cout << val.value() << "\n";
            }
        }
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
        ctx.registerAttribute("x", getter::from(&Point::m_x), true, setter::from(&Point::m_x), true);
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


    void wrapValuePrototype()
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
        c->setPrototypeFunction("Point");

        ctx.registerCallable("make", mkf::from(make));
        ctx.addClassBinding(ctx.typeName<Point>(), c);
        
        {
            bool eval_result = ctx.eval(" Point.prototype.f = function() { return 120; }; make().f() ", false,  &error);
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

#ifdef TEST_LAMBDA    
    void testLambda()
    {
        std::string error;
        dukpp03::context::Context ctx;

        std::function<int(int,int)> f = [](int a, int b) -> int {return a + b;};
        ctx.registerCallable("sum", mkl::from(f));
        std::function<void(int,int)> f2 = [](int a, int b) {  };
        ctx.registerCallable("null", mkl::from(f2));
        

        bool eval_result = ctx.eval("sum(2,3)", false, &error);
        std::cout << error << "\n";
        ASSERT_TRUE( eval_result );
        dukpp03::Maybe<double> result = dukpp03::GetValue<double, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        if (!is_fuzzy_equal(result.value(), 5)) 
        {
            std::cout << "Result is " << result.value() << "\n";
        }
        ASSERT_TRUE( is_fuzzy_equal(result.value(), 5) );
    }
#endif

    void testCallGlobal0()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        bool eval_result = ctx.eval("function test() { return \"string\"; }", true, &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ctx.callGlobalFunction("test");
        dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == "string" );
    }

    void testCallGlobal1()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        bool eval_result = ctx.eval("function test(a) { return \"string\" + a; }", true, &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ctx.callGlobalFunction("test", "test");
        dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == "stringtest" );
    }

    void testCallGlobal2()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        bool eval_result = ctx.eval("function test(a, b) { return a + b; }", true, &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ctx.callGlobalFunction("test", "1", "2");
        dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == "12" );
    }

    void testCallGlobal3()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        bool eval_result = ctx.eval("function test(a, b, c) { return a + b + c; }", true, &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ctx.callGlobalFunction("test", "1", "2", "3");
        dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == "123" );
    }

    void testCallGlobal4()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        bool eval_result = ctx.eval("function test(a, b, c, d) { return a + b + c + d; }", true, &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ctx.callGlobalFunction("test", "1", "2", "3", "4");
        dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == "1234" );
    }

    void testCallGlobal5()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        bool eval_result = ctx.eval("function test(a, b, c, d, e) { return a + b + c + d + e; }", true, &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ctx.callGlobalFunction("test", "1", "2", "3", "4", "5");
        dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == "12345" );
    }

    void testCallGlobal6()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        bool eval_result = ctx.eval("function test(a, b, c, d, e, f) { return a + b + c + d + e + f; }", true, &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ctx.callGlobalFunction("test", "1", "2", "3", "4", "5", "6");
        dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == "123456" );
    }

    void testCallGlobal7()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        bool eval_result = ctx.eval("function test(a, b, c, d, e, f, g) { return a + b + c + d + e + f + g; }", true, &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ctx.callGlobalFunction("test", "1", "2", "3", "4", "5", "6", "7");
        dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == "1234567" );
    }

    void testCallGlobal8()
    {
        std::string error;  
        
        dukpp03::context::Context ctx;
        bool eval_result = ctx.eval("function test(a, b, c, d, e, f, g, h) { return a + b + c + d + e + f + g + h; }", true, &error);
        if (!eval_result)
        {
            std::cout << error << "\n";
        }
        ctx.callGlobalFunction("test", "1", "2", "3", "4", "5", "6", "7", "8");
        dukpp03::Maybe<std::string> result = dukpp03::GetValue<std::string, dukpp03::context::Context>::perform(&ctx, -1);
        ASSERT_TRUE( result.exists() );
        ASSERT_TRUE( result.value() == "12345678" );
    }

} _callables_test;
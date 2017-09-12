#define TEST_INTERACTIVE
#define NO_POINT_BINDINGS
#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <cstdio>
#include <iostream>

#ifdef TEST_INTERACTIVE
    #include "context.h"
    #include "point.h"
#endif

#define _INC_STDIO
#include "include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)

duk_ret_t finalizer(duk_context* ctx)
{
	for(int i = 0; i < duk_get_top(ctx); i++)
	{
		printf("Object: %s\n", duk_to_string(ctx, i));
	}
	printf("Called fnalizer!");
	duk_call(ctx, 0);
	for(int i = 0; i < duk_get_top(ctx); i++)
	{
		printf("Object: %s\n", duk_to_string(ctx, i));
	}
    duk_enum(ctx, 0, DUK_ENUM_INCLUDE_NONENUMERABLE | DUK_ENUM_INCLUDE_HIDDEN);
    while (duk_next(ctx, -1, 1)) {
        printf("key=%s, value=%s\n", duk_to_string(ctx, -2), duk_to_string(ctx, -1));
        duk_pop_2(ctx);
    }
	duk_pop(ctx);
}


duk_ret_t retf(duk_context* ctx)
{
        printf("Called!\n");
        duk_push_object(ctx);

        // Set finalizer
        duk_push_c_function(ctx,  finalizer, 1);
        duk_set_finalizer(ctx, -1);

        duk_push_string(ctx, "test");   
        duk_put_prop_string(ctx, -2, "test");
        return 1;
}


int main(int argc, char** argv)
{
#ifdef TEST_INTERACTIVE
    dukpp03::context::Context t;
	duk_context* c = t.context();
	
	duk_push_global_object(c);
	duk_push_c_function(c, retf, DUK_VARARGS);
    duk_put_prop_string(c, -2 /*idx:global*/, "f");
    duk_pop(c);

    t.eval("var ef = function() { return f(); }");
#ifndef NO_POINT_BINDINGS
    ClassBinding* c = new ClassBinding();
    c->addConstructor<Point>("Point");
    c->addConstructor<Point, int, int>("Point");
    c->addMethod("x",  bnd::from(&Point::x));
    c->addMethod("setX",  bnd::from(&Point::setX));

    c->addMethod("y",  bnd::from(&Point::y));
    c->addMethod("setY",  bnd::from(&Point::setY));
    
    c->addAccessor("m_x", getter::from(&Point::m_x), setter::from(&Point::m_x));
    c->addAccessor("m_y", getter::from(&Point::m_y), setter::from(&Point::m_y));

    t.addClassBinding<Point>(c);
#endif
    bool exit = false;
    std::cout << "Interactive test shell. Type \"quit\" to quit\n";
    do 
    {
        std::cout << "test> ";
        std::string test, error;
        std::getline(std::cin, test);
        if (test == "quit")
        {
            exit = true;
        }
        else
        {
            bool res = t.eval(test, false, &error);
            if (!res)
            {
                std::cout << error << "\n";
            }
        }
    } while(!exit);
#else
    /**
     * Run all of the registered tpunit++ tests. Returns 0 if
     * all tests are successful, otherwise returns the number
     * of failing assertions.
     */
    int result = tpunit::Tests::Run();  
#endif
    return 0;
}

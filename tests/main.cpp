#pragma warning(push)
#pragma warning(disable: 4273)
#pragma warning(disable: 4351)
#include <cstdio>
#include <iostream>
#include "context.h"
#include "point.h"
#define _INC_STDIO
#include "include/3rdparty/tpunit++/tpunit++.hpp"
#pragma warning(pop)

//#define TEST_INTERACTIVE
int main(int argc, char** argv)
{
#ifdef TEST_INTERACTIVE
    dukpp03::context::Context t;
    register_constructor::in_context<Point, double, double>(&t, "Point2");
    register_constructor::in_context<Point>(&t, "Point1");
    
    dukpp03::MultiMethod<dukpp03::context::Context>* ctr = new dukpp03::MultiMethod<dukpp03::context::Context>();
    ctr->add(new dukpp03::Constructor0<dukpp03::context::Context, Point>());
    ctr->add(new dukpp03::Constructor2<dukpp03::context::Context, Point, double, double>());
    ctr->add(new dukpp03::Constructor2<dukpp03::context::Context, Point, std::string, std::string>());
    
    t.registerCallable("Point", ctr);
    t.registerCallable("x", mkm::from(&Point::x));
    t.registerCallable("y", mkm::from(&Point::y));

    t.registerCallable("setX", mkm::from(&Point::setX));
    t.registerCallable("setY", mkm::from(&Point::setY));
    
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

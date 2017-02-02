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

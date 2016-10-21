#include "test2.h"


Test2::Test2() : m_value(0)
{
    
}

Test2::Test2(int value) : m_value(value)
{
    
}

int Test2::get()
{
    return m_value;
}

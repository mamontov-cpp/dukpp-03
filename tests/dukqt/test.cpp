#include "test.h"
#include "test2.h"

#include <iostream>

// =================================== PUBLIC METHODS ===================================

Test::Test() : m_value(0)
{
    
}

Test::Test(int value) : m_value(value)
{
    
}

void Test::setValue(int value)
{
    m_value = value;
}

// ReSharper disable once CppMemberFunctionMayBeConst
int Test::getValue()
{
    return m_value;
}

// =================================== PUBLIC SLOTS ===================================

// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
int Test::return3()
{
    return 3;
}

// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
Test2* Test::returnDerived(int a)
{
    return new Test2(a);
}

// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
Test::ValueHolder Test::returnHolder()
{
    return Test::ValueHolder(m_value);
}

// ReSharper disable once CppMemberFunctionMayBeStatic
// ReSharper disable once CppMemberFunctionMayBeConst
Test::ValueHolder* Test::returnHolderPtr()
{
    return new Test::ValueHolder(m_value);    
}


void Test::deleteHolder(Test::ValueHolder* ptr)
{
    delete ptr;
}

// =================================== PUBLIC Test::ValueHolder ===================================

Test::ValueHolder::ValueHolder() : Value(0)
{
    
}

Test::ValueHolder::ValueHolder(int v) : Value(v)
{
    
}

void Test::ValueHolder::printValue() const
{
    std::cout << "Test::ValueHolder(" << Value << ")\n";
}

int Test::ValueHolder::getValue() const
{
    return Value;
}
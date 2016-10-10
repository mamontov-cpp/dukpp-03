#include "point.h"
#include <sstream>
#include <iostream>

Point::Point() : m_x(0), m_y(0)
{

}

Point::Point(int x, int y) : m_x(x), m_y(y)
{

}

Point::Point(const std::string& s1, const std::string& s2)
{
    std::cout << "String constructor\n";
    std::istringstream str1(s1);
    str1 >> m_x;
    std::istringstream str2(s2);
    str2 >> m_y; 
}

void Point::setX(int x)
{
    this->m_x = x;
}

void Point::setY(int y)
{
    this->m_y = y;
}

int Point::x() const
{
    return m_x;
}

int Point::y() const
{
    return m_y;
}
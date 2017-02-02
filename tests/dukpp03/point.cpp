#include "point.h"
#include <sstream>
#include <iostream>

Point::Point() : m_x(0), m_y(0)
{

}

Point::Point(int x, int y) : m_x(x), m_y(y)
{

}

Point::Point(const std::string& s1, const std::string& s2) : m_x(0), m_y(0)
{
    std::cout << "String constructor\n";
    std::istringstream str1(s1);
    str1 >> m_x;
    std::istringstream str2(s2);
    str2 >> m_y; 
}


Point::Point(double x, double y) : m_x(static_cast<int>(x)), m_y(static_cast<int>(y))
{
    
}

void Point::setX(int x)
{
    this->m_x = x;
}

void Point::setXS(const std::string& s)
{
    std::cout << "Point::setXS\n";
    std::istringstream str1(s);
    str1 >> m_x;
}

void Point::setY(int y)
{
    this->m_y = y;
}

void Point::setYS(const std::string& s)
{
    std::cout << "Point::setYS\n";
    std::istringstream str1(s);
    str1 >> m_y;
}

int Point::x() const
{
    return m_x;
}

int Point::y() const
{
    return m_y;
}

int Point::xv(const std::string& r) const
{
    std::cout << r << "\n";
    return m_x;
}

void Point::setXV(int x, const std::string& r)
{
    std::cout << r << "\n";
    this->m_x = x;
}


Point3::Point3() : Point(0, 0), m_z(0)
{

}

Point3::Point3(double x, double y, double z) : Point(x, y), m_z(z)
{

}

void Point3::setZ(int z)
{
    m_z = z;
}

int Point3::z() const
{
    return m_z;
}
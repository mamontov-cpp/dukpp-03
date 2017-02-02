/*! \file point.h

    Defines a simple point for testing
 */
#pragma once
#include <math.h>
#include <iostream>


/*! A simple point for testing
 */
struct Point
{
    /*! X coordinate
     */
    int m_x;
    /*! Y coordinate
     */
    int m_y;
    
    /*! Constructs new point
     */
    Point();
    /*! Reads point coordinate from string
        \param[in] s1 first string
        \param[in] s2 second string
     */
    Point(const std::string& s1, const std::string& s2);
    /*! Constructs new point
        \param[in] x first coordinate
        \param[in] y second coordinate
     */
    Point(int x, int y);
    /*! Constructs new point
        \param[in] x first coordinate
        \param[in] y second coordinate
     */
    Point(double x, double y);


    /*! Sets x coordinate
        \param[in] x x coordinate
     */
    void setX(int x);
    /*! Sets x coordiate from string
        \param[in] s string
     */
    void setXS(const std::string& s);
    
    /*! Sets y coordinate
        \param[in] y y coordinate
     */
    void setY(int y);
    /*! Sets y coordiate from string
        \param[in] s string
     */
    void setYS(const std::string& s);
    
    /*! A simple string-passing getter
        \param[in] s a getter
        \return value
     */
    int xv(const std::string& s) const;
    /*! A simple string-passing setter
        \param[in] s a setter
        \param[in] x a value
     */
    void setXV(int x, const std::string& s);
    /*! Returns x coordinate
        \return x coordinate
     */ 
    int x() const;

    /*! Returns y coordinate
        \return y coordinate
     */
    int y() const;
};

/*! A point with third point (Z)
 */
struct Point3: public Point
{
    /*! A z-coordinate
     */
    int m_z;

    /*! A default constructor
     */
    Point3();

    /*! Constructs new point
        \param[in] x first coordinate
        \param[in] y second coordinate
     */
    Point3(double x, double y, double z);

    /*! Sets z coordinate
        \param[in] z z coordinate
     */
    void setZ(int z);
    /*! Returns z coordinate
        \return z coordinate
     */
    int z() const;
};

/*! Tests if two double values are equal with precision of 0.001
    \param[in] a first part
    \param[in] b second part
 */
inline bool is_fuzzy_equal(double a, double b)
{
    return fabs(a - b) < 0.001;
}
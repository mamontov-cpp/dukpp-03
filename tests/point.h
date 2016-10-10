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
    /*! Constructs new point
        \param[in] x first coordinate
        \param[in] y second coordinate
     */
    Point(int x, int y);

    /*! Sets x coordinate
        \param[in] x x coordinate
     */
    void setX(int x);
    
    /*! Sets y coordinate
        \param[in] y y coordinate
     */
    void setY(int y);
    
    /*! Returns x coordinate
        \return x coordinate
     */ 
    int x() const;

    /*! Returns y coordinate
        \return y coordinate
     */
    int y() const;
};

/*! Tests if two double values are equal with precision of 0.001
    \param[in] a first part
    \param[in] b second part
 */
inline bool is_fuzzy_equal(double a, double b)
{
    return fabs(a - b) < 0.001;
}
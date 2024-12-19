//
//  Point.cpp
//  HW2.5_Exercise3
//
//  Created by Zhihao Shan on 2023/6/15.
//
// Defines Point class member functions

#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>


// Default constructor
Point::Point()
{
    m_x = m_y = 0.0;
}

// Constructor with parameters
Point::Point(double x, double y)
{
    m_x = x;
    m_y = y;
}

// Copy constructor
Point::Point(const Point& pt)
{
    m_x = pt.X();
    m_y = pt.Y();
}

// Destructor
Point::~Point()
{
}

// Getter for x
double Point::X() const
{
    return m_x;
}

// Setter for x
void Point::X(double newX)
{
    m_x = newX;
}

// Getter for y
double Point::Y() const
{
    return m_y;
}

// Setter for y
void Point::Y(double newY)
{
    m_y = newY;
}

// Convert point to string
string Point::ToString() const
{
    std::stringstream ss;
    ss << "Point(" << m_x << "," << m_y << ")";
    
    return ss.str();
}

// Calculate distance from origin
double Point::Distance() const
{
    return std::sqrt(m_x*m_x+m_y*m_y);
}

// Calculate distance between two points
double Point::Distance(const Point& pt) const
{
    return std::sqrt((m_x-pt.m_x)*(m_x-pt.m_x)+(m_y-pt.m_y)*(m_y-pt.m_y));
}

// Overloaded unary minus
Point Point::operator - () const
{
    return Point(-m_x,-m_y);
}

// Overloaded multiplication
Point Point::operator * (double factor) const
{
    return Point(m_x*factor, m_y*factor);
}

// Overloaded addition
Point Point::operator + (const Point& p) const
{
    return Point(m_x + p.m_x, m_y + p.m_y);
}

// Overloaded equality
bool Point::operator == (const Point& p) const
{
    return (m_x == p.m_x) && (m_y == p.m_y);
}

// Overloaded assignment
Point& Point::operator = (const Point& source)
{
    if (this == &source)
        return *this;

    m_x = source.m_x;
    m_y = source.m_y;

    return *this;
}

//-------------------------------------------------------------------
// Exercise 1 Start

// Overloaded multiplication assignment
Point& Point::operator *= (double factor)
{
    m_x *= factor;
    m_y *= factor;
    return *this;
}

//--------------------------------------------------------------------
// Exercise4 Start

// friend ostream << operator
ostream& operator << (ostream& os, const Point& p)
{
    return os << "Point(" << p.m_x << "," << p.m_y << ")";
}

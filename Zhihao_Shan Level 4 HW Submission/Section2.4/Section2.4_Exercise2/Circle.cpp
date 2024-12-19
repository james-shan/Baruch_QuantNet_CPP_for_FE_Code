//
//  Circle.cpp
//  HW2.4_Exercise2
//
//  Created by Zhihao Shan on 2023/6/15.
//
// Defines Circle class

#include "Point.hpp"
#include "Circle.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

// Default constructor
Circle::Circle()
{
    m_cp = Point(0,0);
    m_radius = 1;
}

// Constructor with parameters
Circle::Circle(const Point& cp, const double& radius)
{
    m_cp = cp;
    m_radius = radius;
}

// Copy constructor
Circle::Circle(const Circle& other)
{
    m_cp = other.CenterPoint();
    m_radius = other.Radius();
}

// Destructor
Circle::~Circle()
{
}

// Getter for center point
Point Circle::CenterPoint() const
{
    return m_cp;
}

// Setter for center point
void Circle::CenterPoint(const Point& cp)
{
    m_cp = cp;
}

// Getter for radius
double Circle::Radius() const
{
    return m_radius;
}

// Setter for radius
void Circle::Radius(const double& radius)
{
    m_radius = radius;
}

// Calculate diameter
double Circle::Diameter() const
{
    return 2*this->Radius();
}

// Calculate area
double Circle::Area() const
{
    return this->Radius()*this->Radius()*M_PI;
}

// Calculate circumference
double Circle::Circumference() const
{
    return 2*this->Radius()*M_PI;
}

// Convert to string
string Circle::ToString() const
{
    stringstream ss;
    ss << "Circle has Centerpoint " << this->CenterPoint().ToString() << " and radius of " << this->Radius();
    return ss.str();
}

//----------------------------------------------------------
// Exercise 1 Start

// Overloaded assignment
Circle& Circle::operator = (const Circle& source)
{
    if (this == &source)
        return *this;

    m_cp = source.m_cp;
    m_radius = source.m_radius;

    return *this;
}


//--------------------------------------------------------------------
// Exercise2 Start

// Ostream << Operator
ostream& operator << (ostream& os, const Circle& c)
{
    return os << c.ToString() << endl;
}


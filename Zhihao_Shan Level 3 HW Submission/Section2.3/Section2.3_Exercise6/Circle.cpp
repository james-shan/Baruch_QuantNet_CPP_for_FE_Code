//
//  Circle.cpp
//  HW2.3_Exercise6
//
//  Created by Zhihao Shan on 2023/6/11.
//

#define _USE_MATH_DEFINES
#include "Point.hpp"
#include "Circle.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

Circle::Circle()
{
    // Default constructor: Initialize m_cp to (0,0) and m_radius to 1
    m_cp = Point(0, 0);
    m_radius = 1;
    
    // Print a message indicating that the Circle object is being constructed by default
    cout << "Circle Constructed by default." << endl;
}

Circle::Circle(const Point& cp, const double& radius)
{
    // Constructor with center point and radius: Initialize m_cp and m_radius with the provided values
    m_cp = cp;
    m_radius = radius;
    
    // Print a message indicating that the Circle object is being constructed using direct input
    cout << this->ToString() << " constructed by direct input." << endl;
}

Circle::Circle(const Circle& other)
{
    // Copy constructor: Initialize m_cp and m_radius with the center point and radius of the provided Circle object (other)
    m_cp = other.CenterPoint();
    m_radius = other.Radius();
    
    // Print a message indicating that the Circle object is being constructed by copy
    cout << this->ToString() << " constructed by copy." << endl;
}

Circle::~Circle()
{
    // Destructor: Print a message indicating that the Circle object is being destructed
    cout << this->ToString() << " destructed." << endl;
}

Point Circle::CenterPoint() const
{
    // Getter for the center point: Return the m_cp
    return m_cp;
}

void Circle::CenterPoint(const Point& cp)
{
    // Setter for the center point: Set the m_cp to the provided cp
    m_cp = cp;
}

double Circle::Radius() const
{
    // Getter for the radius: Return the m_radius
    return m_radius;
}

void Circle::Radius(const double& radius)
{
    // Setter for the radius: Set the m_radius to the provided radius
    m_radius = radius;
}

double Circle::Diameter() const
{
    // Calculate and return the diameter of the circle
    return 2 * this->Radius();
}

double Circle::Area() const
{
    // Calculate and return the area of the circle
    return this->Radius() * this->Radius() * M_PI;
}

double Circle::Circumference() const
{
    // Calculate and return the circumference of the circle
    return 2 * this->Radius() * M_PI;
}

string Circle::ToString() const
{
    // Generate a string representation of the Circle object
    stringstream ss;
    ss << "Circle has Centerpoint" << this->CenterPoint().ToString() << " and radius of " << this->Radius();
    
    // Retrieve the string from the string buffer
    return ss.str();
}


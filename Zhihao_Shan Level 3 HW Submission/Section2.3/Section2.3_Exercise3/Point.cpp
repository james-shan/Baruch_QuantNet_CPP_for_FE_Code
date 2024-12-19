//
//  Point.cpp
//  HW2.3_Exercise3
//
//  Created by Zhihao Shan on 2023/6/10.
//

#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

Point::Point()
{
    // Default constructor: Initialize m_x and m_y to 0.0
    m_x = m_y = 0.0;
    
    // Print a message indicating that the Default Point is being constructed
    std::cout << "Default Point constructed" << std::endl;
}

Point::Point(double x, double y)
{
    // Constructor with user input: Initialize m_x and m_y with the provided values
    m_x = x;
    m_y = y;
    
    // Print a message indicating that the Point object is being constructed using user input
    std::cout << this->ToString() << " constructed by user input" << std::endl;
}

Point::Point(const Point& pt)
{
    // Copy constructor: Initialize m_x and m_y with the values of the provided Point object (pt)
    m_x = pt.X();  // Access the X coordinate of pt using the member function X()
    m_y = pt.Y();  // Access the Y coordinate of pt using the member function Y()
    
    // Print a message indicating that the Point object is being constructed by copy
    std::cout << this->ToString() << " constructed by copy" << std::endl;
}

Point::~Point()
{
    // Destructor: Print a message indicating that the Point object is being destructed
    std::cout << this->ToString() << " destructed" << std::endl;
}

// function overloading
double Point::X() const
{
    // Return the value of m_x
    return m_x;
}

// function overloading
void Point::X(double newX)
{
    // Set the value of m_x to the provided newX value
    m_x = newX;
}

// function overloading
double Point::Y() const
{
    // Return the value of m_y
    return m_y;
}

// function overloading
void Point::Y(double newY)
{
    // Set the value of m_y to the provided newY value
    m_y = newY;
}

string Point::ToString() const
{
    // Create a string stream object to build the string representation
    std::stringstream ss;
    
    // Format the string as "Point(x, y)"
    ss << "Point(" << m_x << "," << m_y << ")";
    
    // Retrieve the string from the string buffer
    return ss.str();
}

// function overloading
double Point::Distance() const
{
    // Calculate the Euclidean distance from the origin (0,0)
    return std::sqrt(m_x * m_x + m_y * m_y);
}

// function overloading
double Point::Distance(const Point& pt) const
{
    // Calculate the Euclidean distance between the current point and the provided point (pt)
    return std::sqrt((m_x - pt.X()) * (m_x - pt.X()) + (m_y - pt.Y()) * (m_y - pt.Y()));
}

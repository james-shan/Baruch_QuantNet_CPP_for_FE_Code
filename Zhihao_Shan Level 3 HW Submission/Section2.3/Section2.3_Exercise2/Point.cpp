//
//  Point.cpp
//  HW2.3_Exercise2
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
    m_x = pt.getX();
    m_y = pt.getY();
    
    // Print a message indicating that the Point object is being constructed by copy
    std::cout << this->ToString() << " constructed by copy" << std::endl;
}

Point::~Point()
{
    // Destructor: Print a message indicating that the Point object is being destructed
    std::cout << this->ToString() << " destructed" << std::endl;
}

double Point::getX() const
{
    // Return the value of m_x
    return m_x;
}

void Point::setX(double newX)
{
    // Set the value of m_x to the provided newX value
    m_x = newX;
}

double Point::getY() const
{
    // Return the value of m_y
    return m_y;
}

void Point::setY(double newY)
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

double Point::DistanceOrigin() const
{
    // Calculate the Euclidean distance from the origin (0,0)
    return std::sqrt(m_x * m_x + m_y * m_y);
}

double Point::Distance(const Point& pt) const
{
    // Calculate the Euclidean distance between the current point and the provided point (pt)
    
    // changing pt would cause compiler error
    // pt.setX(0.1); (Caution, Uncommenting this would cause compiler error)
    return std::sqrt((m_x-pt.m_x)*(m_x-pt.m_x)+(m_y-pt.m_y)*(m_y-pt.m_y));
}

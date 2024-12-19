//
//  Point.cpp
//  HW2.2_Exercise2
//
//  Created by Zhihao Shan on 2023/6/10.
//
// This files defines the member functions of Point class

#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

Point::Point()
{
    // Initialize the member variables m_x and m_y to 0.0
    m_x = m_y = 0.0;
}

Point::~Point()
{
    // Destructor: empty for now
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

double Point::Distance(Point pt) const
{
    // Calculate the Euclidean distance between the current point and the provided point (pt)
    return std::sqrt((m_x - pt.m_x) * (m_x - pt.m_x) + (m_y - pt.m_y) * (m_y - pt.m_y));
}


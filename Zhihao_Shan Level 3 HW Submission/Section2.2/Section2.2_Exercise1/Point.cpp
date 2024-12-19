//
//  Point.cpp
//  HW2.2_Exercise1
//
//  Created by Zhihao Shan on 2023/6/10.
//
// This files defines the member functions of Point class

#include "Point.hpp" // Including the header file for the Point class
#include <iostream> // Including the standard input/output stream
#include <sstream>  // Including the string stream
#include <string>   // Including the string library


Point::Point()
{
    m_x = m_y = 0.0; // Initializing both x and y coordinates to 0.0
}

Point::~Point()
{
    // Destructor implementation (empty in this case)
}

double Point::getX() const
{
    return m_x; // Return the x coordinate of the point
}

void Point::setX(double newX)
{
    m_x = newX; // Set the x coordinate of the point to the given value
}

double Point::getY() const
{
    return m_y; // Return the y coordinate of the point
}

void Point::setY(double newY)
{
    m_y = newY; // Set the y coordinate of the point to the given value
}

string Point::ToString() const
{
    std::stringstream ss; // Create a string stream object to build the string representation of the point
    ss << "Point(" << m_x << "," << m_y << ")"; // Insert the x and y coordinates into the string stream
    
    return ss.str(); // Retrieve the string from the string buffer and return it as the string representation of the point
}

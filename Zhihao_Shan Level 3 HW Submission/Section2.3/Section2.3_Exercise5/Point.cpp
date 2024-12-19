//
//  Point.cpp
//  HW2.3_Exercise5
//
//  Created by Zhihao Shan on 2023/6/10.
//
// This file defines the functions of Point Class

#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>


// Default constructor
Point::Point()
{
    // Initialize m_x and m_y to 0.0
    m_x = m_y = 0.0;
    
    // Print a message indicating that the Default Point is being constructed
    //std::cout << "Default Point constructed" << std::endl;
}

// Constructor with user input
Point::Point(double x, double y)
{
    // Initialize m_x and m_y with the provided values
    m_x = x;
    m_y = y;
    
    // Print a message indicating that the Point object is being constructed using user input
    //std::cout << this->ToString() << " constructed by user input" << std::endl;
}

// Copy constructor
Point::Point(const Point& pt)
{
    // Initialize m_x and m_y with the values of the provided Point object (pt)
    m_x = pt.X();  // Access the X coordinate of pt using the member function X()
    m_y = pt.Y();  // Access the Y coordinate of pt using the member function Y()
    
    // Print a message indicating that the Point object is being constructed by copy
    //std::cout << this->ToString() << " constructed by copy" << std::endl;
}

// Destructor
Point::~Point()
{
    // Print a message indicating that the Point object is being destructed
    //std::cout << this->ToString() << " destructed" << std::endl;
}

// Getter for the X coordinate
// Const function
double Point::X() const
{
    // Return the value of m_x
    return m_x;
}

// Setter for the X coordinate
void Point::X(double newX)
{
    // Set the value of m_x to the provided newX value
    m_x = newX;
}

// Getter for the Y coordinate
// Const function
double Point::Y() const
{
    // Return the value of m_y
    return m_y;
}

// Setter for the Y coordinate
void Point::Y(double newY)
{
    // Set the value of m_y to the provided newY value
    m_y = newY;
}

// Generate a string representation of the Point object
// Const function
std::string Point::ToString() const
{
    // Create a string stream object to build the string representation
    std::stringstream ss;
    
    // Format the string as "Point(x, y)"
    ss << "Point(" << m_x << "," << m_y << ")";
    
    // Retrieve the string from the string buffer
    return ss.str();
}

// Calculate the Euclidean distance from the origin (0,0)
// Const function
double Point::Distance() const
{
    return std::sqrt(m_x * m_x + m_y * m_y);
}

// Calculate the Euclidean distance between two Point objects
// Const function
double Point::Distance(const Point& pt) const
{
    return std::sqrt((m_x - pt.X()) * (m_x - pt.X()) + (m_y - pt.Y()) * (m_y - pt.Y()));
}


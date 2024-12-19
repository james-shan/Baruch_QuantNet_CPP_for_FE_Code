//
//  Line.cpp
//  HW2.4_Exercise4
//
//  Created by Zhihao Shan on 2023/6/15.
//
// Defines Line class

#include "Line.hpp"
#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>

// Default constructor
Line::Line()
{
    start_p = Point(0,0);
    end_p = Point(0,0);
}

// Constructor with parameters
Line::Line(const Point& new_start_p, const Point& new_end_p)
{
    start_p = new_start_p;
    end_p = new_end_p;
}

// Copy constructor
Line::Line(const Line& other)
{
    start_p = other.StartPoint();
    end_p = other.EndPoint();
}

// Destructor
Line::~Line()
{
}

// Getter for start point
Point Line::StartPoint() const
{
    return start_p;
}

// Setter for start point
void Line::StartPoint(const Point& newstart)
{
    start_p = newstart;
}

// Getter for end point
Point Line::EndPoint() const
{
    return end_p;
}

// Setter for end point
void Line::EndPoint(const Point& newend)
{
    end_p = newend;
}

// Convert line to string
string Line::ToString() const
{
    std::stringstream ss;
    ss << "Line starts at Point(" << start_p.X() << "," << start_p.Y() << ") and ends at Point(" << end_p.X() << "," << end_p.Y() << ")";
    return ss.str();
}

// Calculate line length
double Line::Length() const
{
    return StartPoint().Distance(EndPoint());
}

//----------------------------------------------------------
// Exercise 1 Start

// Overloaded assignment
Line& Line::operator = (const Line& source)
{
    if (this == &source)
        return *this;

    start_p = source.start_p;
    end_p = source.end_p;

    return *this;
}

//--------------------------------------------------------------------
// Exercise4 Start

// friend ostream << operator
ostream& operator << (ostream& os, const Line& l)
{
    // using friend << operator from Point class
    return os << "Line starts at " << l.start_p << " and ends at " << l.end_p << endl;
}

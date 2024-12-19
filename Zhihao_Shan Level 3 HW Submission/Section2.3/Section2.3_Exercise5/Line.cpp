//
//  Line.cpp
//  HW2.3_Exercise5
//
//  Created by Zhihao Shan on 2023/6/11.
//
// This file defines functions of Line Class
#include "Line.hpp"
#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>

Line::Line()
{
    // Default constructor: Initialize start_p and end_p to (0,0)
    start_p = Point(0, 0);
    end_p = Point(0, 0);
}

Line::Line(const Point& new_start_p, const Point& new_end_p)
{
    // Constructor with start and end points: Initialize start_p and end_p with the provided points
    start_p = new_start_p;
    end_p = new_end_p;
}

Line::Line(const Line& other)
{
    // Copy constructor: Initialize start_p and end_p with the start and end points of the provided Line object (other)
    start_p = other.StartPoint();
    end_p = other.EndPoint();
}

Line::~Line()
{
    // Destructor: Print a message indicating that the Line object is being destructed
    cout << this->ToString() << " destructed" << endl;
}

Point Line::StartPoint() const
{
    // Getter for the start point: Return the start_p
    return start_p;
}

void Line::StartPoint(const Point& newstart)
{
    // Setter for the start point: Set the start_p to the provided newstart
    start_p = newstart;
}

Point Line::EndPoint() const
{
    // Getter for the end point: Return the end_p
    return end_p;
}

void Line::EndPoint(const Point& newend)
{
    // Setter for the end point: Set the end_p to the provided newend
    end_p = newend;
}

string Line::ToString() const
{
    // Generate a string representation of the Line object
    std::stringstream ss;
    ss << "Line starts at Point(" << start_p.X() << "," << start_p.Y() << ") and ends at Point(" << end_p.X() << "," << end_p.Y() << ")";
    
    // Retrieve the string from the string buffer
    return ss.str();
}

double Line::Length() const
{
    // Calculate the length of the line using the Distance function of the Point class
    return StartPoint().Distance(EndPoint());
}


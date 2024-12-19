//
// Line.cpp
//  Section3.5_Exercise5
//
// Created by Zhihao Shan on 2023/6/16.
//
//  defines functions of Line class

#include "Line.hpp"
#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>


// Line default constructor
Line::Line(): start_p(), end_p() {}

// Line constructor with start point and end point parameters
Line::Line(const Point& new_start_p, const Point& new_end_p): start_p(new_start_p), end_p(new_end_p) {}

// Line copy constructor
Line::Line(const Line& other): start_p(other.StartPoint()), end_p(other.EndPoint()) {}

// Line destructor
Line::~Line()
{
    //cout<<"Line destructed"<<endl;
}


// Overload the assignment operator for the Line class
Line& Line::operator = (const Line& source)
{
    
    if (this == &source) // avoid self-assignment
        return *this;
    
    Shape::operator = (source); // call the assignment operator of shape to copy id
    start_p = source.start_p;
    end_p = source.end_p;
    
    return *this;
}

// Get the start point of the line
Point Line::StartPoint() const
{
    return start_p;
}

// Set the start point of the line
void Line::StartPoint(const Point& newstart)
{
    start_p = newstart;
}

// Get the end point of the line
Point Line::EndPoint() const
{
    return end_p;
}

// Set the end point of the line
void Line::EndPoint(const Point& newend)
{
    end_p = newend;
}

// Convert the line to a string representation
string Line::ToString() const
{
    std::stringstream ss;
    std::string s=Shape::ToString(); // calling base class ToString to print iD
    ss << "Line starts at Point(" << start_p.X() << "," << start_p.Y() << ") and ends at Point(" << end_p.X() << "," << end_p.Y() << "), "<<s;
    
    return ss.str();  // Retrieve the string from the string buffer
}

// Calculate the length of the line
double Line::Length() const
{
    return StartPoint().Distance(EndPoint());
}

// Overload the output stream operator for the Line class
ostream& operator << (ostream& os, const Line& l)
{
    return os << l.ToString() << endl;
}

// Draw function to simulate drawing
void Line::Draw()
{
    cout<< "Drawing a Line" << endl;
}


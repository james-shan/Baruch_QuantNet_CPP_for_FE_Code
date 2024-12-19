//
// Line.cpp
// Section3.4_Exercise1
//
// Created by Zhihao Shan on 2023/6/16.
//

#include "Line.hpp"
#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace ZHIHAO::CAD;

namespace ZHIHAO
{
    namespace CAD
    {
        // Line default constructor
        Line::Line(): start_p(), end_p() {}

        // Line constructor with start point and end point parameters
        Line::Line(const Point& new_start_p, const Point& new_end_p): start_p(new_start_p), end_p(new_end_p) {}

        // Line copy constructor
        Line::Line(const Line& other): start_p(other.StartPoint()), end_p(other.EndPoint()) {}

        // Line destructor
        Line::~Line()
        {
            //cout<<this->ToString()<<" destructed"<<endl;
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
            ss << "Line starts at Point(" << start_p.X() << "," << start_p.Y() << ") and ends at Point(" << end_p.X() << "," << end_p.Y() << ")";
            
            return ss.str();  // Retrieve the string from the string buffer
        }

        // Calculate the length of the line
        double Line::Length() const
        {
            return StartPoint().Distance(EndPoint());
        }

        //----------------------------------------------------------
        // Exercise 1 Start
        // Overload the assignment operator for the Line class
        Line& Line::operator = (const Line& source)
        {
            
            if (this == &source)
                return *this;
            
            start_p = source.start_p;
            end_p = source.end_p;
            
            return *this;
        }

        //--------------------------------------------------------------------
        // Exercise2 Start
        // Overload the output stream operator for the Line class
        ostream& operator << (ostream& os, const Line& l)
        {
            return os << l.ToString() << endl;
        }

    }

}



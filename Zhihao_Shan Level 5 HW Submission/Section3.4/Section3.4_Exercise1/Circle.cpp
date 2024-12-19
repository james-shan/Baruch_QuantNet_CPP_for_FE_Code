//
// Circle.cpp
// Section3.4_Exercise1
//
// Created by Zhihao Shan on 2023/6/16.
//

// Include necessary headers and libraries
#define _USE_MATH_DEFINES
#include "Point.hpp"
#include "Circle.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace ZHIHAO::CAD;

namespace ZHIHAO
{

    namespace CAD
    {
        // Circle default constructor
        Circle::Circle(): m_cp(0.0,0.0), m_radius(1) {}
        

        // Circle constructor with center point and radius parameters
        Circle::Circle(const Point& cp, const double& radius): m_cp(cp), m_radius(radius) {}

        // Circle copy constructor
        Circle::Circle(const Circle& other): m_cp(other.CenterPoint()), m_radius(other.Radius()) {}

        // Circle destructor
        Circle::~Circle()
        {
            //cout<<this->ToString()<<" destructed."<<endl;
        }

        // Get the center point of the circle
        Point Circle::CenterPoint() const
        {
            return m_cp;
        }

        // Set the center point of the circle
        void Circle::CenterPoint(const Point& cp)
        {
            m_cp = cp;
        }

        // Get the radius of the circle
        double Circle::Radius() const
        {
            return m_radius;
        }

        // Set the radius of the circle
        void Circle::Radius(const double& radius)
        {
            m_radius = radius;
        }

        // Calculate the diameter of the circle
        double Circle::Diameter() const
        {
            return 2*this->Radius();
        }

        // Calculate the area of the circle
        double Circle::Area() const
        {
            return this->Radius()*this->Radius()*M_PI;
        }

        // Calculate the circumference of the circle
        double Circle::Circumference() const
        {
            return 2*this->Radius()*M_PI;
        }

        // Convert the circle to a string representation
        string Circle::ToString() const
        {
            stringstream ss;
            ss << "Circle has Centerpoint" << this->CenterPoint().ToString() << " and radius of " << this->Radius();
            
            return ss.str();
        }

        //--------------------------------------------------------
        // Exercise1 Start

        // Overload the assignment operator for the Circle class
        Circle& Circle::operator = (const Circle& source)
        {
            if (this == &source)
                return *this;
            
            m_cp = source.m_cp;
            m_radius = source.m_radius;
            
            return *this;
        }

        // Overload the output stream operator for the Circle class
        ostream& operator << (ostream& os, const Circle& c)
        {
            return os << c.ToString() << endl;
        }

    }

}

//
//  Point.cpp
//  HW2.6_Exercise1
//
//  Created by Zhihao Shan on 2023/6/16.
//

#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace ZHIHAO::CAD;

// include Point member functions to CAD
namespace ZHIHAO
{
    namespace CAD
    {
        // Default constructor
        Point::Point()
        {
            m_x = m_y = 0.0;
            std::cout<<"Default Point constructed"<<endl;
        }

        // Constructor with user input
        Point::Point(double x, double y)
        {
            m_x = x;
            m_y = y;
            //std::cout<<this->ToString()<<" constructed by user input"<<endl;
        }

        // Copy constructor
        Point::Point(const Point& pt)
        {
            m_x = pt.X();
            m_y = pt.Y();
            //std::cout<<this->ToString()<<" constructed by copy"<<endl;
        }

        // Destructor
        Point::~Point()
        {
            std::cout<<this->ToString()<<" destructed"<<endl;
        }
        
        // Get X overload function
        double Point::X() const
        {
            return  m_x;
        }

        // Set X overload function
        void Point::X(double newX)
        {
            m_x = newX;
        }
        
        // Get Y overload function
        double Point::Y() const
        {
            return m_y;
        }
        
        // Set Y overload function
        void Point::Y(double newY)
        {
            m_y = newY;
        }

        // return Point as string
        string Point::ToString() const
        {
            std::stringstream ss;
            ss << "Point(" << m_x << "," << m_y << ")";
            
            return ss.str();  // Retrieve the string from the string buffer
        }
        
        // calculate distance to origin
        double Point::Distance() const
        {
            return std::sqrt(m_x*m_x+m_y*m_y);
        }

        // calculate distance with another point using overload
        double Point::Distance(const Point& pt) const //modified to not copy
        {
            // changing pt would cause compiler error
            // pt.setX(0.1);
            return std::sqrt((m_x-pt.m_x)*(m_x-pt.m_x)+(m_y-pt.m_y)*(m_y-pt.m_y));
        }


        
        // get negative
        Point Point::operator - () const
        {
            return Point(-m_x,-m_y);
        }

        // * operator, time with scaler
        Point Point::operator * (double factor) const
        {
            return Point(m_x*factor,m_y*factor);
        }

        // + operator, adds corresponding coordinates
        Point Point::operator + (const Point& p) const
        {
            return Point(m_x+p.m_x, m_y+p.m_y);
        }
        
        // == operator, judge if both coordinates are equal
        bool Point::operator == (const Point& p) const
        {
            return  (m_x == p.m_x) && (m_y==p.m_y);
        }

        // assignment operator
        Point& Point::operator = (const Point& source)
        {
            if (this == &source)
                return *this;
            
            m_x = source.m_x;
            m_y = source.m_y;
            
            return *this;
        }

        // *= operator
        Point& Point::operator *= (double factor)
        {
            m_x *= factor;
            m_y *= factor;
            return *this;
        }


        // << operator
        ostream& operator << (ostream& os, const Point& p)
        {
            return os << "Point(" << p.m_x << "," << p.m_y << ")";
        }

    }

}

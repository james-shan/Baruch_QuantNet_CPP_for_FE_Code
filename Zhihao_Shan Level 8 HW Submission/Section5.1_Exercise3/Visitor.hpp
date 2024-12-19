//
//  Visitor.hpp
//  Section5.1_Exercise3
//
//  Created by Zhihao Shan on 2023/7/15.
//

#ifndef Visitor_hpp
#define Visitor_hpp

#include <boost/variant/static_visitor.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

class Visitor : public boost::static_visitor<void>
{
private:
    double m_dx; // x-coordinate
    double m_dy; // y-coordinate

public:
    Visitor(); // Default constructor
    Visitor(double xValue, double yValue); // Constructor with input
    Visitor(const Visitor& source); // Copy constructor
    ~Visitor(); // Destructor

    // Member operator overloading
    Visitor& operator = (const Visitor& source); // Assignment operator
    void operator () (Point& p) const; // () operator for Point
    void operator () (Line& l) const; // () operator for Line
    void operator () (Circle& c) const; // () operator for Circle
};
#endif /* Visitor_hpp */

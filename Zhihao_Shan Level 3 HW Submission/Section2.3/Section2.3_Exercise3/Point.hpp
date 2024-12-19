//
//  Point.hpp
//  HW2.3_Exercise3
//
//  Created by Zhihao Shan on 2023/6/10.
//
// This file is the header file for Point Class

#include <string>
#ifndef Point_hpp
#define Point_hpp

using namespace std;

class Point
{
private:
    double m_x;
    double m_y;
public:
    // Constructors
    Point(); // Default constructor
    Point(double x, double y); // Constructor with user input
    ~Point(); // Destructor
    Point(const Point& other); // Copy constructor

    // set and get x using function overloading
    double X() const;
    void X(double newX);
    
    // set and get y using function overloading
    double Y() const;
    void Y(double newY);
    
    //To string function
    string ToString() const;
    
    //Distance functions using function overloading
    double Distance() const;
    double Distance(const Point& pt) const;
};

#endif /* Point_hpp */

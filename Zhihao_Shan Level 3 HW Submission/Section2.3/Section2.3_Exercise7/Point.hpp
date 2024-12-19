//
//  Point.hpp
//  HW2.3_Exercise7
//
//  Created by Zhihao Shan on 2023/6/10.
//
// This file is header file for Point Class and implements default & normal inline member functions

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

    // set and get x
    double X() const;
    // default inline setter for x
    void X(double newX){m_x = newX;};
    
    // set and get y
    double Y() const;
    // default inline setter for y
    void Y(double newY){m_y = newY;};
    
    //To string function
    string ToString() const;
    
    //Distance functions
    double Distance() const;
    double Distance(const Point& pt) const;
};

// normal inline getter for x and y
inline double Point::X() const {return m_x;}
inline double Point::Y() const {return m_y;}

#endif /* Point_hpp */

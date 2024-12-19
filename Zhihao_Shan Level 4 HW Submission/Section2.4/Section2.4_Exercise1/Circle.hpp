//
//  Circle.hpp
//  HW2.4_Exercise1
//
//  Created by Zhihao Shan on 2023/6/15.
//
//  Header file for Circle class
#include <iostream>
#include "Point.hpp"
#include <string>

#ifndef Circle_hpp
#define Circle_hpp

using namespace std;

class Circle
{
private:
    Point m_cp;
    double m_radius;
    

public:
    // Constructor and destructors
    Circle();
    Circle(const Point& cp, const double& radius);
    Circle(const Circle& other);
    ~Circle();
    
    // Overloaded getters and setters
    Point CenterPoint() const;
    void CenterPoint(const Point& cp);
    double Radius() const;
    void Radius(const double& radius);
    
    //Other funtions
    double Diameter() const;
    double Area() const;
    double Circumference() const;
    string ToString() const;
    
    // Assignment Operator
    Circle& operator = (const Circle& source);
    

};


#endif 

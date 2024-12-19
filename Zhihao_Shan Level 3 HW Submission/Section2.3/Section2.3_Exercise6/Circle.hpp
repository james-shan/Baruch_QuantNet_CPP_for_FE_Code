//
//  Circle.hpp
//  HW2.3_Exercise6
//
//  Created by Zhihao Shan on 2023/6/11.
//
//  This file is header file for Cirlce Class

#include <iostream>
#include "Point.hpp"
#include <string>

#ifndef Circle_hpp
#define Circle_hpp

using namespace std;

class Circle
{
private:
    Point m_cp; // Center point of the circle
    double m_radius; // Radius of the circle

public:
    // Constructors and destructor
    Circle(); // Default constructor
    Circle(const Point& cp, const double& radius);  // Constructor with center point and radius
    Circle(const Circle& other); // Copy constructor
    ~Circle(); // Destructor

    // Overloaded getters and setters
    Point CenterPoint() const; // Getter for the center point
    void CenterPoint(const Point& cp); // Setter for the center point
    double Radius() const; // Getter for the radius
    void Radius(const double& radius); // Setter for the radius

    // Other functions
    double Diameter() const; // Calculate the diameter of the circle
    double Area() const; // Calculate the area of the circle
    double Circumference() const; // Calculate the circumference of the circle
    string ToString() const; // Convert the circle to a string representation
};


#endif /* Line_hpp */

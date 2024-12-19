//
// Circle.hpp
//  Section3.5_Exercise4
//
// Created by Zhihao Shan on 2023/6/16.
//
//  header file for Line Class

#include "Point.hpp" // Include the Point header file for Point class
#include "Shape.hpp"
#include <iostream>
#include <string>

#ifndef Circle_hpp
#define Circle_hpp

using namespace std;

class Circle: public Shape // inherit from Shape Class
{
private:
    Point m_cp; // Center point of the circle
    double m_radius; // Radius of the circle

public:
    // Constructor and destructors
    Circle(); // Default constructor
    Circle(const Point& cp, const double& radius); // Constructor with center point and radius parameters
    Circle(const Circle& other); // Copy constructor
    ~Circle(); // Destructor
    
    // Assignment Operator
    Circle& operator=(const Circle& source);
    

    // Overloaded getters and setters
    Point CenterPoint() const; // Get the center point of the circle
    void CenterPoint(const Point& cp); // Set the center point of the circle
    double Radius() const; // Get the radius of the circle
    void Radius(const double& radius); // Set the radius of the circle

    // Other functions
    double Diameter() const; // Calculate the diameter of the circle
    double Area() const; // Calculate the area of the circle
    double Circumference() const; // Calculate the circumference of the circle
    string ToString() const; // Convert the circle to a string representation

    
    // Draw function to simulate drawing
    void Draw();
    
    

};

// Ostream << operator
ostream& operator<<(ostream& os, const Circle& c);


#endif


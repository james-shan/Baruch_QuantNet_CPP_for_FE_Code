//
//  Point.hpp
//  Section3.6_Exercise1
//
//  Created by Zhihao Shan on 2023/6/16.
//
//  header file for Point Class

#include <string>
#include "Shape.hpp"
using namespace std;

#ifndef Point_hpp
#define Point_hpp


class Point: public Shape // inherit from Shape Class
{
// set private variables
private:
    double m_x;
    double m_y;
public:
    // Constructors
    Point(); // Default constructor
    Point(double x, double y); // Constructor with user input
    ~Point(); // Destructor
    Point(const Point& other); // Copy constructor
    
    // Assignment operator
    Point& operator = (const Point& source);
    
    // set and get x
    double X() const;
    void X(double newX);
    
    // set and get y
    double Y() const;
    void Y(double newY);
    
    // To string function
    string ToString() const;
    
    // Draw function to simulate drawing
    void Draw();
    
    //Distance functions
    double Distance() const;
    double Distance(const Point& pt) const;
    
    
    // Operators
    Point operator - () const; // Negate the coordinates.
    Point operator * (double factor) const; // Scale the coordinates.
    Point operator + (const Point& p) const; // Add coordinates.
    bool operator == (const Point& p) const; // Equally compare operator.
    Point& operator *= (double factor); // Scale the coordinates & assign.
    
    // global friend operator
    friend ostream& operator << (ostream& os, const Point& p);
};


#endif /* Point_hpp */

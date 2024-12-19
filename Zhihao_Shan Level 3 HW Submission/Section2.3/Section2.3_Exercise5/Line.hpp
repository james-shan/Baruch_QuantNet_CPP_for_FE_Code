//
//  Line.hpp
//  HW2.3_Exercise5
//
//  Created by Zhihao Shan on 2023/6/11.
//

#ifndef Line_hpp
#define Line_hpp

#include "Point.hpp"  // Include the header file for the Point class
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

class Line
{
private:
    Point start_p;  // Start point of the line
    Point end_p;    // End point of the line

public:
    // Constructors and destructor
    Line();  // Default constructor
    Line(const Point& new_start_p, const Point& new_end_p);  // Constructor with start and end points
    Line(const Line& other);  // Copy constructor
    ~Line();  // Destructor
    
    // Overloaded getters and setters
    Point StartPoint() const;  // Getter for the start point
    void StartPoint(const Point& newstart);  // Setter for the start point
    Point EndPoint() const;  // Getter for the end point
    void EndPoint(const Point& newend);  // Setter for the end point
    
    // Other functions
    std::string ToString() const;  // Generate a string representation of the Line object
    double Length() const;  // Calculate the length of the line
};

#endif /* Line_hpp */


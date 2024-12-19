//
//  Line.hpp
//  Section4.2a_Exercise1
//
//  Created by Zhihao Shan on 2023/7/2.
//
//  header file for Line Class

#include "Point.hpp"
#include "Shape.hpp"
#include <string>
#include <iostream>

#ifndef Line_hpp
#define Line_hpp
using namespace std;


class Line: public Shape // inherit from Shape Class
{
private:
    Point start_p;
    Point end_p;
    
public:
    // Constructor and destructors
    Line();
    Line(const Point& new_start_p, const Point& new_end_p);
    Line(const Line& other);
    ~Line();
    
    // Assignment Operator
    Line& operator = (const Line& source);
    
    // Overloaded getters and setters
    Point StartPoint() const;
    void StartPoint(const Point& newstart);
    Point EndPoint() const;
    void EndPoint(const Point& newend);
    
    // Other funtions
    string ToString() const;
    double Length() const;
    
    // Draw function to simulate drawing
    void Draw();
    
};

// Ostream << operator
ostream& operator << (ostream& os, const Line& l);

#endif

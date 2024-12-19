//
//  main.cpp
//  Section3.4_Exercise1
//
//  Created by Zhihao Shan on 2023/6/24.
//
//  Tests the functionality of Shape base class and pointers to it

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"


int main()
{
    Shape s; // Create shape.
    Point p(10, 20); // Create point.
    Line l(Point(1,2), Point(3, 4)); // Create line.
    
    
    cout<<s.ToString()<<endl; // Print shape.
    cout<<p.ToString()<<endl; // Print point.
    cout<<l.ToString()<<endl; // Print line
    
    
    cout<<"Shape ID: "<<s.ID()<<endl; // ID of the shape.
    
    cout<<"Point ID: "<<p.ID()<<endl; // ID of the point. Does this work?
    // It works since point inherits functionality of Shape class.
    
    cout<<"Line ID: "<<l.ID()<<endl; // ID of the point. Does this work?
    // It works since line inherits functionality of Shape class.
    
    Shape* sp;  // Create pointer to a shape variable.
    sp=&p;  // Point in a shape variable. Possible?
    // Yes
    
    cout<<sp->ToString()<<endl;  // What is printed?
    // ID of Point p is printed using ToString of Shape class
    
    
    // Create and copy Point p to new point.
    Point p2;
    p2=p;
    
    cout<<p2<<", "<<p2.ID()<<endl;
    // Is the ID copied if you do not call the base class assignment in point?
    // It is copied since we called the assignment operator of shape in the assignment operator of point
    
    return 0;
}


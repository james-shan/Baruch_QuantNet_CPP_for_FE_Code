//
//  main.cpp
//  Section3.5_Exercise1
//
//  Created by Zhihao Shan on 2023/6/24.
//
//  This file tests the usage of virtual base class function.

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"


int main()
{
    // Create Shape Pointer and assign to a Point
    Shape* s1;
    Point p1 = Point(3.5,4.5);
    s1 = &p1;
    
    // Print s1 using ToString, it uses the function in Shape Class without making ToString virtual.
    
    cout<< s1->ToString() << endl; // after making ToString in Shape.hpp virtual, it uses the ToString function in Point class.
    
    
    return 0;
}


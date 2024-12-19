//
//  main.cpp
//  Section3.5_Exercise2
//
//  Created by Zhihao Shan on 2023/6/24.
//
//  This file tests the usage of calling base class functionality

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"


int main()
{
    // Create  a Point, a Line and a Circle
    Point p1 = Point(3.5,4.5);
    Line l1 = Line(p1,Point(6.5,7.5));
    Circle c1 = Circle(p1,3.0);
    
    
    // use ToString to print these shapes, it should print ID after modification
    cout<< p1.ToString() << endl;
    cout<< l1.ToString() << endl;
    cout<< c1.ToString() << endl;
    
    return 0;
}


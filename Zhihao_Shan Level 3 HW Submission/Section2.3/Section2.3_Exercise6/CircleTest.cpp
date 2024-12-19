//
//  main.cpp
//  HW2.3_Exercise6
//
//  Created by Zhihao Shan on 2023/6/10.
//
//  This file tests functionality of Circle Class

#include "Point.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;

int main()
{
    // Initialize variables for creating circle
    Point p1(5,3);
    double r = 3;
    
    // Initiate Circle by given value
    Circle c(p1,r);
    
    // Print Cirlce information
    cout << c.ToString() << endl;
        
    // Change Circle parameters
    Point p2(3,3);
    c.CenterPoint(p2);
    c.Radius(6);
    cout << "New circle: " << c.ToString() << endl;
        
    // Print new characteristics of circle
    cout << "Diameter is " << c.Diameter() << endl;
    cout << "Area is " << c.Area() << endl;
    cout << "Circumference is " << c.Circumference() << endl;
    cout << endl;
    
    
}
 



//
//  main.cpp
//  Section3.5_Exercise5
//
//  Created by Zhihao Shan on 2023/6/24.
//
//  This file tests the usage of Template Method Pattern

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"


int main()
{
    // Declaring new Point and Line object
    Point p1(3.5, 4.5);
    Point p2(6.5, 8.5);
    Line l1(p1,p2);
    
    // Use Pring()function from Shape Class
    p1.Print();
    l1.Print();
    
    //Does it print the right information even when point and line do not have the Print() function?
    // It does!
}


//
//  main.cpp
//  Section3.5_Exercise4
//
//  Created by Zhihao Shan on 2023/6/24.
//
//  This file tests the usage of PVMF

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"


int main()
{
    Shape* shapes[5];
    
    shapes[0] = new Point;  // Default constructor of Point
    shapes[1] = new Point(3.0, 4.0); // Constructor with user input of Point
    shapes[2] = new Point(Point(3.0,4.0)); // Copy constructor of Point
    shapes[3] = new Line; // Default constructor of Line
    shapes[4] = new Circle; // Default constructor of Circle
    
    // iterate through shape arr
    for (int i=0; i!=5; i++)
    {
        shapes[i]->Draw(); // PVMF: Draw()
        delete shapes[i];
    }
    
}


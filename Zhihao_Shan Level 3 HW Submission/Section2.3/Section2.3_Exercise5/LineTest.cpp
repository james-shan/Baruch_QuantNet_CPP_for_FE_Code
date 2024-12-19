//
//  LineTest.cpp
//  HW2.3_Exercise5
//
//  Created by Zhihao Shan on 2023/6/10.
//
// This file test functionality of Line Class

#include "Point.hpp"
#include "Line.hpp"
#include <iostream>
using namespace std;

int main()
{
    // Define points for line
    Point start1(1.5, 3.6);
    Point end1(2.0, 5.4);
    Point start2(5.2, 3.8);
    
    // Initialize Line
    Line l1(start1, end1);
    
    // Print the start and end points of the line
    cout << "Start point of the line is " << l1.StartPoint().ToString() << endl;
    cout << "End point of the line is " << l1.EndPoint().ToString() << endl;
    
    // Update the start point of the line
    l1.StartPoint(start2);
    
    // Print the length of the line
    cout << "Length of " << l1.ToString() << " is " << l1.Length() << endl;
    
    return 0;
}

 



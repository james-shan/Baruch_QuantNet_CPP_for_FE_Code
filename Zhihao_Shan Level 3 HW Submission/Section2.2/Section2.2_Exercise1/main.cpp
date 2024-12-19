//
//  main.cpp
//  HW2.2_Exercise1
//
//  Created by Zhihao Shan on 2023/6/10.
//
// This file tests the functions of Point class

#include "Point.hpp"
#include <iostream>
using namespace std;

int main()
{
    // declare variables
    double x;
    double y;
    
    // let user input
    cout << "Enter x and y coordinate:" << endl;
    cin >> x >> y ;
    
    // set point using setX and setY member functions
    Point pt1;
    pt1.setX(x);
    pt1.setY(y);
    
    // Print description of p1 using ToString()
    cout << pt1.ToString() << endl;
    
    // Print description of p1 using GetX() and GetY()
    cout << "Point(" << pt1.getX() << "," << pt1.getY() << ")" << endl;
    
}

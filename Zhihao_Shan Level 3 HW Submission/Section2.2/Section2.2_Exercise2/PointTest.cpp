//
//  main.cpp
//  HW2.2_Exercise2
//
//  Created by Zhihao Shan on 2023/6/10.
//
// This file tests the functions of Point Class

#include "Point.hpp"
#include <iostream>
using namespace std;

int main()
{
    // declare variables
    double x1;
    double y1;
    
    // let user input
    cout << "Enter x and y coordinate:" << endl;
    cin >> x1 >> y1 ;
    
    // set point
    Point pt1;
    pt1.setX(x1);
    pt1.setY(y1);
    
    // Print description of p1 using ToString()
    cout << pt1.ToString() << endl;
    
    // Print description of p1 using GetX() and GetY()
    cout << "Point(" << pt1.getX() << "," << pt1.getY() << ")" << endl;
    
    //set another point
    double x2 = 4.0;
    double y2 = 6.0;
    Point pt2;
    pt2.setX(x2);
    pt2.setY(y2);
    
    //get distance
    cout << "Distance between "<<pt1.ToString()<< " and origin is: " << pt1.DistanceOrigin() <<endl;
    cout << "Distance between "<< pt1.ToString() << " and " << pt2.ToString() <<" is: " << pt1.Distance(pt2) <<endl;
}
 

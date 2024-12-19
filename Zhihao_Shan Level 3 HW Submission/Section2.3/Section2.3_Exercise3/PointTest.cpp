//
//  main.cpp
//  HW2.3_Exercise3
//
//  Created by Zhihao Shan on 2023/6/10.
//
// This file tests functionality of Point Class

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
    
    // set point using function overloading
    Point pt1;
    pt1.X(x1);
    pt1.Y(y1);
    
    // print point coordinates using function overloading
    cout << "x-coordinate for pt1 is "<<pt1.X()<<endl;
    cout << "y-coordinate for pt1 is "<<pt1.Y()<<endl;
    
    //get distance
    cout << "Distance between "<<pt1.ToString()<< " and origin is: " << pt1.Distance() <<endl;
    
}
 



//
//  PointTest.cpp
//  HW2.3_Exercise1
//
//  Created by Zhihao Shan on 2023/6/10.
//
//  This file tests the functions of Point Class

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
    Point pt1 = Point(x1,y1);
    
    //set another point
    Point pt2 = Point(6.0,4.0);
    
    //get distance
    double distance_res = pt1.Distance(pt2);
    cout << "Distance between "<< pt1.ToString() << " and " << pt2.ToString() <<" is: " << distance_res <<endl;
}
 
// Before adding the copy constructor, constructor and destructor for pt1 are both called once. But constructor for pt2 is only called once (construction by copy is not printed) and destructor is called twice.

// After adding the copy constructor, for pt2, constructor and destructor are both called twice. for pt1, they are both called once.


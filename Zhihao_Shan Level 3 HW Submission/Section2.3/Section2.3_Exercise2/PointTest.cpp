//
//  main.cpp
//  HW2.3_Exercise2
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
    
    // set point
    Point pt1 = Point(x1,y1);
    
    //set another point
    Point pt2 = Point(6.0,4.0);
    
    //get distance
    double distance_res = pt1.Distance(pt2);
    cout << "Distance between "<< pt1.ToString() << " and " << pt2.ToString() <<" is: " << distance_res <<endl;
}
 
// After modified the Distance function to use reference, both constructor and destructor of pt1 and pt2 are only called once.



//
//  main.cpp
//  HW2.3_Exercise4
//
//  Created by Zhihao Shan on 2023/6/10.
//
// This file test functionality of Point Class

#include "Point.hpp"
#include <iostream>
using namespace std;

int main()
{
    // construct const point
    const Point cp(1.5, 3.9);
    // cp.X(0.3);
    // Yes, modifying the point would cause compilter error!
    
    // after marking X(), ToString() and Distance() as const, build succeeded
    cout << cp.X() << endl;
    cout << cp.ToString() << endl;
    cout << "Distance between "<< cp.ToString()<< " and origin is: " << cp.Distance() <<endl;
    
}
 



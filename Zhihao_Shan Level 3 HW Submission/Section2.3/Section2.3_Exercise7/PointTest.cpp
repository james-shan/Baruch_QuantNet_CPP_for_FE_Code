//
//  main.cpp
//  HW2.3_Exercise7
//
//  Created by Zhihao Shan on 2023/6/10.
//
//  This file tests functionality of modified Point Class with inline member functions

#include "Point.hpp"
#include <iostream>
using namespace std;

int main()
{
    // construct const point
    const Point cp(1.5, 3.9);
    
    // after marking X(), ToString() and Distance() as const, build succeeded
    cout<<cp.X()<<endl;
    cout << cp.ToString() << endl;
    cout << "Distance between "<< cp.ToString()<< " and origin is: " << cp.Distance() <<endl;
    
}
 



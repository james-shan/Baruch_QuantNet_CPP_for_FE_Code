//
//  OstreamTest.cpp
//  HW2.4_Exercise3
//
//  Created by Zhihao Shan on 2023/6/15.
//
// Tests implicit constructor of point class

#include "Point.hpp"
#include <iostream>
using namespace std;

int main()
{
    // create point using two methods and compare if they are same
    Point p(1.0, 1.0);
    if (p==(Point)1.0) cout<<"Equal!"<<endl;
    else cout<<"Not equal"<<endl;
}

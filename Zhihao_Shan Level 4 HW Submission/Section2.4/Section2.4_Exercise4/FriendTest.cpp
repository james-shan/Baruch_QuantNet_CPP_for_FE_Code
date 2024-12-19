//
//  FriendTest.cpp
//  HW2.4_Exercise4
//
//  Created by Zhihao Shan on 2023/6/15.
//
//  Test friend ostream << operators

#include "Point.hpp"
#include "Line.hpp"
#include <iostream>
using namespace std;

int main()
{
    // Friend << operator for Point
    Point p(3.0, 4.0);
    cout << p.ToString() << endl; // Use member function to print
    cout << p << endl; // Use Friend << operator to print
    
    
    // Friend << operator for Line
    Point p1 (3.0, 4.0);
    Point p2 (5.0, 6.0);
    Line line(p1, p2);
    cout << line.ToString() << endl; // Use member function to print
    cout << line << endl; // Use Friend << operator to print

    
    return 0;
}

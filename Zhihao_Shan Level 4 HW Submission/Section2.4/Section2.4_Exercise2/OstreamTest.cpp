//
//  OstreamTest.cpp
//  HW2.4_Exercise2
//
//  Created by Zhihao Shan on 2023/6/15.
//
// Compares results using Tostring and ostream << operator

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;

int main()
{
    // Ostream << operator for Point
    Point p(3.0, 4.0);
    cout << p.ToString() << endl; // Use member function to print
    cout << p << endl; // Use Ostream << operator to print
    
    
    // Ostream << operator for Line
    Point p1 (3.0, 4.0);
    Point p2 (5.0, 6.0);
    Line line(p1, p2);
    cout << line.ToString() << endl; // Use member function to print
    cout << line << endl; // Use Ostream << operator to print
    
    
    // Ostream << operator for Circle
    double radius = 5.0;
    Circle c(p, radius);
    cout << c.ToString() << endl; // Use member function to print
    cout << c << endl; // Use Ostream << operator to print
    
    return 0;
}

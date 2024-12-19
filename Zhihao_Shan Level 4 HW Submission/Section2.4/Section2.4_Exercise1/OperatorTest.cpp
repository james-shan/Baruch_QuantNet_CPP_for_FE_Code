//
//  OperatorTest.cpp
//  HW2.4_Exercise1
//
//  Created by Zhihao Shan on 2023/6/15.
//
//  Tests operator functionalities of three classes

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;

int main()
{
    // +,-,= for Point
    Point p1(3.0, 4.0);
    cout << "p1 is " << p1.ToString() << endl;
    Point p2(5.0, 6.0);
    p2 = p2 + (-p1);
    cout << "p2 is " << p2.ToString() << endl;
    cout << endl;
    
    
    // *, *=, ==for Point
    double d = 5.0;
    p1 *= d;
    cout << "p1 *= f gives " << p1.ToString() << endl;
    p2 = p2 * d;
    cout << "p2 = p2 * f gives " << p2.ToString() << endl;
    cout << endl;
    cout << ((p1 == p2) ? "p1 == p2" : "p1 != p2") << endl << endl;

    
    // assignment operator for Line and Circle
    Line line1 = Line(p1, p2);
    cout << "line1 is " << line1.ToString() << endl;
    Line line2 = line1;
    cout << "line2 is " << line2.ToString() << endl;
    line2.StartPoint(Point(0,0));
    cout << "line1 is " << line1.ToString() << endl;
    cout << "line2 is " << line2.ToString() << endl;
    cout << endl;
    
    Circle circle1 = Circle(p1, d);
    cout << "circle1 is " << circle1.ToString() << endl;
    Circle circle2 = circle1;
    cout << "circle2 is " << circle2.ToString() << endl;
    circle2.Radius(10);
    cout << "circle1 is " << circle1.ToString() << endl;
    cout << "circle2 is " << circle2.ToString() << endl;
    
    return 0;
}

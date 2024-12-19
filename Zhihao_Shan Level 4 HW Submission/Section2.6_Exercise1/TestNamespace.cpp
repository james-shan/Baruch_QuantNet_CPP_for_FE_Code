//
//  TestNamespace.cpp
//  HW2.6_Exercise1
//
//  Created by Zhihao Shan on 2023/6/16.
//
//  Tests classes after using namespace

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"

int main()
{
    // Explicit access qualification
    // Create a point p using the ZHIHAO::CAD::Point class
    ZHIHAO::CAD::Point p(3.0, 4.0);
    std::cout << "Distance of " << p << " from the origin is " << p.ZHIHAO::CAD::Point::Distance() << std::endl;

    // Using declaration
    // Declare the Line class from the ZHIHAO::CAD namespace
    using ZHIHAO::CAD::Line;
    Line l;
    l.Line::EndPoint(p);
    std::cout << "Length of Line l is " << l.Line::Length() << std::endl;

    // Using directive
    // Use the ZHIHAO::Containers namespace
    using namespace ZHIHAO::Containers;
    Array arr = Array(5);
    arr.SetElement(2, p);
    std::cout << "arr[2] becomes " << arr.GetElement(2) << std::endl;

    // Alias namespaces
    // Create an alias ZC for the ZHIHAO::CAD namespace
    namespace ZC = ZHIHAO::CAD;
    double r = 5.0;
    ZC::Circle c(p, r);
    std::cout << "Area of the circle is " << c.ZC::Circle::Area() << std::endl;

    
    return 0;
}


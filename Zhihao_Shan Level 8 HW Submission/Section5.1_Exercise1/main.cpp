//
//  main.cpp
//  Section5.1_Exercise1
//
//  Created by Zhihao Shan on 2023/7/2.
//
//  This file shows the usage of shared_ptr from boost library

#include <boost/shared_ptr.hpp>
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"


int main()
{
    // Typedefs to simplify the code
    typedef boost::shared_ptr<Shape> ShapePtr;
    typedef Array<ShapePtr> ShapeArray;
    
    // Create an array of length 3 to store shapes
    ShapeArray shapes1(3);
    
    // Create shapes and assign to pointer
    ShapePtr p1(new Point(2.5, 4.5));
    ShapePtr l1(new Line(Point(3.5, 6.5), Point(2.5, 4.5)));
    ShapePtr c1(new Circle(Point(2.5, 4.5), 3.5));


    //  Assign shared pointers to smart array
    shapes1[0] = p1;
    shapes1[1] = l1;
    shapes1[2] = c1;
    
    // print the shapes using member function
    for (int i = 0; i < 3; ++i)
        cout << (*shapes1[i]).ToString()<< endl;

    // Shapes are automatically deleted after no longer in use because of the use of smart pointer in boost

    return 0;
}

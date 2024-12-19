//
//  main.cpp
//  Section5.1_Exercise3
//
//  Created by Zhihao Shan on 2023/7/15.
//

#include <boost/variant.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Visitor.hpp"
#include <string>
#include <iostream>
using namespace std;
using boost::variant;

typedef boost::variant<Point, Line, Circle> ShapeType;

// This function asks user to input shape type and creates corresponding shape objects
ShapeType ShapeVariant()
{
    ShapeType shape;

    // Ask the user for input of shape type
    cout << "Please choose the shape:" << endl << "a Point; b Line; c Circle" << endl;
    char choice;
    cin >> choice;

    // Use switch case to create shape specified by user
    switch (choice)
    {
        case 'a':
            shape = Point();
            break;
        case 'b':
            shape = Line();
            break;
        case 'c':
            shape = Circle();
            break;
        default:
            break;
    }

    return shape;
}

int main()
{
    // Use ShapeVariant to initialize shape
    ShapeType s = ShapeVariant();;
    cout << s << endl; // show original shape

    // Move the shape use visitor and apply_visitor from boost
    Visitor visitor(2.5, 3.5);
    boost::apply_visitor(visitor, s);
    cout << s << endl; // show result of move
    
    return 0;
}

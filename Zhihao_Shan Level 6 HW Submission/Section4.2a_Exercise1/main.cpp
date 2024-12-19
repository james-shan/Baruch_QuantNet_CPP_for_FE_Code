//
//  main.cpp
//  Section4.2a_Exercise1
//
//  Created by Zhihao Shan on 2023/7/2.
//
//  This file tests the functionality of template array class

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "ArrayException.hpp"
#include "Array.hpp"

/*
Reason of why the tip works:
 When using template classes in C++, the implementation must be known at compile-time, unlike regular classes that can be linked later from object files.Uninstantiated templates cannot be stored in an object file for the linker.
 We included the template source file (.cpp) within the template header file (.hpp), and then included the header file in the main.cpp file.
 This allows the template to be instantiated and compiled when including the header in the main.cpp file.
*/


int main()
{
    // Create arrays of points and lines
    int size = 5;
    Array<Point> points(size); // Create an array of points
    Array<Line> lines(size); // Create an array of lines
    
    points[0].Draw();  // Test PVMF Draw()


    // Set elements of Array points
    Point p(6,8);
    points[0] = p;
    points[1].X(8.0);
    points[2].Y(2.0);
    points[3] = points[1] + points[2];
    points[4] = points[0] * (-1.0);
    
    // Print the elements in Array points
    for (int i=0; i<points.Size(); i++)
    {
        cout << "The NO."<<i+1<<" object of points is " << points[i] << endl;
    }

    
    // Test Exception catching using lines
    try
    {
        cout << lines[5] << endl; // Access an element out of bounds
    }
    catch (ArrayException& ex) // Catch exception object
    {
        cout << ex.GetMessage() << endl; // Use arrayexception to print error messsage
    }
    
}


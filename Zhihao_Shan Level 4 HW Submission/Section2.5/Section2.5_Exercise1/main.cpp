//
//  main.cpp
//  HW2.5_Exercise1
//
//  Created by Zhihao Shan on 2023/6/15.
//
// This file dynamically creates Point objects

#include "Point.hpp"
#include <iostream>
using namespace std;


int main()
{
    // Creating Point objects on the heap using new
    Point* p1 = new Point(); // Default constructor
    Point* p2 = new Point(3, 4); // Constructor with coordinates
    Point* p3 = new Point(*p2); // Copy constructor

    // Calling Distance() function on the pointers
    cout << (*p1).Distance() << endl;  // Distance between p1 and origin
    cout << (*p2).Distance() << endl;  // Distance between p2 and origin
    cout << (*p3).Distance() << endl;  // Distance between p3 and origin

    // Deleting objects created with new
    delete p1;
    delete p2;
    delete p3;
    
    /*
    // Let user input array size -> lead to compile error!
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    */
    
    
    // Set size first then creat point array
    int size = 10;
    Point* pp;
    pp = new Point[size]; // Using the default constructor for each object,  cannot use other constructor
    cout << pp[0]; // Print first point in the array

    // Deleting the array created with new[]
    delete[] pp;

    return 0;
}

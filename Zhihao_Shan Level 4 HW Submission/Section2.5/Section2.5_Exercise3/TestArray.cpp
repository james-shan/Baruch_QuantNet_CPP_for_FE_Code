//
//  main.cpp
//  HW2.5_Exercise3
//
//  Created by Zhihao Shan on 2023/6/16.
//
// Test functionalities of Array class

#include <iostream>
#include "Array.hpp"
#include "Point.hpp"


int main()
{
    // Create array by default
    Array arr1;
    
    // Create an array with a size of 5
    Array arr2(5);
    
    // Create an array by copy
    Array arr3(arr2);

    // Set elements in arr3
    for (int i = 0; i < arr3.Size(); ++i)
    {
        Point p(i, i+1);
        arr3.SetElement(i, p);
    }
    
    // Print array size
    std::cout<<"Size of Array is "<<arr3.Size()<<endl;

    // Get and print elements from the array
    for (int i = 0; i < arr3.Size(); ++i)
    {
        const Point& p = arr3.GetElement(i);
        std::cout << "Element " << i << ": (" << p.X() << ", " << p.Y() << ")\n";
    }

    // Modify an element using the square bracket operator
    arr3[2] = Point(10, 20);
    
    // Print the modified element
    const Point& modifiedPoint = arr3.GetElement(2);
    std::cout << "Modified Element at index 2: "<< modifiedPoint <<endl;
    
    return 0;
}

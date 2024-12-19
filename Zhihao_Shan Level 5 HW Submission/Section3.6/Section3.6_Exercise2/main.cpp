//
//  main.cpp
//  Section3.6_Exercise2
//
//  Created by Zhihao Shan on 2023/6/24.
//
//  This file tests the functionality of ArrayException and OutofboundException

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"


int main()
{
    try
    {
        // Creating new array of length 5
        Array arr = Array(5);
        
        // Trying to assign a value to an index outside the bounds of the array
        cout<<arr[10]<<endl;
        
        // arr.SetElement(20, Point(4.0,5.0)); // Trying SetElement at index 20
        // cout<<arr.GetElement(3)<<endl; // Getting Element at legit index
        
    }
    catch (const ArrayException& ex)
    {
        // Print the error message using ArrayException base class
        std::cout << ex.GetMessage() << std::endl;
    }

    return 0;
}


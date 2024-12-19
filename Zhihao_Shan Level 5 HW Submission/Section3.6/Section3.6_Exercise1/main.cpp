//
//  main.cpp
//  Section3.6_Exercise1
//
//  Created by Zhihao Shan on 2023/6/24.
//
//  This file tests the usage of throwing error

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"


int main()
{
    // Create an array of Point with 5 elements
    Array arr = Array(5);
    
    //cout << arr[-1] << endl;    // libc++abi: terminating with uncaught exception of type int
    
    
    // implement try...caught mechanism
    try
    {
        cout << arr[10] << endl;
    }
    catch (int err)
    {
        // display out of bounds error if -1 catched
        if (err == -1)
            cout << "Error: index out of bounds." << endl;
    }
    catch(...)
    {
        // handle other unexpected errors
        cout << "Unexpected error" << endl;
    }
    
    // try a legit input
    cout << arr.GetElement(2) << endl;
    
    return 0;
}


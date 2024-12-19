//
//  main.cpp
//  Section4.2b_Exercise1
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


int main()
{
    // Create 2 arrays of int
    Array<int> intArray1;
    Array<int> intArray2;
    
    // Creat an array of double
    Array<double> doubleArray;
    
    // The output would be 20, 20, 20 since I set the default size to 20 in the source file
    cout<<intArray1.DefaultSize()<<endl;
    cout<<intArray2.DefaultSize()<<endl;
    cout<<doubleArray.DefaultSize()<<endl;
    
    // modify static variable d_size of intArray1
    intArray1.DefaultSize(15);
    
    // The output would be 15, 15, 20 since for template classes, static variable is only shared among classes of the same data type.
    cout<<intArray1.DefaultSize()<<endl;
    cout<<intArray2.DefaultSize()<<endl;
    cout<<doubleArray.DefaultSize()<<endl;
    
}


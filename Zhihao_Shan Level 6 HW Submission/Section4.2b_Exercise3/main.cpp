//
//  main.cpp
//  Section4.2b_Exercise3
//
//  Created by Zhihao Shan on 2023/7/2.
//
//  This file tests the functionality of PointArray class

#include <iostream>
#include "Point.hpp"
#include "ArrayException.hpp"
#include "PointArray.hpp"


int main()
{
    // initialize an PointArray
    PointArray pa1;
    
    // Use indexer in Array class to set element
    for (int i=0; i < pa1.Size(); i++)
    {
        pa1[i] = Point(i+1,i+6);
    }
    
    // Test copy constructor
    PointArray pa2(pa1); // copy
    cout << "printing point array 2:"<<endl;
    for (int i=0; i < pa2.Size(); i++)
    {
        cout << pa2[i] << endl;
    }
    
    // Test assignment operator
    PointArray pa3;
    pa3 = pa2;
    cout << "printing point array 3:"<<endl;
    for (int i=0; i < pa3.Size(); i++)
    {
        cout << pa3[i] << endl;
    }
    
    // Test Length in PointArray
    // result should be 4 times (2^0.5) for pa3
    cout << pa3.Length() << endl;
    
    // Try Length on array with length1
    PointArray pa4(1);
    try
    {
        cout << pa4.Length() << endl;
    }
    catch (ArrayException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
}



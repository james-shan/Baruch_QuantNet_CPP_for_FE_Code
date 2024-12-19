//
//  main.cpp
//  Section4.2b_Exercise2
//
//  Created by Zhihao Shan on 2023/7/2.
//
//  This file tests the functionality of template NumericArray class

#include <iostream>
#include <random>
#include "Point.hpp"
#include "ArrayException.hpp"
#include "NumericArray.hpp"


int main()
{
    // Create numeric arrays for testing
    NumericArray<int> intArray1;
    NumericArray<int> intArray2;
    NumericArray<int> intArray3;
    NumericArray<int> intArray4(8);
    
    // Assign arbitrary values to intArray1 and intArray2
    for (int i=0; i<intArray1.Size(); i++)
    {
        intArray1[i] = random() % 10;
        intArray2[i] = random() % 10;
        
        cout << "No."<<i<<" object of array 1 and 2: "<<intArray1[i] <<", "<< intArray2[i]<<endl;
    }
    cout << endl;
    

    // Test operator + ()
    // Add intArray1 and intArray2, assign to intArray3
    intArray3 = intArray1 + intArray2;
    
    // Print results
    cout << "Sum of array 1 and 2 is: ";
    for (int i=0; i<intArray3.Size(); i++)
    {
        cout << intArray3[i] << ", ";
    }
    cout << endl;

    
    // Test operator * ()
    // Scale intArray2 by 2 and assign it to intArray3
    intArray3 = intArray2 * 2.0;
    
    // Prints results
    cout << "Array 2 times 2 is: ";
    for (int i=0; i<intArray3.Size(); i++)
    {
        cout << intArray3[i] << ", ";
    }
    cout << endl;
    
    
    // Test function DotProduct()
    int dot_product = intArray1.DotProduct(intArray2);  // Take dot product of intArray2 and intArray3
    cout << "Dot product of intArray1 and intArray2: " << dot_product << endl << endl;
    
    
    // Test Size Mismatch Exception catching
    try
    {
        int test_dot_product = intArray1.DotProduct(intArray4); // Try dot product on 2 arrays with different size
        cout<<test_dot_product<<endl;
    }
    catch (ArrayException& ex) // Catch exception object
    {
        cout << ex.GetMessage() << endl;
    }
    
    // Create numeric arrays with Point object
    NumericArray<Point> pts1;
    NumericArray<Point> pts2;
    NumericArray<Point> pts3;
    
    // Check functionality of Array
    cout << "Size of pts1: " << pts1.Size() << endl;
    cout << "pts3[2]: " << pts3[2] << endl;
    
    // Check functionality of NumericArray
    double d = 2.0;
    pts2 = pts1 * d; // Works because Point has * operator
    pts2 = pts1 + pts2; // Works because Point has + operator
    //Point p = pts1.DotProduct(pts2); // Causes error because Point does not have dotproduct
     
    return 0;
    
}


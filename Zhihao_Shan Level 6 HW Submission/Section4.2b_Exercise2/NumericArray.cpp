//
//  NumericArray.cpp
//  Section4.2b_Exercise2
//
//  Created by Zhihao Shan on 2023/7/2.
//
// This file defines functions of Numeric Array template class
// By declaring these functions, we need type T to support T+T, T*double and T*T
#ifndef NumericArray_cpp
#define NumericArray_cpp

#include "NumericArray.hpp"
#include "SizeMismatchException.hpp"

// Default Constructor for NumericArray class
template <typename T>
NumericArray<T>::NumericArray(): Array<T>()
{
    // Calls the base class Array's defualt constructor to initialize the size and allocate memory for the array
}

// Input size Constructor for NumericArray class
template <typename T>
NumericArray<T>::NumericArray(int size): Array<T>(size)
{
    // Calls the base class Array's input size constructor to initialize the size and allocate memory for the array
}

// Copy constructor for NumericArray class
template <typename T>
NumericArray<T>::NumericArray(const NumericArray& source): Array<T>(source)
{
    // Calls the base class Array's copy constructor to copy the elements and size from the other object
}

// Destructor for NumericArray class
template <typename T>
NumericArray<T>::~NumericArray()
{
    // The base class Array's destructor is automatically called
}

// Assignment operator for NumericArray class
template <typename T>
NumericArray<T>& NumericArray<T>::operator=(const NumericArray& source)
{
    // Check fot self assignment
    if (this == &source)
        return *this;
    
    // Calls the base class Array's assignment operator function
    Array<T>::operator = (source);
    return *this;
}


// * operator function
template <typename T>
NumericArray<T> NumericArray<T>::operator*(double factor) const
{
    // initialize result Array to store result
    NumericArray<T> result(this->Size());
    
    // Multiplies each element of the array with the given factor and stores it in the result array
    for (int i = 0; i < NumericArray<T>::Size(); i++)
    {
        result[i] =  (*this)[i] * factor;
    }
    return result;
}

// + operator function
template <typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& arr) const
{
    // throw size mismatch exception if sizes are not the same
    if (this->Size() != arr.Size())
        throw SizeMismatchException();
    
    // initialize result Array to store result
    NumericArray<T> result(arr.Size());
    
    // add corresponding data members of the two arrays
    for (int i=0; i<arr.Size(); i++)
    {
        result[i] = arr.GetElement(i) + this->GetElement(i);
    }
    
    return result;
}


// Function DotProduct()
template <typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& arr) const
{
    // Checks if the arrays have the same size
    if (this->Size() != arr.Size())
        throw SizeMismatchException();
    
    // initialize dp_result to store result
    T dp_result = 0;
    
    // loop through the arrays to get dotproduct
    for (int i=0; i<arr.Size(); i++)
        dp_result += (this->GetElement(i) * arr.GetElement(i));
    
    return dp_result;
}

#endif

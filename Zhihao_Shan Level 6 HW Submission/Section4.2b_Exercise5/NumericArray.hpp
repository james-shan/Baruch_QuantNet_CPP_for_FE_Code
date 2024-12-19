//
//  NumericArray.hpp
//  Section4.2b_Exercise5
//
//  Created by Zhihao Shan on 2023/7/2.
//
// This file is the header file for Numeric Array template class that inherits Array template class
#ifndef NumericArray_hpp
#define NumericArray_hpp
#include "Array.hpp"

template <typename T>
class NumericArray : public Array<T>
{
public:
    NumericArray(); // Default constructor
    NumericArray(int size); // Consturcotr using size input
    NumericArray(const NumericArray& source); // Copy constructor
    ~NumericArray(); // Destructor

    NumericArray& operator=(const NumericArray& source); //Assignment operator

    NumericArray operator*(double factor) const; // * operator
    NumericArray operator+(const NumericArray& other) const; // + operator
    T DotProduct(const NumericArray& other) const; // Dotproduct member function
};

#ifndef NumericArray_cpp
#include "NumericArray.cpp"
#endif

#endif /* NumericArray_hpp */


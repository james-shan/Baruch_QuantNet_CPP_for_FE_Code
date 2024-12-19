//
//  PointArray.hpp
//  Section4.2b_Exercise6
//
//  Created by Zhihao Shan on 2023/7/4.
//
//  This is the header file for PointArray Class

#ifndef PointArray_hpp
#define PointArray_hpp

#include "Point.hpp"
#include "Array.hpp"
#include <iostream>


class PointArray : public Array<Point>
{
public:
    PointArray(); // Default constructor
    PointArray(int size); // Constructor with input size
    PointArray(const PointArray& source); // Copy constructor
    ~PointArray(); // Destructor
    PointArray& operator = (const PointArray& source); // Assignment operator
    
    double Length() const; // Total length between the points in the array
};
#endif /* PointArray_hpp */

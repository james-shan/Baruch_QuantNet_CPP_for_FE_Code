//
//  PointArray.cpp
//  Section4.2b_Exercise3
//
//  Created by Zhihao Shan on 2023/7/4.
//
//  This file defines functionality of PointArray class

#include "PointArray.hpp"
#include "LengthNotEnoughException.hpp"


// Default constructor
// Calls the base class Array's defualt constructor to initialize the size and allocate memory for the array
PointArray::PointArray() : Array<Point>()
{
    //cout << "PointArray constructed by default." << endl;
}

// Constructor with input size
// Calls the base class Array's input size constructor to initialize the size and allocate memory for the array
PointArray::PointArray(int size) : Array<Point>(size)
{
    //cout << "PointArray constructor with input size." << endl;
}

// Copy constructor
// Calls the base class Array's copy constructor to copy the elements and size from the other object
PointArray::PointArray(const PointArray& source) : Array<Point>(source)
{
    //cout << "PointArray constructed by copy." << endl;
}

// Destructor
// The base class Array's destructor is automatically called
PointArray::~PointArray()
{
    //cout << "PointArray destructed." << endl;
}

// Assignment operator
PointArray& PointArray::operator = (const PointArray& source)
{
    // Check fot self assignment
    if (this == &source)
        return *this;
    
    // Calls the base class Array's assignment operator function
    Array<Point>::operator = (source);
    return *this;
}


// Total length between the points in the array
double PointArray::Length() const
{
    // throw error if there are less than or equal to 1 point in the array
    if (this->Size() <= 1)
        throw LengthNotEnoughException();
    
    // get total length between neighboring points in the array using for loop and Point.Distance() function
    double length = 0.0;
    for (int i = 1; i < this->Size(); i++)
    {
        length += (this->GetElement(i-1)).Distance(this->GetElement(i));
    }
    
    return length;
}


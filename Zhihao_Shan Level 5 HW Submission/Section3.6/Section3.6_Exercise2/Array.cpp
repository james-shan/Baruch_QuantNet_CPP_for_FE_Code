//
//  Array.cpp
//  Section3.6_Exercise1
//
//  Created by Zhihao Shan on 2023/6/28.
//
// This file defines the functions of Array class

#include "Array.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>

// default constructor
Array::Array()
{
    // default size set to 10 and create dynamic memory for Point
    m_size = 10;
    m_data = new Point[m_size];
    
    std::cout<< "Array created by default"<<endl;
}

// constructor with size argument
Array::Array(int size)
{
    // set size to given int and create dynamic memory for Point
    m_size = size;
    m_data = new Point[m_size];
    
    std::cout<< "Array created with input size"<<endl;
}

// copy constructor
Array::Array(const Array& source)
{
    // set size to source size and create dynamic memory for Point
    m_size = source.m_size;
    m_data = new Point[m_size];
    
    // iterate through the source using index and copy the points
    for (int i = 0; i < m_size; i++)
        m_data[i] = source.m_data[i];
    
    std::cout<< "Array created by copy"<<endl;
}

// Destructor
Array::~Array()
{
    // delete internal C array
    delete [] m_data;
    
    std::cout<< "Array destructed"<<endl;
}


// Assignment operator
Array& Array::operator = (const Array& source)
{
    // avoid assigning to itself
    if (this == &source)
        return *this;
    
    // delete current data and initialize
    delete [] m_data;
    m_size = source.m_size;
    m_data = new Point[m_size];
    
    // use iteration to assign new data
    for (int i = 0; i < m_size; i++)
        m_data[i] = source.m_data[i];
        
    return *this;
}

// Member functions
int Array::Size() const // get array size
{
    return m_size;
}

//--------------------------------------------------------------------
// Modified functions below to throw OutOfBoundsException at exception

// Get element at given index
const Point& Array::GetElement(int index) const
{
    // throw OutOfBoundsException at excpetion
    if (index >= m_size || index < 0)
        throw OutOfBoundsException(index);
    
    // normal return
    return m_data[index];
}

// Set element at given index
void Array::SetElement(int index, const Point& point)
{

    // throw OutOfBoundsException at excpetion
    if (index >= m_size || index < 0)
        throw OutOfBoundsException(index);
    
    // set element if index is legit
    m_data[index] = point;
}

// Square bracket operator
Point& Array::operator [] (int index)
{
    // throw OutOfBoundsException at excpetion
    if (index >= m_size || index < 0)
        throw OutOfBoundsException(index);
    
    // normal return
    return m_data[index];
}

// Const Square bracket operator
const Point& Array::operator[](int index) const
{
    // throw OutOfBoundsException at excpetion
    if (index >= m_size || index < 0)
        throw OutOfBoundsException(index);
    
    // normal return
    return m_data[index];
}

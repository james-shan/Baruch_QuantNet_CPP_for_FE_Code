//
//  Array.cpp
//  Section4.2b_Exercise3
//
//  Created by Zhihao Shan on 2023/7/2.
//
// This file defines the functions of Array class


#ifndef Array_cpp
#define Array_cpp

#include "Array.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>

// static variable default size
template <typename T>
int Array<T>::d_size = 5;

// default constructor
// default size set to 10 and create dynamic memory for typename T
template <typename T>
Array<T>::Array(): m_size(Array<T>::d_size), m_data(new T[Array<T>::d_size])
{
    //std::cout<< "Array created by default"<<endl;
}

// constructor with size argument
// set size to given int and create dynamic memory for typename T
template <typename T>
Array<T>::Array(int size): m_size(size), m_data(new T[size])
{
    //std::cout<< "Array created with input size"<<endl;
}

// copy constructor
template <typename T>
Array<T>::Array(const Array<T>& source): m_size(source.m_size), m_data(new T[source.m_size])
{
    // set size to source size and create dynamic memory for typename T
    // iterate through the source using index and copy the "T"s
    for (int i = 0; i < m_size; i++)
        m_data[i] = source.m_data[i];
    
    //std::cout<< "Array created by copy"<<endl;
}

// Destructor
template <typename T>
Array<T>::~Array()
{
    // delete internal C array
    delete [] m_data;
    
    //std::cout<< "Array destructed"<<endl;
}


// Assignment operator
template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& source)
{
    // avoid assigning to itself
    if (this == &source)
        return *this;
    
    // delete current data and initialize
    delete [] m_data;
    m_size = source.m_size;
    m_data = new T[m_size];
    
    // use iteration to assign new data
    for (int i = 0; i < m_size; i++)
        m_data[i] = source.m_data[i];
        
    return *this;
}

// Member functions
template <typename T>
int Array<T>::Size() const // get array size
{
    return m_size;
}

// Get element at given index
template <typename T>
const T& Array<T>::GetElement(int index) const
{
    // throw OutOfBoundsException at excpetion
    if (index >= m_size || index < 0)
        throw OutOfBoundsException(index);
    
    // normal return
    return m_data[index];
}

// Set element at given index
template <typename T>
void Array<T>::SetElement(int index, const T& t)
{

    // throw OutOfBoundsException at excpetion
    if (index >= m_size || index < 0)
        throw OutOfBoundsException(index);
    
    // set element if index is legit
    m_data[index] = t;
}

// Square bracket operator
template <typename T>
T& Array<T>::operator [] (int index)
{
    // throw OutOfBoundsException at excpetion
    if (index >= m_size || index < 0)
        throw OutOfBoundsException(index);
    
    // normal return
    return m_data[index];
}

// Const Square bracket operator
template <typename T>
const T& Array<T>::operator[](int index) const
{
    // throw OutOfBoundsException at excpetion
    if (index >= m_size || index < 0)
        throw OutOfBoundsException(index);
    
    // normal return
    return m_data[index];
}

//------------------------------------------------------------

// Getter function for d_size
template <typename T>
int Array<T>::DefaultSize() const
{
    return d_size;
}

// Setter function for d_size
template <typename T>
void Array<T>::DefaultSize(int size)
{
    d_size = size;
}

#endif

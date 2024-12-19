//
//  Array.hpp
//  Section4.2b_Exercise1
//
//  Created by Zhihao Shan on 2023/7/2.
//
//  This is the header file for Array Class

#ifndef Array_hpp
#define Array_hpp
#include <stdio.h>
#include "Point.hpp"

template <typename T>
class Array
{
private:
    // store array size
    int m_size;
    
    // dynamic C array of Point objects
    T *m_data;
    
    // static variable default size
    static int d_size;
    
public:
    // Constructors and Destructor
    Array(); // default constructor
    Array(int size); // constructor with size argument
    Array(const Array<T>& source); // copy constructor
    
    // Destructor
    ~Array();
    
    // Assignment operator
    Array<T>& operator = (const Array<T>& source);
    
    // Member functions
    int Size() const; // get array size
    const T& GetElement(int index) const; // Get element at given index
    void SetElement(int index, const T& t); // Set element at given index
    
    // Sqauire bracket operator overloading
    T& operator [] (int index); // Square bracket operator
    const T& operator[] (int index) const; // Const Square bracket operator
    
    // Getter and Setter for default size
    int DefaultSize() const; // Get the default size of the array
    void DefaultSize(int size); // Set the default size
};

#ifndef Array_cpp 
#include "Array.cpp"
#endif

#endif /* Array_hpp */

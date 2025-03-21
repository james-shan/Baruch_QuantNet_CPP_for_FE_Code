//
//  Stack.hpp
//  Section4.2b_Exercise4
//
//  Created by Zhihao Shan on 2023/7/5.
//
// This file is the header file for Stack template class

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#include "Array.hpp"

template <typename T>
class Stack
{
private:
    int m_current; // Current index
    Array<T> m_array; // Data stored in array
    
public:
    Stack(); // Default constructor
    Stack(int size); // Constructor with input size
    Stack(Stack& source); // Copy Constructor
    virtual ~Stack(); // Destructor
    
    Stack& operator = (const Stack& source); // Assignment operator
    
    void Push(T element); // Add new element to the stack
    T Pop(); // Return and delete the top element from the stack
    
};

#ifndef Stack_cpp
#include "Stack.cpp"
#endif

#endif /* Stack_hpp */

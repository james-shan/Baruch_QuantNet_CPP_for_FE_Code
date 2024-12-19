//
//  Stack.cpp
//  Section4.2b_Exercise6
//
//  Created by Zhihao Shan on 2023/7/5.
//
// This file defines functionality for Stack template class
// modified to use an int size as template

#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"
#include "ArrayException.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

// Default constructor
template <typename T, int size>
Stack<T, size>::Stack() : m_current(0), m_array(size)
{
    //cout << "Stack constructed by default." << endl;
}


// Copy constructor
template <typename T, int size>
Stack<T, size>::Stack(Stack& source) : m_current(source.m_current), m_array(source.m_array)
{
    //cout << "Stack contructed by copy." << endl;
}

// Destructor
template <typename T, int size>
Stack<T, size>::~Stack()
{
    //cout << "Stack Destructed." << endl;
}

// Assignment operator
template <typename T, int size>
Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source)
{
    // Check for self assignment
    if (this == &source)
        return *this;
    
    m_current = source.m_current;
    m_array = source.m_array;

    return *this;
}


// Push function
template <typename T, int size>
void Stack<T, size>::Push(T element)
{
    // Try...Catch to handle exception
    try
    {
        m_array[m_current] = element;
        m_current++;
    }
    catch(ArrayException& ex)
    {
        throw StackFullException();
    }
}

// Pop function
template <typename T, int size>
T Stack<T, size>::Pop()
{
    
    // Try...Catch to handle exception
    try
    {
        T top = m_array[m_current-1];
        m_current--;
        return top;
    }
    catch(ArrayException& ex)
    {
        throw StackEmptyException();
    }
}

#endif

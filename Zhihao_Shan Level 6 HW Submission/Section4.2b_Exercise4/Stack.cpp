//
//  Stack.cpp
//  Section4.2b_Exercise4
//
//  Created by Zhihao Shan on 2023/7/5.
//
// This file defines functionality for Stack template class

#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"


// Default constructor
template <typename T>
Stack<T>::Stack() : m_current(0), m_array()
{
    //cout << "Stack constructed by default." << endl;
}

// Constructor with input size
template <typename T>
Stack<T>::Stack(int size) : m_current(0), m_array(size)
{
    //cout << "Stack constructed with input size." << endl;
}

// Copy constructor
template <typename T>
Stack<T>::Stack(Stack& source) : m_current(source.m_current), m_array(source.m_array)
{
    //cout << "Stack contructed by copy." << endl;
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
    //cout << "Stack Destructed." << endl;
}

// Assignment operator
template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& source)
{
    // Check for self assignment
    if (this == &source)
        return *this;
    
    m_current = source.m_current;
    m_array = source.m_array;

    return *this;
}


// Push function
template <typename T>
void Stack<T>::Push(T element)
{
    // if index out of bounds, do not run to m_current ++
    m_array[m_current] = element;
    m_current++;
}

// Pop function
template <typename T>
T Stack<T>::Pop()
{
    T top = m_array[m_current-1];
    m_current--;
    
    return top;
}

#endif

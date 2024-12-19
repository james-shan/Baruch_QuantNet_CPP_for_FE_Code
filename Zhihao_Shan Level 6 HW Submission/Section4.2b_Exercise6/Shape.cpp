//
//  Shape.cpp
//  Section4.2b_Exercise6
//
//  Created by Zhihao Shan on 2023/7/2.
//
// This file defines functions of Shape class

#include "Shape.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

// Default Constuctor using rand to randomly set up id
Shape::Shape(): m_id(rand()) {}

// Copy constructor
Shape::Shape(const Shape& other): m_id(other.ID()) {}


// Destructor with message
Shape::~Shape()
{
    //std::cout<<"Shape destructed"<<endl;
}

// Assignment operator
Shape& Shape::operator=(const Shape& source)
{
    if (this == &source)
        return *this;
    
    m_id = source.ID();
    return *this;
}

// member function ID to return m_id as int
int Shape::ID() const
{
    return m_id;
}

// member function ToString to return a string of the current object
string Shape::ToString() const
{
    stringstream ss;
    ss << "ID:" << this->ID();
    return ss.str();
}

// Print function that calls ToString() (Template Method Pattern)
void Shape::Print() const
{
    cout<<"Pringting shape: "<< this->ToString()<<endl;
}

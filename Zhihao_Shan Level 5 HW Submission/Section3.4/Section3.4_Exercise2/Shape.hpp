//
//  Shape.hpp
//  HW2.4_Exercise1
//
//  Created by Zhihao Shan on 2023/6/24.
//
// This file is header file for shape class

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Shape
{
private:
    // id number with type int
    int m_id;
    
public:
    // Constructors
    Shape(); // Default Constructor
    Shape(const Shape& other); // Copy Constructor
    
    // Destructor
    ~Shape();
    
    // Assignment Operator
    Shape& operator=(const Shape& source);
    
    
    // ID function to retreive ID as int
    int ID() const;
    
    // To string function
    string ToString() const;
};

#endif

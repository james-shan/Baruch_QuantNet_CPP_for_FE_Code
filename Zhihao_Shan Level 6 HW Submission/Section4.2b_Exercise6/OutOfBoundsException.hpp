//
//  OutOfBoundsException.hpp
//  Section4.2b_Exercise6
//
//  Created by Zhihao Shan on 2023/7/2.
//
// This file defines class OutOfBounndsExeception which inherits ArrayException to handle out of bound exception when indexing an array

#ifndef OutOfBoundsException_hpp
#define OutOfBoundsException_hpp
#include "ArrayException.hpp"

class OutOfBoundsException : public ArrayException
{
private:
    int m_index; // Store the erroneous array index

public:
    // Constructor that takes an integer argument to indicate the index
    OutOfBoundsException(int index) : m_index(index) {}

    // Override the GetMessage() function to return the error message
    std::string GetMessage() const
    {
        return "Error: Index " + std::to_string(m_index) + " is out of bounds.";
    }
};

#endif 

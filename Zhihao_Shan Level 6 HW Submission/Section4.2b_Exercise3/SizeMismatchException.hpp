//
//  SizeMismatchException.hpp
//  Section4.2b_Exercise3
//
//  Created by Zhihao Shan on 2023/7/2.
//
// This file defines class SizeMismatchException which inherits ArrayException
#ifndef SizeMismatchException_hpp
#define SizeMismatchException_hpp
#include "ArrayException.hpp"

class SizeMismatchException: public ArrayException
{
public:
    // Override the GetMessage() function to return the error message for size mismatch in dot product or add fucntion of Numeric Array
    std::string GetMessage() const
    {
        return "Error, size of arrays do not match.";
    }
};

#endif 

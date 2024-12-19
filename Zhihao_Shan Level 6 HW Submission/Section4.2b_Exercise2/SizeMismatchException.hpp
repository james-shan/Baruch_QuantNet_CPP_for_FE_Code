//
//  SizeMismatchException.h
//  Section4.2b_Exercise2
//
//  Created by Zhihao Shan on 2023/7/2.
//

#ifndef SizeMismatchException_hpp
#define SizeMismatchException_hpp
#include "ArrayException.hpp"

class SizeMismatchException : public ArrayException
{
public:
    // Override the GetMessage() function to return the error message
    std::string GetMessage() const
    {
        return "Error, size of arrays do not match.";
    }
};

#endif /* SizeMismatchException_hpp */

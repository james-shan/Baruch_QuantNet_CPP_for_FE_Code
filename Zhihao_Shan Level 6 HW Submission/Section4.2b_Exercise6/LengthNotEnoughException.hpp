//
//  TotalLengthException.hpp
//  Section4.2b_Exercise6
//
//  Created by Zhihao Shan on 2023/7/4.
//
// This file defines class LengthNotEnoughException which inherits ArrayException

#ifndef LengthNotEnoughException_hpp
#define LengthNotEnoughException_hpp

#include "ArrayException.hpp"


class LengthNotEnoughException : public ArrayException
{
public:
    std::string GetMessage() const
    {
        // Return the the error message
        return "This Point array of do not have enough points to calculate length.";
    }
};

#endif 

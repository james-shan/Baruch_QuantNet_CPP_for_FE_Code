//
//  StackEmptyException.hpp
//  Section4.2b_Exercise5
//
//  Created by Zhihao Shan on 2023/7/5.
//
// This file creates StackEmptyException class that inherits StackException

#ifndef StackEmptyException_hpp
#define StackEmptyException_hpp

#include "StackException.hpp"

class StackEmptyException : public StackException
{
public:
    std::string GetMessage() const
    {
        // Return the the error message
        return "Stack is empty. Pop is invalid!";
    }
};


#endif /* StackEmptyException_hpp */

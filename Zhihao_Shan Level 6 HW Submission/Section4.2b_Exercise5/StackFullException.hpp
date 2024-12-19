//
//  StackFullException.hpp
//  Section4.2b_Exercise5
//
//  Created by Zhihao Shan on 2023/7/5.
//
// This file creates StackFullException class that inherits StackException

#ifndef StackFullException_hpp
#define StackFullException_hpp

#include "StackException.hpp"

class StackFullException : public StackException
{
public:
    std::string GetMessage() const
    {
        // Return the the error message
        return "Stack is full. Push is invalid!";
    }
};

#endif /* StackFullException_hpp */

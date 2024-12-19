//
//  StackException.hpp
//  Section4.2b_Exercise6
//
//  Created by Zhihao SHan on 2023/7/5.
//
// This file defines Stack Exception base class with virtual function GetMessage

#ifndef StackException_hpp
#define StackException_hpp

class StackException
{
public:
    virtual std::string GetMessage() const = 0;
};


#endif /* StackException_hpp */

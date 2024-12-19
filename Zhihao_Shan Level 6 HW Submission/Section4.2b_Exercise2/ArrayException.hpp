//
//  ArrayException.h
//  Section4.2b_Exercise2
//
//  Created by Zhihao Shan on 2023/7/2.
//
// This file defines base class ArrayException

#ifndef ArrayException_hpp
#define ArrayException_hpp

// Base class ArrayException
class ArrayException
{
public:
    // PVMF GetMessage
    virtual std::string GetMessage() const = 0;
};

#endif /* ArrayException_hpp */

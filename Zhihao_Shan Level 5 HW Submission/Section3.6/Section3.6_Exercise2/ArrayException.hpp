//
//  ArrayException.hpp
//  Section3.6_Exercise2
//
//  Created by Zhihao Shan on 2023/6/28.
//

#ifndef ArrayException_hpp
#define ArrayException_hpp

// Base class ArrayException
class ArrayException
{
public:
    // PVMF GetMessage
    virtual std::string GetMessage() const = 0;
};

#endif

//
//  SmallerThan.hpp
//  Section4.7_Exercise3
//
//  Created by Zhihao Shan on 2023/7/8.
//
// This file is the header file for SmallerThan class

#ifndef SmallerThan_hpp
#define SmallerThan_hpp

#include <stdio.h>


class SmallerThan
{
public:
    SmallerThan(double value) : threshold(value) {}

    // Overloaded function call operator
    bool operator()(double input) const
    {
        return input < threshold;
    }

private:
    double threshold;
};

#endif /* SmallerThan_hpp */

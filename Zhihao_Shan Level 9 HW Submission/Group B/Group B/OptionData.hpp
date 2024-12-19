//
//  OptionData.hpp
//  GroupB
//
//  Created by Zhihao Shan on 2023/7/18.
//
//  This file define struct of Optiondata

#ifndef OptionData_hpp
#define OptionData_hpp

struct OptionData
{
    double T; // Expiry date
    double K; // Strike price
    double sig; // Volatility
    double r;  // Interest rate
    double b; // Cost of carray
    double S; // Asset Price
};

#endif /* OptionData_hpp */

//
//  AmericanOption.hpp
//  Group B
//
//  Created by Zhihao Shan on 2023/7/23.
//
// This is the header file of AmericanOption Class that inherits OptionBaseClass

#ifndef AmericanOption_hpp
#define AmericanOption_hpp

#include "OptionBaseClass.hpp"
#include "PricingFuncs.hpp"
#include "ArrayFuncs.hpp"
#include <cmath>
#include <string>
using namespace std;

class AmericanOption: public OptionBaseClass
{
    
public:
    
    // Overridng Setter for Perpetual Option: no Expiration time T
    void SetOption(double newK, double newsig, double newr, double newb, double newS);// Set all private data of class

    // Pricing Functions
    double PerpetualPrice(); // Perpetual call and put option price
    vector<double> PerpetualPrice(const vector<double>& S_array); // Get price with a vector of S
    vector<vector<double>> PerpetualPrice(const vector<vector<double>>& param_matrix); // Get price with parameter matrix
    
};

#endif /* AmericanOption_hpp */

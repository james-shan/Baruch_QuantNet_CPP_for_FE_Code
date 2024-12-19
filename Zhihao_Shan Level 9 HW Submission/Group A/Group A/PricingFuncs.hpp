//
//  PricingFuncs.hpp
//  roupA
//
//  Created by Zhihao Shan on 2023/7/18.
//
//  This is the header file for PricingFuncs

#ifndef PricingFuncs_hpp
#define PricingFuncs_hpp

#include "OptionData.hpp"

// Gaussian functions
double n(double x);
double N(double x);


// Overloaded pricing functions
double CallPrice(double T, double K, double sig, double r, double b, double S);
double CallPrice(const OptionData& data);

double PutPrice(double T, double K, double sig, double r, double b, double S);
double PutPrice(const OptionData& data);

// Overloaded Greeks functions
// Gamma (exact formula)
double Gamma(double T, double K, double sig, double r, double b, double S);
double Gamma(const OptionData& data);

// Gamma (divided difference approximation)
double Gamma(double T, double K, double sig, double r, double b, double S, double h);
double Gamma(const OptionData& data, double h);


// Delta for call (exact formula)
double CallDelta(double T, double K, double sig, double r, double b, double S);
double CallDelta(const OptionData& data);

// Delta for call (divided difference approximation)
double CallDelta(double T, double K, double sig, double r, double b, double S, double h);
double CallDelta(const OptionData& data, double h);


// Delta for put (exact formula)
double PutDelta(double T, double K, double sig, double r, double b, double S);
double PutDelta(const OptionData& data);

// Delta for put (divided difference approximation)
double PutDelta(double T, double K, double sig, double r, double b, double S, double h);
double PutDelta(const OptionData& data, double h);

#endif /* PricingFuncs_hpp */

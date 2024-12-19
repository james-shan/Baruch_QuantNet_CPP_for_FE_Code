//
//  EuropeanOption.hpp
//  GroupB
//
//  Created by Zhihao Shan on 2023/7/18.
//
//  This is the header file for European options class that inherits Option base class

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include "PricingFuncs.hpp"
#include "ArrayFuncs.hpp"
#include <cmath>
#include <string>
#include "OptionBaseClass.hpp"
using namespace std;

class EuropeanOption: public OptionBaseClass
{

public:
    
    // --------------------Pricing-----------------------
    // Exact C and P price function overloading
    double CallPriceEuro(); // price if option is call
    double PutPriceEuro();  // price if option is put
    double PriceEuro(); // Get price of current option type
    vector<double> PriceEuro(const vector<double>& S_array); // Get price with a vector of S
    vector<vector<double>> PriceEuro(const vector<vector<double>>& param_matrix); // Get price with parameter matrix
    bool PutCallParity();   // check Put-Call parity
    
    // Alternative way to check put call parity through returning the price of the other type
    // double PutCallParity();
    
    // ---------------------Greeks-----------------------
    double DeltaEuro() const; // Delta (exact formula)
    double DeltaEuro(double h) const; // Delta (divided difference approximation)
    double GammaEuro() const; // Gamma (exact formula)
    double GammaEuro(double h) const; // Gamma (divided difference approximation)
    
    // Input a range of S, and output a vector delta for call/put
    vector<double> DeltaEuro(const vector<double>& S_array); // Exact formula
    vector<double> DeltaEuro(const vector<double>& S_array, double h); // Difference approximation

    // Input a matrix of parameters, and output corresponding gamma/delta
    vector<vector<double>> DeltaEuro(const vector<vector<double>>& param_matrix); // Get delta with parameter matrix
    vector<vector<double>> GammaEuro(const vector<vector<double>>& param_matrix); // Get gamma with parameter matrix
   

};

#endif /* EuropeanOption_hpp */

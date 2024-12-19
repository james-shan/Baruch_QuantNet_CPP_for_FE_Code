//
//  EuropeanOption.cpp
//  GroupA
//
//  Created by Zhihao Shan on 2023/7/18.
//
//  This file defines pricing and getting greeks functions for EuropeanOption Class

#ifndef EuropeanOption_cpp
#define EuropeanOption_cpp

#include "EuropeanOption.hpp"
#include "PricingFuncs.hpp"
#include "ArrayFuncs.hpp"
#include <cmath>
#include <string>
using namespace std;


// --------------------------------- Pricing ----------------------------------- //

// Price of Call European Option
double EuropeanOption::CallPriceEuro()
{
    return CallPrice(GetData());
}

// Price of Put European Option
double EuropeanOption::PutPriceEuro()
{
    return PutPrice(GetData());
}

// Price of European Option depending on type
double EuropeanOption::PriceEuro()
{
    if (OptionType()=="C")
    {
        return CallPrice(GetData());
    }
    else
    {
        return PutPrice(GetData());
    }
}

// Price of European Option with varying range of S
vector<double> EuropeanOption::PriceEuro(const vector<double>& S_array)
{ // Delta for call as a function of varying S (exact formula)
    
    double originalS = S();
    vector<double> prices;
    for (int i = 0; i < S_array.size(); ++i)
    {
        S(S_array[i]); // Update S of option
        prices.push_back(PriceEuro());
    }
    
    S(originalS); // restore orignial value of S
    return prices;
}

// Price of European Option with varying parameter matrix
vector<vector<double>> EuropeanOption::PriceEuro(const vector<vector<double>>& param_matrix)
{
    OptionData OriginalData = GetData();
    vector<vector<double>> prices;
    for (int i = 0; i < param_matrix.size();++i)
    {
        vector<double> param_array = param_matrix[i];
        vector<double> tmp_res;
        for (int j = 0; j < param_array.size(); ++j)
        {
            if (i==0) T(param_array[j]);
            else if(i==1) K(param_array[j]);
            else if(i==2) sig(param_array[j]);
            else if(i==3) r(param_array[j]);
            else if(i==4) b(param_array[j]);
            else if(i==5) S(param_array[j]);
            tmp_res.push_back(PriceEuro());
        }
        prices.push_back(tmp_res);
        SetData(OriginalData);
    }
    return prices;
}

// Alternative way to check put call parity through returning the price of the other type
/*
double EuropeanOption::PutCallParity()
{
    if (OptionType()=="C")
    {
        return CallPriceEuro() - S() + K() * exp(-r()*T());
    }
    else
    {
        return PutPriceEuro() + S()- K() * exp(-r()*T());
    }
   
}
*/

// Check put call parity
bool EuropeanOption::PutCallParity()
{
    // Define a tolerance level for put-call parity match
    double tolerance = 0.000001;
    double putprice1, putprice2;
    
    putprice1 = CallPriceEuro() - S() + K() * exp(-r()*T());
    putprice2 = PutPriceEuro();
    
    return (fabs(putprice1-putprice2)<tolerance);
}



// ------------------------------------ Greeks --------------------------------------- //

// Delta (Exact)
double EuropeanOption::DeltaEuro() const
{
    //
    if (OptionType() =="C")
    {
        return CallDelta(GetData()); // Use Delta in PricingFuncs
    }
    else
    {
        return PutDelta(GetData()); // Use Delta in PricingFuncs
    }
}

// Delta (divided difference approximation)
double EuropeanOption::DeltaEuro(double h) const
{
    if (OptionType() =="C")
    {
        return CallDelta(GetData(), h); // Use Delta in PricingFuncs
    }
    else
    {
        return PutDelta(GetData(), h); // Use Delta in PricingFuncs
    }
}


// Delta for call as a function of varying S (exact formula)
vector<double> EuropeanOption::DeltaEuro(const vector<double>& S_array)
{
    double originalS = S();
    vector<double> deltas;
    for (int i = 0; i < S_array.size(); ++i)
    {
        S(S_array[i]); // Update S of option
        deltas.push_back(DeltaEuro());
    }
    S(originalS); // restore orignial value of S
    
    return deltas;
}

// Delta for call as a function of varying S (divided difference approximation)
vector<double> EuropeanOption::DeltaEuro(const vector<double>& S_array, double h)
{
    double originalS = S();
    vector<double> deltas;
    for (int i = 0; i < S_array.size(); ++i)
    {
        S(S_array[i]); // Update S of option
        deltas.push_back(DeltaEuro(h));
    }
    S(originalS); // restore orignial value of S
    
    return deltas;
}

// Delta for parameter matrix (Exact)
vector<vector<double>> EuropeanOption::DeltaEuro(const vector<vector<double>>& param_matrix)
{
    OptionData OriginalData = GetData();
    vector<vector<double>> deltas;
    for (int i = 0; i < param_matrix.size();++i)
    {
        vector<double> param_array = param_matrix[i];
        vector<double> tmp_res;
        for (int j = 0; j < param_array.size(); ++j)
        {
            if (i==0) T(param_array[j]);
            else if(i==1) K(param_array[j]);
            else if(i==2) sig(param_array[j]);
            else if(i==3) r(param_array[j]);
            else if(i==4) b(param_array[j]);
            else if(i==5) S(param_array[j]);
            tmp_res.push_back(DeltaEuro());
        }
        deltas.push_back(tmp_res);
        SetData(OriginalData);
    }
    return deltas;
}

// Gamma (exact formula)
double EuropeanOption::GammaEuro() const
{
    return Gamma(GetData()); // Call Gamma in PricingFuncs
}

// Gamma (divided difference approximation)
double EuropeanOption::GammaEuro(double h) const
{
    return Gamma(GetData(), h); // Call Gamma in PricingFuncs
}

// Gamma for parameter matrix (Exact)
vector<vector<double>> EuropeanOption::GammaEuro(const vector<vector<double>>& param_matrix)
{
    OptionData OriginalData = GetData();
    vector<vector<double>> gammas;
    for (int i = 0; i < param_matrix.size();++i)
    {
        vector<double> param_array = param_matrix[i];
        vector<double> tmp_res;
        for (int j = 0; j < param_array.size(); ++j)
        {
            if (i==0) T(param_array[j]);
            else if(i==1) K(param_array[j]);
            else if(i==2) sig(param_array[j]);
            else if(i==3) r(param_array[j]);
            else if(i==4) b(param_array[j]);
            else if(i==5) S(param_array[j]);
            tmp_res.push_back(GammaEuro());
        }
        gammas.push_back(tmp_res);
        SetData(OriginalData);
    }
    return gammas;
}



#endif /* EuropeanOption_cpp */


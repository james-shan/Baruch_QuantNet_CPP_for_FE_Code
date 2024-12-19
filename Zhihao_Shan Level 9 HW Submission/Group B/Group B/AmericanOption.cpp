//
//  AmericanOption.cpp
//  Group B
//
//  Created by Zhihao Shan on 2023/7/23.
//
//  This file implements functionalities for AmericanOption Class

#include "AmericanOption.hpp"
#include "PricingFuncs.hpp"


// Overiding setter for American Option
void AmericanOption::SetOption(double newK, double newsig, double newr, double newb, double newS)
{
    K(newK);
    sig(newsig);
    r(newr);
    b(newb);
    S(newS);
}


// Get price based on option type
double AmericanOption::PerpetualPrice()
{
    if (OptionType()=="C")
    {
        return CallPricePerpetual(K(), sig(), r(), b(), S()); // Call function in PricingFuncs
    }
    else
    {
        return PutPricePerpetual(K(), sig(), r(), b(), S()); // Call function in PricingFuncs
    }
}


// Price of Perpetual American Option with varying range of S
vector<double> AmericanOption::PerpetualPrice(const vector<double>& S_array)
{ // Delta for call as a function of varying S (exact formula)
    
    double originalS = S();
    vector<double> prices;
    for (int i = 0; i < S_array.size(); ++i)
    {
        S(S_array[i]); // Update S of option
        prices.push_back(PerpetualPrice());
    }
    
    S(originalS); // restore orignial value of S
    return prices;
}


// Price of Perpetual American Option with varying parameter matrix
vector<vector<double>> AmericanOption::PerpetualPrice(const vector<vector<double>>& param_matrix)
{
    OptionData OriginalData = GetData();
    vector<vector<double>> prices;
    for (int i = 0; i < param_matrix.size();++i)
    {
        vector<double> param_array = param_matrix[i];
        vector<double> tmp_res;
        for (int j = 0; j < param_array.size(); ++j)
        {
            if (i==0) K(param_array[j]);
            else if(i==1) sig(param_array[j]);
            else if(i==2) r(param_array[j]);
            else if(i==3) b(param_array[j]);
            else if(i==4) S(param_array[j]);
            tmp_res.push_back(PerpetualPrice());
        }
        prices.push_back(tmp_res);
        SetData(OriginalData);
    }
    return prices;
}




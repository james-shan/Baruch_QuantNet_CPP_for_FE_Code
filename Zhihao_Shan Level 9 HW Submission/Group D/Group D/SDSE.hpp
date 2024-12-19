//
//  SDSE.hpp
//  Group D
//

#ifndef SDSE_hpp
#define SDSE_hpp

#include <cmath>
#include <vector>


// Function to calculate the sample standard deviation of a vector of prices
double optionSD(const vector<double>& prices, double r, double T)
{
    double CTj = 0.0;    // Accumulator for summing up all prices
    double CTjsq = 0.0;  // Accumulator for summing up the square of prices
    long NSim = prices.size();  // Number of elements in the 'prices' vector

    for (long i = 0; i < NSim; i++)
    {
        CTj += prices[i];  // Summing up all the prices
        CTjsq += prices[i] * prices[i];  // Summing up the square of each price
    }

    // Calculating the sample standard deviation and discounting it to present value
    return sqrt((CTjsq - (CTj * CTj) / NSim) / (NSim - 1)) * exp(-r * T);
}

// Function to calculate the standard error of the mean of a vector of prices
double optionSE(const vector<double>& prices, double r, double T)
{
    return optionSD(prices, r, T) / sqrt(prices.size());  // Using optionSD() to calculate SD and then dividing it by the square root of the sample size
}

#endif /* SDSE_hpp */


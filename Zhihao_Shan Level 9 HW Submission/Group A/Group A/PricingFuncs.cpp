//
//  PricingFuncs.cpp
//  GroupA
//
//  Created by Zhihao Shan on 2023/7/18.
//
//  This file implements mathemetical formulas for computing option price and greeks

#include "PricingFuncs.hpp"
#include <cmath>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
using namespace std;
using namespace boost::math;

// --------------------------- Gausian functions ----------------------------- //
// PDF of normal distribution
double n(double x)
{
    // More accurate using boost normal distribution
    normal_distribution<> myNormal(0.0, 1.0);
    return pdf(myNormal, x);
    
}

// CDF of normal distribution
double N(double x)
{
    // More accurate using boost normal distribution
    normal_distribution<> myNormal(0.0, 1.0);
    return cdf(myNormal, x);
    
}


// --------------------------- Exact C and P Option Prices ----------------------------- //
// Call option price
double CallPrice(double T, double K, double sig, double r, double b, double S)
{
    double d1 = (log(S/K) + (b + (sig*sig)*0.5) * T)/(sig * sqrt(T));
    double d2 = d1 - sig * sqrt(T);
    
    return (S * exp((b-r)*T) * N(d1)) - (K * exp(-r*T) * N(d2));
}

double CallPrice(const OptionData& data)
{
    return CallPrice(data.T, data.K, data.sig, data.r, data.b, data.S);
}


// Put option price
double PutPrice(double T, double K, double sig, double r, double b, double S)
{
    double d1 = (log(S/K) + (b + (sig*sig)*0.5) * T)/(sig * sqrt(T));
    double d2 = d1 - sig * sqrt(T);
    
    return (K * exp(-r*T) * N(-d2)) - (S * exp((b-r)*T) * N(-d1));
}

double PutPrice(const OptionData& data)
{
    return PutPrice(data.T, data.K, data.sig, data.r, data.b, data.S);
}


// ------------------------------ Greeks --------------------------------- //
// Gamma (exact formula)
double Gamma(double T, double K, double sig, double r, double b, double S)
{
    double d1 = (log(S/K) + (b + (sig*sig)*0.5) * T) / (sig * sqrt(T));
    
    return (n(d1) * exp((b-r)*T)) / (S* sig * sqrt(T));
}

double Gamma(const OptionData& data)
{
    return Gamma(data.T, data.K, data.sig, data.r, data.b, data.S);
}

// Gamma (divided difference approximation)
double Gamma(double T, double K, double sig, double r, double b, double S, double h)
{
    double S1, S2;
    S1 = S - h;
    S2 = S + h;
    
    return (CallPrice(T, K, sig, r, b, S2) - 2 * CallPrice(T, K, sig, r, b, S)
          + CallPrice(T, K, sig, r, b, S1)) / (h*h);
}

double Gamma(const OptionData& data, double h)
{
    return Gamma(data.T, data.K, data.sig, data.r, data.b, data.S, h);
}


// Delta for call (exact formula)
double CallDelta(double T, double K, double sig, double r, double b, double S)
{
    double d1 = (log(S/K) + (b + (sig*sig)*0.5) * T) / (sig * sqrt(T));
    
    return exp((b-r)*T) * N(d1);
}

double CallDelta(const OptionData& data)
{
    return CallDelta(data.T, data.K, data.sig, data.r, data.b, data.S);
}

// Delta for call (divided difference approximation)
double CallDelta(double T, double K, double sig, double r, double b, double S, double h)
{
    double S1, S2;
    S1 = S - h;
    S2 = S + h;
    
    return (CallPrice(T, K, sig, r, b, S2) - CallPrice(T, K, sig, r, b, S1)) / (2*h);
}

double CallDelta(const OptionData& data, double h)
{
    return CallDelta(data.T, data.K, data.sig, data.r, data.b, data.S, h);
}


// Delta for put (exact formula)
double PutDelta(double T, double K, double sig, double r, double b, double S)
{
    double d1 = (log(S/K) + (b + (sig*sig)*0.5) * T) / (sig * sqrt(T));
    
    return -exp((b-r)*T) * N(-d1);
}

double PutDelta(const OptionData& data)
{
    return PutDelta(data.T, data.K, data.sig, data.r, data.b, data.S);
}

// Delta for put (divided difference approximation)
double PutDelta(double T, double K, double sig, double r, double b, double S, double h)
{
    double S1, S2;
    S1 = S - h;
    S2 = S + h;
    
    return (PutPrice(T, K, sig, r, b, S2) - PutPrice(T, K, sig, r, b, S1)) / (2*h);
}

double PutDelta(const OptionData& data, double h)
{
    return PutDelta(data.T, data.K, data.sig, data.r, data.b, data.S, h);
}

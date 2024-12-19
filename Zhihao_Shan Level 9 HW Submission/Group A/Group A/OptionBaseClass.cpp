//
//  OptionBaseClass.cpp
//  Group A
//
//  Created by Zhihao Shan on 2023/7/22.
//
//  This file defines basic funcionalities of OptionBaseClass

#ifndef OptionBaseClass_cpp
#define OptionBaseClass_cpp

#include "OptionBaseClass.hpp"
#include "PricingFuncs.hpp"
#include "ArrayFuncs.hpp"
#include <cmath>
#include <string>
using namespace std;

// --------------------------- Initializer, Constructors and destructor ----------------------------- //
void OptionBaseClass::init()
{
    
    data.T   = 30.0;
    data.K   = 100.0;
    data.sig = 0.10;
    data.r   = 0.05;
    data.S = 100.0;
    
    optType = "C";
}

void OptionBaseClass::copy(const OptionBaseClass& o2)
{
    data.T   = o2.data.T;
    data.K   = o2.data.K;
    data.sig = o2.data.sig;
    data.r   = o2.data.r;   
    
    data.S = o2.data.S;
    optType = o2.optType;
}

// Default constructor calling init
OptionBaseClass::OptionBaseClass()
{
    init();
}

// Copy constructor
OptionBaseClass::OptionBaseClass(const OptionBaseClass& o2)
{
    
    copy(o2);
}

// Destructor
OptionBaseClass::~OptionBaseClass()
{
}

// Assignment operator
OptionBaseClass& OptionBaseClass::operator = (const OptionBaseClass& option2)
{
    if (this == &option2)
        return *this;
    
    copy(option2);
    
    return *this;
}


// ---------------------------- Getter and Setter functions ---------------------------- //

// Overloaded Getter and Setter for each parameter
double OptionBaseClass::T() const
{
    return data.T;
}

void OptionBaseClass::T(double newT)
{
    data.T = newT;
}

double OptionBaseClass::K() const
{
    return data.K;
}


void OptionBaseClass::K(double newK)
{
    data.K = newK;
}

double OptionBaseClass::sig() const
{
    return data.sig;
}

void OptionBaseClass::sig(double newsig)
{
    data.sig = newsig;
}

double OptionBaseClass::r() const
{
    return data.r;
}

void OptionBaseClass::r(double newr)
{
    data.r = newr;
}

double OptionBaseClass::b() const
{
    return data.b;
}

void OptionBaseClass::b(double newb)
{
    data.b = newb;
}

double OptionBaseClass::S() const
{
    return data.S;
}


void OptionBaseClass::S(double newS)
{
    data.S = newS;
}

string OptionBaseClass::OptionType() const
{
    return optType;
}

void OptionBaseClass::OptionType(string newoptType)
{
    optType = newoptType;
}

void OptionBaseClass::toggle()
{ // Change option type (C/P, P/C)

    if (optType== "C")
        optType = "P";
    else
        optType = "C";
}

// Getter and Setter for multiple parameters
OptionData OptionBaseClass::GetData() const
{
    return data;
}

void OptionBaseClass::SetData(OptionData newOD)
{
    data = newOD;
}


void OptionBaseClass::SetOption(double newT, double newK, double newsig, double newr, double newb, double newS)
{
    T(newT);
    K(newK);
    sig(newsig);
    r(newr);
    b(newb);
    S(newS);
}



#endif

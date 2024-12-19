//
//  OptionBaseClass.hpp
//  Group A
//
//  Created by Zhihao Shan on 2023/7/22.
//
//  This file is the header file for OptionBaseClass that stores, gets and sets option data

#ifndef OptionBaseClass_hpp
#define OptionBaseClass_hpp

#include <cmath>
#include <string>
#include "OptionData.hpp"
using namespace std;

class OptionBaseClass
{
private:
    OptionData data; // Incapulated data
    string optType; // Option Type, "C" for Call, "P" for Put
    
public:
    // Initializers
    void init(); // Initialization with default values
    void copy(const OptionBaseClass& o2); // Initialization from copying
    
    // Constructors, destructor, and assignment operator
    OptionBaseClass(); // Default constructor
    OptionBaseClass(const OptionBaseClass& option); // Copy constructor
    virtual ~OptionBaseClass(); // Destructor
    OptionBaseClass& operator = (const OptionBaseClass& option); // Assignment operator
    
    // Getter functions for each parameter
    double T() const; // Get T from Optiondata
    double K() const; // Get K from Opitondata
    double sig() const; // Get sig from Optiondata
    double r() const; // Get r from Optiondata
    double b() const; // Get b from Optiondata
    double S() const; // Get S from Optiondata
    string OptionType() const; // Get Option Type
    
    // Setter functions for each parameter
    void T(double newT); // Set T
    void K(double newK); // Set K
    void sig(double newsig); // Set sig
    void r(double newr); // Set r
    void b(double newb); // Set b
    void S(double newS); // Set S
    void OptionType(string newoptType); // Set Option Type
    void toggle(); // Change option type to be the opposite
    
    // Setter and Getter functions for multiple parameters
    OptionData GetData() const; // Get whole data
    void SetData(OptionData newOD); // Set data through passing OptionData
    void SetOption(double newT, double newK, double newsig, double newr, double newb, double newS);// Set all private data of class
    
};
#endif /* OptionBaseClass_hpp */

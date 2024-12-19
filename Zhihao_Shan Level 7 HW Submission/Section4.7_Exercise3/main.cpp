//
//  main.cpp
//  Section4.7_Exercise3
//
//  Created by Zhihao Shan on 2023/7/8.
//
// This program demonstrates use of count_if and Class Smaller than

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include "SmallerThan.hpp"

// Global function to check if a double is smaller than a certain value
bool isSmallerThan(double number, double threshold)
{
    return number < threshold;
}

int main()
{
    // intialize variables
    std::vector<double> numbers;
    double threshold = 1.5;
    int numElements = 10;

    // Append  numbers to the vector
    for (int i = 0; i < numElements; ++i)
    {
        numbers.push_back((i*2+6)%5);
    }
    
    // Use global function to count_if

    // Using count_if with the isSmallerThan function
    int count_with_function = std::count_if(numbers.begin(), numbers.end(), [&](double num) {
        return isSmallerThan(num, threshold);
    });
    
    // Show result
    std::cout << "Using global funciton - Number of elements smaller than " << threshold << ": " << count_with_function << std::endl;

    // Use SmallerThan class to count_if
    
    // Create an instance of the function object
    SmallerThan smallerThan(threshold);

    // Use count_if with the function object
    long count = std::count_if(numbers.begin(), numbers.end(), smallerThan);

    // show result
    std::cout << "Using SmallerThan Class - Number of elements smaller than " << threshold << ": " << count << std::endl;

    return 0;
}

// main.c
// HW1.5_Exercise1
//
// Created by Zhihao Shan on 2023/6/4.
//

#include <stdio.h>

// Function to subtract two numbers
double minus(double n1, double n2)
{
    return n1 - n2;
}

int main()
{
    double a = 15.42; // First number
    double b = 7.39;  // Second number
    
    printf("%f - %f = %f \n", a, b, minus(a, b)); // Call the minus() function and print the result
    
    return 0;
}


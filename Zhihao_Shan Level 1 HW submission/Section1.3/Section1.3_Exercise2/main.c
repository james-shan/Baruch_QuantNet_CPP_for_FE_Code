//
//  main.c
//  HW1.3_Exercise2
//
//  Created by Zhihao Shanon 2023/5/31.
//
// This file contains the implementation of a program that calculates the area of a triangle.

#include <stdio.h>

int main()
{
    double base, height, area;
    
    // Get height from user input
    printf("Please enter the value of height\n");
    scanf("%lf", &height);
    
    // Get base from user input
    printf("Please enter the value of base\n");
    scanf("%lf", &base);
    
    // Calculate area
    area = base * height * 0.5;
    
    // Print the surface of the triangle
    printf("The surface of the triangle is %f\n", area);
    
    return 0;
}


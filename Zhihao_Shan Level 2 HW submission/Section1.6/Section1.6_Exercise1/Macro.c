//
//  main.c
//  HW1.6_Exrecise1
//
//  Created by Zhihao Shan on 2023/6/22.
//
// This program use the funtion defined in Defs.h to print values

#include <stdio.h>
#include "Defs.h"

int main() {
    int a = 10; // Declare and initialize variable 'a' with value 10
    int b = 20; // Declare and initialize variable 'b' with value 20

    PRINT1(a); // Print the value of 'a' using the PRINT1
    PRINT2(a, b); // Print the values of 'a' and 'b' using the PRINT2

    return 0;
}


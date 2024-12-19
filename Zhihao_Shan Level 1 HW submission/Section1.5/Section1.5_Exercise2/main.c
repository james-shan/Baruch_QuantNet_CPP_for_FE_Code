// main.c
// HW1.5_Exercise2
//
// Created by Zhihao Shan on 2023/6/4.
//

#include <stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int n)
{
    switch(n)
    {
        case 0:
            return 1; // Base case: factorial of 0 is 1
        default:
            return n * factorial(n-1); // Recursive case: multiply n with factorial of (n-1)
    }
}

int main()
{
    int n = 6; // Number for which factorial is calculated
    int result = factorial(n); // Call the factorial() function
    printf("factorial of %d is %d\n", n, result); // Print the result
    
    return 0;
}


// main.c
// HW1.5_Exercise4
//
// Created by Zhihao Shan on 2023/6/4.
//

#include <stdio.h>

// Function to print an integer number
int printnumber(int n)
{
    if (n == 0)
    {
        return 0; // Base case: number is zero, return 0
    }
    else if (n < 0)
    {
        putchar('-'); // Print '-' for negative numbers
        printnumber(-n); // Call printnumber() recursively with the absolute value of n
    }
    else
    {
        printnumber(n / 10); // Call printnumber() recursively with the integer division of n by 10
        putchar((n % 10) + '0'); // Print the last digit of n by converting it to character using '0' as offset
    }
    
    return 0;
}

int main()
{
    int n = -3429; // Integer number to be printed
    printnumber(n); // Call the printnumber() function to print the number
    
    return 0;
}


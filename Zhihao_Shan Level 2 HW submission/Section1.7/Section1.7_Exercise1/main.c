//
//  main.c
//  HW1.7_Exercise1
//
//  Created by Zhihao Shanon 2023/6/4.
//
// This program defines a funciton to swap values of variables and demonstrates its usage
#include <stdio.h>

// Function to swap the values of two variables
int Swap(int *i, int *j)
{
    int temp = *i; // Store the value of 'i' in a temporary variable
    *i = *j;      // Assign the value of 'j' to 'i'
    *j = temp;    // Assign the temporary value to 'j'
    
    return 0;
}

int main()
{
    int i = 123; // Declare and initialize variable 'i' with value 123
    int j = 456; // Declare and initialize variable 'j' with value 456
        
    printf("Before swap: i = %d, j = %d\n", i, j);
    
    Swap(&i, &j); // Call the Swap function passing the addresses of 'i' and 'j'
        
    printf("After swap: i = %d, j = %d\n", i, j);
        
    return 0;
}


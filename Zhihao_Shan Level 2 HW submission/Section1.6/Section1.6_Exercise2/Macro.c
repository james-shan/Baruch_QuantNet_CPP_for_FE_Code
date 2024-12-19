//
//  Macro.c
//  HW1.6_Exercise2
//
//  Created by Zhihao Shan on 2023/6/4.
//

// // This file demonstrates how we use MAX2 and MAX3 to find maximum

#include <stdio.h>
#include "Defs.h"

int main() {
    int x = 4; // Declare and initialize variable 'x' with value 4
    int y = 3; // Declare and initialize variable 'y' with value 3
    int z = 5; // Declare and initialize variable 'z' with value 5
    int max2; // Variable to store the maximum of two values
    int max3; // Variable to store the maximum of three values
    
    // Find the maximum of 'x' and 'y' using MAX2
    max2 = MAX2(x, y);
    
    // Find the maximum of 'x', 'y', and 'z' using MAX3
    max3 = MAX3(x, y, z);
    
    // Print the results
    printf("max of x and y is %d and max of all is %d\n", max2, max3);

    return 0;
}

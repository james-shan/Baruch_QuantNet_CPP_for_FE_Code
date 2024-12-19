//
//  main.c
//  HW1.3_Exercise6
//
//  Created by Zhihao Shan on 2023/5/31.
//

#include <stdio.h>

// This program demonstrates the use of arithmetic and logical right shifts on an integer.

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    int lastTwoBits = num & 3; // Get the last two bits of num
    
    int arithShift;
    int logShift;
    
    // Check if the last two bits are 1 1
    if (lastTwoBits == 3) {
        // If the last two bits are 1 1, perform an arithmetic right shift by 2 positions
        arithShift = num >> 2;
        printf("%d (arithmetic shift) \n", arithShift);
    } else {
        // If the last two bits are not 1 1, perform a logical right shift by 2 positions
        logShift = num >> 2;
        printf("%d (logical shift) \n", logShift);
    }
    
    return 0;
}


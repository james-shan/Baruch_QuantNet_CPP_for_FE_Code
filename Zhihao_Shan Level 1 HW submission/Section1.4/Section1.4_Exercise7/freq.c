// main.c
// HW1.4_Exercise7
//
// Created by Zhihao Shan on 2023/6/3.
//

#include <stdio.h>

int main() {
    int count0 = 0; // Counter for the number of '0' characters
    int count1 = 0; // Counter for the number of '1' characters
    int count2 = 0; // Counter for the number of '2' characters
    int count3 = 0; // Counter for the number of '3' characters
    int count4 = 0; // Counter for the number of '4' characters
    int other = 0;  // Counter for any other character
    
    char c = '\0'; // Variable to store the current character
    
    printf("Enter your number:\n");
    
    while (c != EOF) { // Continue the loop until the end of input is reached
        c = getchar(); // Read a character from input
        
        switch(c) {
            case '0':
                count0++; // Increment count0 for '0' character
                break;
            case '1':
                count1++; // Increment count1 for '1' character
                break;
            case '2':
                count2++; // Increment count2 for '2' character
                break;
            case '3':
                count3++; // Increment count3 for '3' character
                break;
            case '4':
                count4++; // Increment count4 for '4' character
                break;
            default:
                if (c != EOF  && c !='\n') {
                    other++; // Increment other for any other character
                }
                break;
        }
    }
    
    // Check and output the counts for each number
    if (count0 < 3) {
        printf("The number zero appears %d time.\n", count0);
    } else {
        printf("The number zero appears more than two times.\n");
    }

    if (count1 < 3) {
        printf("The number one appears %d time.\n", count1);
    } else {
        printf("The number one appears more than two times.\n");
    }

    if (count2 < 3) {
        printf("The number two appears %d time.\n", count2);
    } else {
        printf("The number two appears more than two times.\n");
    }
    
    if (count3 < 3) {
        printf("The number three appears %d time.\n", count3);
    } else {
        printf("The number three appears more than two times.\n");
    }

    if (count4 < 3) {
        printf("The number four appears %d time.\n", count4);
    } else {
        printf("The number four appears more than two times.\n");
    }
    
    printf("Other characters appear %d times.\n", other);
}


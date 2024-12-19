//
//  main.c
//  HW1.9_Exercise1
//
//  Created by Zhihao Shan on 2023/6/7.
//
// This program reads the characters from the keyboard and shows them on screen
#include <stdio.h>

int main()
{
    char c; // define character c
    
    // Display message to ask for user input
    printf("Please enter characters:\n");

    // Loop until the input character is Ctrl+A (ASCII code 1)
    while ((c = getchar()) != 1)
    {
        if (c == '\n')
        {
            putchar('\n'); // If the input is a newline character, print a newline
        }
        else
        {
            putchar(c); // Print the input character
        }
    }

    // Inform the user that Ctrl+A is a correct ending
    printf("\nCTRL + A is a correct ending.\n");

    return 0;
}


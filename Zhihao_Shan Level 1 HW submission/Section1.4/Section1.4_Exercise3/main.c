// main.c
// HW1.4_Exercise3
//
// Created by Zhihao Shan on 2023/6/3.
//

// Do the same task as last exercise but use case instead of if

#include <stdio.h>

int main() {
    int charCount = 0;
    int wordCount = 0;
    int newlineCount = 0;
    
    char prev = '\0'; // Variable to store the previous character
    char c = '\0'; // Variable to store the current character
    
    printf("Please enter: \n");
    
    do {
        c = getchar(); // Read a character from input
        
        switch(c) {
            case ' ':
                if (prev != ' ') {
                    wordCount++; // Increment wordCount if the previous character is not a space
                }
                prev = c; // Update the previous character
                break;
                
            case '\n':
                newlineCount++; // Increment newlineCount
                wordCount++; // Increment wordCount for the newline
                prev = c; // Update the previous character
                break;
                
            default:
                if ((int)c != -1) {
                    charCount++; // Increment charCount for non-space and non-newline characters
                    prev = c; // Update the previous character
                }
                break;
        }
    } while ((int)c != -1); // Continue the loop until the end of input is reached
    
    if (prev != '\n') {
        wordCount++; // Increment wordCount if the last character is not a newline
    }
    
    // Output the results
    printf("Characters: %d\n", charCount);
    printf("Words: %d\n", wordCount);
    printf("Newlines: %d\n", newlineCount);
}


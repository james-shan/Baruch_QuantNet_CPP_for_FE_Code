//
//  main.c
//  HW1.9_Exercise2
//
//  Created by Zhihao Shan on 2023/6/8.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c; // Variable to store the input character
    char filename[50]; // Array to store the filename
    FILE *file; // File pointer

    printf("Enter the filename to write to: ");
    scanf("%s", filename); // Read the filename from the user

    file = fopen(filename, "w"); // Open the file in write mode
    
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1; // Return with an error status if file opening fails
    }

    printf("Please enter characters: \n");

    while ((c = getchar()) != 1)
    {
        if (c == '\n')
        {
            fputc('\n', file); // Write a newline character to the file if input is a newline
        }
        else
        {
            fputc(c, file); // Write the input character to the file
        }
    }

    fclose(file); // Close the file
    printf("\nCTRL + A is a correct ending.\n");
    return 0;
}



//
//  main.c
//  HW1.7_Exercise2
//
//  Created by Zhihao Shan on 2023/6/4.
//
// This program defines Length to return length of input string

#include <stdio.h>
#define MAXLINE 30

// String lenght declaration
int Length(char str[]);

int main()
{
     char string[MAXLINE+1];  // Line of maxium 30 chars + \0
     int c;                   // The input character
     int i=0;                 // The counter
     // Print intro text
     printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
     // Get the characters
     while ((c=getchar())!=EOF && i<MAXLINE)
     {
         string[i++]=(char)c;
     }
     string[i]='\0';          // String must be closed with \0
     printf("String length is %d\n", Length(string));
}

int Length(char str[])
{
    int i = 0; // Initialize a counter variable
    
    while (str[i++] != '\0');// Iterate through the string until a null character '\0' is encountered

    return i - 1; // Subtract 1 to exclude the ending character from the length
}


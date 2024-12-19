//
//  main.c
//  HW1.4_Exercise2
//
//  Created by Zhihao Shan on 2023/6/3.
//

// Do the same task as last exercise but use do..while

#include <stdio.h>

int main() {
    int charCount = 0;
    int wordCount = 0;
    int newlineCount = 0;
    
    char prev = '\0';
    char c = '\0';
    
    printf("Please enter: \n");
    // On Macbook, value of Ctrl+D is -1
    
    do
    {
        c = getchar();
    // Avoid counting consecutive spaces as words
        if (c == ' ')
        {
            if (prev != ' ')
            {
                wordCount++;
            }
            prev = c;
        }
    // Count lines and the last word of the line as a word
        else if (c == '\n')
        {
            newlineCount++;
            wordCount++;
            prev = c;
        }
    // Count charaters and do not include the ending signal
        else if ((int)c != -1)
        {
            charCount++;
            prev = c;
        }
    }
    while ((int)c != -1);
        
    // Count the last word if the input is not ended with a line change
    if (prev != '\n')
    {
        wordCount ++;
    }
    
    
    // Out put the results
    printf("Characters: %d\n", charCount);
    printf("Words: %d\n", wordCount);
    printf("Newlines: %d\n", newlineCount);
}

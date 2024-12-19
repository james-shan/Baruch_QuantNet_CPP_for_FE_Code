//
//  main.c
//  HW1.3_Exercise7
//
//  Created by Zhihao Shan on 2023/5/31.
//

#include <stdio.h>

int main()
{
    int i, n;
    
    // Get i and n integer from user input
    printf("Enter an integer for 'i':\n");
    scanf("%d", &i);
    printf("Enter n for the operation 'i*2^n': \n");
    scanf("%d", &n);
    
    
    // A left shift by n is equivalent to multiplying by 2n
    // Carry out the left shit and print the result
    i = i << n;
    printf("i << n results in i*2^n = %d.\n", i);
    
    return 0;
}


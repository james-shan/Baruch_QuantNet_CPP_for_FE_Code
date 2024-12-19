//
//  main.c
//  HW1.3_Exercise3
//
//  Created by Zhihao Shan on 2023/5/31.
//

/* Operators */
#include <stdio.h>
int main()
{
    
    int x;
    x=-3+4*5-6;
    printf("x=%d\n", x);
    //output is -3+2-6 = 11
    
    x=3+4%5-6;
    printf("x=%d\n", x);
    //output is 3+4-6 = 1
    
    x=-3*4%-6/5;
    printf("x=%d\n", x);
    //output is -12 mod -6 than divide by 5 which is 0
    
    x=(7+6)%5/2;
    printf("x=%d\n", x);
    //output is 13 mod 5 than devide by 2 which is 1
    //note that 3/2 is not float 1.5 but integer 1
    return 0;
    
}


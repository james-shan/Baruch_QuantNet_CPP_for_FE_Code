//
//  main.cpp
//  HW1.3_Assignment8
//
//  Created by Zhihao Shan on 2023/5/31.
//

/* Assignment operators */
#include <stdio.h>
int main()
{
int x=2;
int y; int z;
     x*=3+2;
     printf("x=%d\n", x);
    //output is 2*(3+2) = 10
     x*=y=z=4;
     printf("x=%d\n", x);
    //output is 10*4 = 40
     x=y==z;
     printf("x=%d\n", x);
    //value is boolean True, so output is 1 in integer form.
return 0; }

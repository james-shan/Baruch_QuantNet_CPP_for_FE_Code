//
//  main.cpp
//  HW1.3_Exercise9
//
//  Created by Zhihao Shan on 2023/5/31.
//
/* Conditional expressions */

#include <stdio.h>
int main()
{
int x=1;
     int y=1;
     int z=1;
     x+=y+=x;
    // y+=x -> y = 2
    // x+=y -> x = 3
     printf("%d\n\n", (x<y)?y:x);
    //output is x, which is 3
     printf("%d\n", (x<y)?x++:y++);
    //output is y++, which is 3, y becomes 3 after this line
     printf("%d\n", x);
    //output is 3
     printf("%d\n", y);
    //output is 3
return 0; }

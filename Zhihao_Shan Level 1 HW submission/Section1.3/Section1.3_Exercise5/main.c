//
//  main.c
//  HW1.3_Exercise5
//
//  Created by Zhihao Shan on 2023/5/31.
//

#include <stdio.h>


int main()
{
    int i = 1;
    
    int x;
    
    // Assignment operation: x = i--;
    // Explanation: The value of i is assigned to x, and then i is decremented by 1.
    // Before the assignment, the value of i is 1. After the assignment, x becomes 1 and i becomes 0.
    x = i--;
    printf("Operation is x = i--. Then, x and i become %d, %d \n", x, i); // 1, 0
    
    i = 1;
    
    // Assignment operation: x = --i;
    // Explanation: i is decremented by 1, and then the decremented value of i is assigned to x.
    // Before the assignment, i is decremented from 1 to 0. After the assignment, x becomes 0 and i remains 0.
    x = --i;
    printf("Operation is x = --i. Then, x and i become %d, %d \n", x, i); // 0, 0
    
    return 0;
}

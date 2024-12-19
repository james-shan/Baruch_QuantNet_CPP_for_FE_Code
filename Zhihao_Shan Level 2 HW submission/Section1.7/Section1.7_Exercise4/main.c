//
//  main.c
//  HW1.7_Exercise4
//
//  Created by Zhihao Shan on 2023/6/4.
//
// This program defines a function to print dayname of corresponding day and demonstrates its usage

#include <stdio.h>

int DayName(int i);

int main()
{
    int i = 2;   // Testcase, day 2 is monday
    DayName(i);   // Use DayName to print day
    
    return 0;
}

int DayName(int i)
{
    // An array of strings representing day names
    char* day_name[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    
    // print the corresponding day
    printf("Day %i is %s.\n", i, day_name[i-1]);
    
    return 0;
}

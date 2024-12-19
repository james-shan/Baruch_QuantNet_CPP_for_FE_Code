//
//  main.c
//  HW1.4_Exercise5
//
//  Created by Zhihao Shan on 2023/6/3.
//

#include <stdio.h>
// The program prints a table of Fahrenheit and corresponding Celsius

int main(){
    // set starting and ending temperature
    int start = 0;
    int end = 300;
    
    // initiate Fahreheit and Celsius variable
    int fah;
    float cel;
    
    // print header
    printf("Fahrenheit   Celsius\n");
    
    // loop through required values of Fahreheit
    for (fah=start; fah<=end; fah+=20)
    {
        //calculate celsius and print result
        cel = (fah-32)*5/(float)9;
        printf("%d      %10.1f  \n",fah,cel);
    }
}

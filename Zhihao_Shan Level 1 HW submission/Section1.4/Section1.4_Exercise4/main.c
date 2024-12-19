//
//  main.c
//  HW1.4_Exercise4
//
//  Created by Zhihao Shan on 2023/6/3.
//

#include <stdio.h>

int main(){
    // set starting and ending temperature
    int start = 0;
    int end = 300;
    
    // initiate Fahreheit and Celsius variable
    int fah = start;
    float cel = 0;
    
    // print header
    printf("Fahrenheit   Celsius\n");
    
    // loop through required values of Fahreheit
    while (fah<=end)
    {
        //calculate celsius and print result
        cel = (fah-32)*5/(float)9;
        printf("%d      %10.1f  \n",fah,cel);
        fah += 20;
    }
}

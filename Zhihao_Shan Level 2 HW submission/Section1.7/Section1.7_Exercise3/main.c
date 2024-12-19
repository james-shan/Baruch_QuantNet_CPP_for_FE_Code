//
//  main.c
//  HW1.7_Exercise3
//
//  Created by Zhihao Shan on 2023/6/4.
//

#include <stdio.h>
#define PRD(a) printf("%d", (a))
#define NL printf("\n");

// Create and initialse array
int a[]={0, 1, 2, 3, 4};
int main()
{
int i;
     int* p;
     for (i=0; i<=4; i++) PRD(a[i]);
     //prints element 0 to 4 of array a, which is 01234
     NL;
     for (p=&a[0]; p<=&a[4]; p++) PRD(*p);
     //prints all elements <= the last element of array a, which is 01234
     NL;
     NL;
     for (p=&a[0], i=0; i<=4; i++) PRD(p[i]);
     //prints element 0 to 4 of array a, which is 01234, iterate using pointer
     NL;
     for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i));
     // iterates through the array with stepsize 2, which is 024
     NL;
     NL;
     for (p=a+4; p>=a; p--) PRD(*p);
     // prints from 4 to 0, 43210
     NL;
     for (p=a+4, i=0; i<=4; i++) PRD(p[-i]);
     //prints in reverse order (from 4 to 0), 43210
     NL;
     for (p=a+4; p>=a; p--) PRD(a[p-a]);
     //prints from last element to first of array a, 43210
     NL;
return 0; }

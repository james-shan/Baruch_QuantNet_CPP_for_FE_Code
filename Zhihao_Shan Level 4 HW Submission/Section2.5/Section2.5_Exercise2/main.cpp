//
//  main.cpp
//  HW2.5_Exercise2
//
//  Created by Zhihao Shan on 2023/6/15.
//
//  Creates array on heap with non-default constructors

#include "Point.hpp"
#include <iostream>
using namespace std;

int main()
{
    // Creating an array of Point pointers with 3 elements on the heap
    Point** pp;
    pp = new Point*[3];

    // Creating Point objects for each element in the array
    pp[0] = new Point(1, 2);
    pp[1] = new Point(3, 4);
    pp[2] = new Point(5, 6);

    // Iterating the array and printing each point
    for (int i = 0; i < 3; ++i)
    {
        cout << (*pp[i]).ToString() << endl;
    }

    // Iterating the array and deleting each point
    for (int i = 0; i < 3; ++i)
    {
        delete pp[i];
    }

    // Deleting the array itself
    delete[] pp;

    return 0;
}


/* Drawing of the memory layout:
    
    _________
    |   pp  |   --->  Stack, pointer to pp[0]
    ---------
        |
        V
    _________________________
    | pp[0] | pp[1] | pp[2] |    --->  Stack, pointer to each Point object
    -------------------------
        |       |       |
        V       V       V
    _________________________
    | Point | Point | Point |    --->  Heap
    -------------------------
 
*/

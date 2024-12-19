//
//  main.cpp
//  Section3.4_Exercise1
//
//  Created by Zhihao Shan on 2023/6/24.
//

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"


int main()
{
    Line l;
    
    /*
     Before using colon syntax, default construction and destruction are both called 4 times because start_p and end_p are both initiated by system (1*2 = 2 times) and initiated by calling the point default constructor in the line default constructor (1*2 = 2 times). It is a total of 4 times.
    
     After using colon syntax, destructor and constructor are both called twice because point default constructor is no longer called in the line defualt constructor
     */

    return 0;
}


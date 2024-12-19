//
//  main.cpp
//  Section3.5_Exercise3
//
//  Created by Zhihao Shan on 2023/6/24.
//
//  This file tests the usage of virtual destructors

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"


int main()
{
    // Create shape pointer arr to Shape, Point and Line Object
    Shape* shapes[3];
    shapes[0]=new Shape;
    shapes[1]=new Point;
    shapes[2]=new Line;
    
    // Delete them in sequence and check desctrutor message
    for (int i=0; i!=3; i++)
        delete shapes[i];
    
    /* Before declaring shape destructor as virtual, all three deletes called the Shape destructor once, which is not the right destructors to call.
        
     Correct destructors to call after declaring virtual, which agrees with result:
     1. Shape destructor.
          
     2. Point destructor then Shape destructor.
          
     3. Line destructor,
        (Start Point destructor then Shape destructor,
            End Point destructor then Shape destructor)
        then Shape destructor.
     
     A total of 9 destructors!
     
    */
    
    
}


//
//  main.cpp
//  Section4.2b_Exercise6
//
//  Created by Zhihao Shan on 2023/7/2.
//
//  This file tests the functionality of Stack class

#include <iostream>
#include "StackException.hpp"
#include "Stack.hpp"


int main()
{
    // test Stack of type double
    Stack<double,5> stack1;
    
    // test copy constructor
    Stack<double,5> stack2(stack1);
    
    // test Push()
    for (int i=0; i < 5; i++)
    {
        stack2.Push(i%4+5);
    }
    
    // test assignment constructor
    Stack<double,5> stack3 = stack2;
    // Stack<double,10> stack3 = stack2; will cause an error because size not match!
    
    // test Push() when full
    try
    {
        stack3.Push(5.0);
    }
    catch(StackException& ex)
    {
        cout<< ex.GetMessage() <<endl;
    }
    
    
    // test Pop() when empty
    for (int i=0; i < 8; i++)
    {
        try
        {
            cout << stack3.Pop() << endl;;
        }
        catch(StackException& ex)
        {
            cout << ex.GetMessage() << endl;
        }
    }

    return 0;

    
}



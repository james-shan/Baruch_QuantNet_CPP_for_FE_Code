//
//  ArrayFuncs.hpp
//  GroupB
//
//  Created by Zhihao Shan on 2023/7/18.
//
//  This file defines meshing and printing functions for array
#ifndef ArrayFuncs_hpp
#define ArrayFuncs_hpp

#include <vector>
#include <iomanip> 
#include <iostream>
using namespace std;


template <typename T>
vector<T> MeshArray(T start, T end, T interval)
{ // Generate a mesh array of T separated by a mesh size 'interval'
    
    vector<T> arr;
    
    T temp = start;
    while (temp <= end)
    {
        arr.push_back(temp);
        temp = temp + interval;
    }
    
    return arr;
}




template <typename T>
void PrintArray(const vector<T>& arr)
{ // Print a one dimensional array
    
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
}



template <typename T, typename S>
void PrintArray(const vector<T>& arr1, const vector<S>& arr2)
{ // Print 2 one dimensional arrays with the same size side-by-side
    
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << right << setw(4) << arr1[i] << ", "
        << left <<  setw(12) << arr2[i] << endl;
    }
}



template <typename T, typename S, typename I>
void PrintArray(const vector<T>& arr1, const vector<S>& arr2, const vector<I>& arr3)
{ // Print 3 one dimensional arrays with the same size side-by-side
    
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << right << setw(4) << arr1[i] << ", " << setw(12)
        << arr2[i] << ", " << left << setw(12) << arr3[i] << endl;
    }
}






#endif /* ArrayFuncs_hpp */

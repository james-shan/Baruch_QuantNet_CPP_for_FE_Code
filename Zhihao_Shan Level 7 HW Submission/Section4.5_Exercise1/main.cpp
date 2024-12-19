//
//  main.cpp
//  Section4.5_Exercise1
//
//  Created by Zhihao Shan on 2023/7/6.
//

#include <iostream>
#include <list>
#include <vector>
#include <map>

int main()
{
    // Create a list of doubles
    std::list<double> myList;
    myList.push_back(3.14);
    myList.push_back(6.28);
    myList.push_back(9.42);

    // Access the first and last element using front() and back()
    double firstElement = myList.front();
    double lastElement = myList.back();

    std::cout << "First element: " << firstElement << std::endl;
    std::cout << "Last element: " << lastElement << std::endl;

    // Create a vector of doubles
    std::vector<double> myVector;
    myVector.push_back(2.5);
    myVector.push_back(5.0);
    myVector.push_back(10.0);

    // Access elements using the index operator
    double element1 = myVector[0];
    double element2 = myVector[1];

    std::cout << "Element at index 0: " << element1 << std::endl;
    std::cout << "Element at index 1: " << element2 << std::endl;

    // Make the vector grow
    myVector.push_back(3.0);
    myVector.push_back(6.0);

    // Create a map that maps strings to doubles
    std::map<std::string, double> myMap;
    myMap["apple"] = 0.99;
    myMap["banana"] = 1.99;

    // Access elements using the square bracket operator
    double priceApple = myMap["apple"];
    double priceBanana = myMap["banana"];

    std::cout << "Price of an apple: " << priceApple << std::endl;
    std::cout << "Price of a banana: " << priceBanana << std::endl;

    return 0;
}


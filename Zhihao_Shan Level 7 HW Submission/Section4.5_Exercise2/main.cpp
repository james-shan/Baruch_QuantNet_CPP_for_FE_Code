//
//  main.cpp
//  Section4.5_Exercise2
//
//  Created by Zhihao Shan on 2023/7/6.
//

#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

/*
 In this program, we have two Sum() function templates.
 The first template accepts a container (T) as the input and uses iterators (T::const_iterator) to iterate over the container elements and calculate their sum. We have to specialize it for map because map has two items stored, key and value.
 The second template accepts two iterators (Iterator) representing the begin and end positions of the range, and it calculates the sum between those iterators. We have to specialize it for map because map has two items stored, key and value.
 */


// Sum() for list and vector
template<typename T>
double Sum(const T& container)
{
    double sum = 0.0;
    typename T::const_iterator it;

    // Use iterator to loop and sum
    for (it = container.begin(); it != container.end(); ++it)
    {
        sum += *it;
    }

    return sum;
}


// Specialization for map
template <typename T1, typename T2>
double Sum(const map<T1, T2>& m)
{
    double sum = 0.0;
    typename map<T1, T2>::const_iterator it;

    for (it = m.begin(); it != m.end(); ++it)
    {
        sum += it->second;
    }

    return sum;
}


// Sum() with Range for list and vector
template<typename Iterator>
double Sum(const Iterator& begin, const Iterator& end)
{
    double sum = 0.0;
    
    // Use iterator to loop and sum
    for (Iterator it = begin; it != end; ++it)
    {
        sum += *it;
    }

    return sum;
}

// Specialization for map iterators
template <typename T1, typename T2>
double Sum(const typename map<T1,T2>::const_iterator& begin, const typename map<T1,T2>::const_iterator& end)
{
    double sum = 0; // init sum
    typename map<T1,T2>::const_iterator it;
    for (it = begin; it != end; it++)
    {
        sum += it->second;
    }
    return sum;
};


/*
In the main program, we call the Sum() function for each container (myList, myVector, and myMap) to calculate their sums and display the results.
 */


int main() {
    // Create a list of doubles
    list<double> myList;
    myList.push_back(3.14);
    myList.push_back(6.28);
    myList.push_back(9.42);
    myList.push_back(12.56);

    // Overall Sum
    double sumList = Sum(myList);
    cout << "Sum of the list: " << sumList << endl;
    
    // Sum within specified range
    double sumListRange = Sum(++myList.begin(), --myList.end());
    cout << "Sum of the list without first and last: " << sumListRange << endl;

    // Create a vector of doubles
    vector<double> myVector;
    myVector.push_back(2.5);
    myVector.push_back(5.0);
    myVector.push_back(10.0);
    myVector.push_back(2.5);
    myVector.push_back(5.0);
    myVector.push_back(10.0);

    // Overall Sum
    double sumVector = Sum(myVector);
    cout << "Sum of the vector: " << sumVector << endl;
    
    // Sum within specified range
    double sumVectorRange = Sum(++myVector.begin(), --myVector.end());
    cout << "Sum of the vetor without first and last: " << sumVectorRange << endl;

    // Create a map that maps strings to doubles
    map<string, double> myMap;
    myMap["apple"] = 0.99;
    myMap["banana"] = 1.99;
    myMap["orange"] = 2.99;

    // Overall Sum
    double sumMap = Sum(myMap);
    cout << "Sum of the map: " << sumMap << endl;
    
    // Sum within specified range
    map<string, double>::const_iterator map_begin = ++myMap.begin();
    map<string, double>::const_iterator map_end = --myMap.end();
    double sumMapRange = Sum<string, double>(map_begin, map_end);
    cout << "Sum of the map without first and last: " << sumMapRange << endl;
    
    return 0;
}











//
//  main.cpp
//  Section5.1_Exercise2
//
//  Created by Zhihao Shan on 2023/7/14.
//

#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp>

typedef boost::tuple<std::string, int, double> Person; // Define a typedef for the Person tuple that contains a name, age, and length.

void printPerson(const Person& person)
{
    std::cout << "Name: " << person.get<0>() << std::endl; // Retrieve the name using get<0>() and print it.
    std::cout << "Age: " << person.get<1>() << std::endl; // Retrieve the age using get<1>() and print it.
    std::cout << "Length: " << person.get<2>() << std::endl; // Retrieve the length using get<2>() and print it.
}

int main()
{
    Person person1("Alice", 25, 1.65); // Initialize person1 with name "Alice", age 25, and length 1.65.
    Person person2("Bob", 30, 1.8); // Initialize person2 with name "Bob", age 30, and length 1.8.
    
    
    // Print info of person1 and person2
    printPerson(person1);
    std::cout << std::endl;
    printPerson(person2);
    std::cout << std::endl;

    person1.get<1>() += 1; // Increment the age of person1 by accessing it with get<1>().

    // Print info or person1 after incrementing age
    std::cout << "After incrementing age:" << std::endl;
    printPerson(person1);

    return 0;
}


// Circle.hpp
// HW2.5_Exercise1
//
// Created by Zhihao Shan on 2023/6/16.
//

#include <iostream>
#include "Point.hpp" // Include the Point header file for Point class
#include <string>

#ifndef Circle_hpp
#define Circle_hpp

using namespace std;
using namespace ZHIHAO::CAD;

namespace ZHIHAO
{
    namespace CAD
    {
        class Circle
        {
        private:
            Point m_cp; // Center point of the circle
            double m_radius; // Radius of the circle

        public:
            // Constructor and destructors
            Circle(); // Default constructor
            Circle(const Point& cp, const double& radius); // Constructor with center point and radius parameters
            Circle(const Circle& other); // Copy constructor
            ~Circle(); // Destructor

            // Overloaded getters and setters
            Point CenterPoint() const; // Get the center point of the circle
            void CenterPoint(const Point& cp); // Set the center point of the circle
            double Radius() const; // Get the radius of the circle
            void Radius(const double& radius); // Set the radius of the circle

            // Other functions
            double Diameter() const; // Calculate the diameter of the circle
            double Area() const; // Calculate the area of the circle
            double Circumference() const; // Calculate the circumference of the circle
            string ToString() const; // Convert the circle to a string representation

            // Assignment Operator
            Circle& operator=(const Circle& source);

        };

        // Ostream << operator
        ostream& operator<<(ostream& os, const Circle& c);
    }

}
#endif


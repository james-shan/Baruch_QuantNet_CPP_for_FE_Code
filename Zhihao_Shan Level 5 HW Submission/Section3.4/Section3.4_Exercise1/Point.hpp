//
//  Point.hpp
//  Section3.4_Exercise1
//
//  Created by Zhihao Shan on 2023/6/16.
//

#include <string>
#ifndef Point_hpp
#define Point_hpp
using namespace std;

// include class Point to ZHIHAO::CAD
namespace ZHIHAO
{
    namespace CAD{

        class Point
        {
        // set private variables
        private:
            double m_x;
            double m_y;
        public:
            // Constructors
            Point(); // Default constructor
            Point(double x, double y); // Constructor with user input
            ~Point(); // Destructor
            Point(const Point& other); // Copy constructor
            
            // set and get x
            double X() const;
            void X(double newX);
            
            // set and get y
            double Y() const;
            void Y(double newY);
            
            //To string function
            string ToString() const;
            
            //Distance functions
            double Distance() const;
            double Distance(const Point& pt) const;
            
            
            // Operators
            Point operator - () const; // Negate the coordinates.
            Point operator * (double factor) const; // Scale the coordinates.
            Point operator + (const Point& p) const; // Add coordinates.
            bool operator == (const Point& p) const; // Equally compare operator.
            Point& operator = (const Point& source); // Assignment operator.
            Point& operator *= (double factor); // Scale the coordinates & assign.
            
            // global friend operator
            friend ostream& operator << (ostream& os, const Point& p);
        };
    }

}
// Ostream << operator

#endif /* Point_hpp */

//
//  Point.hpp
//  HW2.3_Exercise2
//
//  Created by Zhihao Shan on 2023/6/10.
//
// This file is the header file for Point Class

#include <string>
#ifndef Point_hpp
#define Point_hpp

using namespace std;

class Point
{
private:
    double m_x;
    double m_y;
public:
    // Constructors
    Point(); // Default constructor
    Point(double x, double y); // Constructor with user input
    ~Point(); // Destructor
    Point(const Point& other); // Copy constructor

    // Getter functions
    double getX() const;
    double getY() const;
    
    //Setter functions
    void setX(double newX);
    void setY(double newY);
    
    //To string function
    string ToString() const;
    
    //Distance functions
    double DistanceOrigin() const;
    double Distance(const Point& pt) const;
};

#endif /* Point_hpp */

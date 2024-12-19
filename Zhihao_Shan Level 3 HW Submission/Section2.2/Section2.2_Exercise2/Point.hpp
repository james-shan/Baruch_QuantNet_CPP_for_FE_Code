//
//  Point.hpp
//  HW2.2_Exercise2
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
    ~Point(); // Destructor

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
    double Distance(Point pt) const;
};

#endif /* Point_hpp */

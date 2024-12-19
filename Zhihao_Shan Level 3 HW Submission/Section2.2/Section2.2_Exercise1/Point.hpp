//
//  Point.hpp
//  HW2.2_Exercise1
//
//  Created by Zhihao Shan on 2023/6/10.
//
//  This is the header file for Point class

#include <string>
#ifndef Point_hpp
#define Point_hpp

using namespace std;

class Point
{
private:
    // coordinate stored in m_x and m_y
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
};

#endif /* Point_hpp */

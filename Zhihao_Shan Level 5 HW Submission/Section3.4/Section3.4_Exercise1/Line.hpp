//
//  Line.hpp
//  Section3.4_Exercise1
//
//  Created by Zhihao Shan on 2023/6/16.
//
#include <iostream>
#include "Point.hpp"
#include <string>

#ifndef Line_hpp
#define Line_hpp
using namespace std;
using namespace ZHIHAO::CAD;

namespace ZHIHAO
{
    namespace CAD
    {
        class Line
        {
        private:
            Point start_p;
            Point end_p;
            
        public:
            // Constructor and destructors
            Line();
            Line(const Point& new_start_p, const Point& new_end_p);
            Line(const Line& other);
            ~Line();
            
            // Overloaded getters and setters
            Point StartPoint() const;
            void StartPoint(const Point& newstart);
            Point EndPoint() const;
            void EndPoint(const Point& newend);
            
            // Other funtions
            string ToString() const;
            double Length() const;
            
            // Assignment Operator
            Line& operator = (const Line& source);
            
        };

        // Ostream << operator
        ostream& operator << (ostream& os, const Line& l);
    }
}
#endif /* Line_hpp */

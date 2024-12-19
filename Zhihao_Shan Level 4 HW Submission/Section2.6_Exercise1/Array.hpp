//
//  Array.hpp
//  HW2.6_Exercise1
//
//  Created by Zhihao Shan on 2023/6/16.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>
using namespace ZHIHAO::CAD;

namespace ZHIHAO
{
    namespace Containers
    {
        class Array
        {
        private:
            // store array size
            int m_size;
            
            // dynamic C array of Point objects
            Point* m_data;
            
        public:
            // Constructors and Destructor
            Array(); // default constructor
            Array(int size); // constructor with size argument
            Array(const Array& source); // copy constructor
            
            // Destructor
            ~Array();
            
            // Assignment operator
            Array& operator = (const Array& arr);
            
            // Member functions
            int Size() const; // get array size
            const Point& GetElement(int index) const; // Get element at given index
            void SetElement(int index, const Point& point); // Set element at given index
            Point& operator [] (int index); // Square bracket operator
            const Point& operator[] (int index) const; // Const Square bracket operator
            
        };
    
    }

}
#endif /* Array_hpp */

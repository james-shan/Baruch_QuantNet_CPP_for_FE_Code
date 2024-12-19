//
//  Array.cpp
//  HW2.6_Exercise1
//
//  Created by Zhihao Shan on 2023/6/16.
//

#include "Point.hpp"
#include "Array.hpp"
#include <iostream>
using namespace ZHIHAO::CAD;
using namespace ZHIHAO::Containers;

namespace ZHIHAO
{
    namespace Containers
    {
        // default constructor
        Array::Array()
        {
            // default size set to 10 and create dynamic memory for Point
            m_size = 10;
            m_data = new Point[m_size];
            
            std::cout<< "Array created by default"<<std::endl;
        }

        // constructor with size argument
        Array::Array(int size)
        {
            // set size to given int and create dynamic memory for Point
            m_size = size;
            m_data = new Point[m_size];
            
            std::cout<< "Array created with input size"<<std::endl;
        }

        // copy constructor
        Array::Array(const Array& source)
        {
            // set size to source size and create dynamic memory for Point
            m_size = source.m_size;
            m_data = new Point[m_size];
            
            // iterate through the source using index and copy the points
            for (int i = 0; i < m_size; i++)
                m_data[i] = source.m_data[i];
            
            std::cout<< "Array created by copy"<<std::endl;
        }

        // Destructor
        Array::~Array()
        {
            // delete internal C array
            delete [] m_data;
            
            std::cout<< "Array destructed"<<std::endl;
        }


        // Assignment operator
        Array& Array::operator = (const Array& source)
        {
            // avoid assigning to itself
            if (this == &source)
                return *this;
            
            // delete current data and initialize
            delete [] m_data;
            m_size = source.m_size;
            m_data = new Point[m_size];
            
            // use iteration to assign new data
            for (int i = 0; i < m_size; i++)
                m_data[i] = source.m_data[i];
            
            return *this;
        }

        // Member functions
        int Array::Size() const // get array size
        {
            return m_size;
        }

        const Point& Array::GetElement(int index) const // Get element at given index
        {
            // normal return
            if (index >= 0 && index < m_size)
            {
                return m_data[index];
            }
            // return first object if index out of range
            else
            {
                return m_data[0];
            }
        }

        void Array::SetElement(int index, const Point& point) // Set element at given index
        {
            // ignore the set and print error if index out of range
            if (index < 0 || index >= m_size)
            {
                std::cout<<"Index out of range!"<<std::endl;
            }
            // set element if index is legit
            else
            {
                m_data[index] = point;
            }
        }

        // Square bracket operator
        Point& Array::operator [] (int index)
        {
            // normal return
            if (index >= 0 && index < m_size)
            {
                return m_data[index];
            }
            // return first object if index out of range
            else
            {
                return m_data[0];
            }
        }

        // Const Square bracket operator
        const Point& Array::operator[](int index) const
        {
            // function content is same as above
            if (index >= 0 && index < m_size) {
                return m_data[index];
            } else {
                return m_data[0];
            }
        }
    }
}

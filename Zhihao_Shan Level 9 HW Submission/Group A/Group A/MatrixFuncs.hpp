//
//  MatrixFuncs.hpp
//  Group A
//
//  Created by Zhihao Shan on 2023/7/23.
//
//  This file defines printing function for matrix

#ifndef MatrixFuncs_hpp
#define MatrixFuncs_hpp

#include <vector>
#include <iomanip>   // setw
#include <iostream>
using namespace std;

void PrintMatrix(const vector<vector<double>>& matrix)
{
    if (matrix.empty()) {
        cout << "Matrix is empty." << endl;
        return;
    }

    // Find the size of the largest row in the matrix
    size_t maxRowSize = 0;
    for (const auto& row : matrix) {
        if (row.size() > maxRowSize) {
            maxRowSize = row.size();
        }
    }

    // Determine the maximum width needed for the numbers
    size_t maxNumberWidth = 1; // At least 1 character for each number (to handle negatives)
    for (const auto& row : matrix) {
        for (const auto& num : row) {
            size_t currentWidth = to_string(num).size();
            if (currentWidth > maxNumberWidth) {
                maxNumberWidth = currentWidth;
            }
        }
    }

    // Print each row of the matrix as a column with equal-length numbers
    for (size_t i = 0; i < maxRowSize; ++i) {
        for (const auto& row : matrix) {
            if (i < row.size()) {
                cout << setw(maxNumberWidth) << row[i] << "\t"; // Use setw() to set width
            } else {
                cout << setw(maxNumberWidth) << "" << "\t"; // Empty space if row is smaller than maxRowSize
            }
        }
        cout << endl; // Move to the next line after each column
    }
}
#endif /* MatrixFuncs_hpp */

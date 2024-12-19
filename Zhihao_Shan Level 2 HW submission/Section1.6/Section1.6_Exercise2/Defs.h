//
//  Defs.h
//  HW1.6_Exercise2
//
//  Created by Zhihao Shan on 2023/6/4.
//
// This file defines MAX2 and MAX3 to find maximum

#ifndef Defs_h
#define Defs_h

// Function to find the maximum of two values
#define MAX2(x, y) ((x) > (y) ? (x) : (y))

// Function to find the maximum of three values
#define MAX3(x, y, z) MAX2(MAX2(x, y), z)

#endif // Defs_h

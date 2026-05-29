//
// Created by Swarup on 2026-05-29.
//

#ifndef EPSILON_H
#define EPSILON_H
#include <stdint.h>

typedef struct {
    uint16_t sign: 1;
    uint16_t exponent: 5;
    uint16_t mantissa: 10;
} float16_t;

typedef struct {
    uint32_t sign: 1;
    uint32_t exponent: 8;
    uint32_t mantissa: 23;
} float32_t;

typedef struct {
    uint64_t sign : 1;
    uint64_t exponent : 11;
    uint64_t mantissa : 52;
} float64_t;

// Function to convert a float to float16_t
float16_t floatToFloat16(float num);

// Function to convert a float to float32_t (normal IEEE 754 single precision)
float32_t floatToFloat32(float num);

// Function to convert a float to float64_t
float64_t floatToFloat64(float num);
// Function to convert float16_t back to float
float float16ToFloat(float16_t f);

// Function to convert float32_t back to float
float float32ToFloat(float32_t f);

// Function to convert float64_t back to float
float float64ToFloat(float64_t f);

// Function to print the components of the float types
void printFloat16(float16_t f);

void printFloat32(float32_t f);

void printFloat64(float64_t f);

#endif //EPSILON_H

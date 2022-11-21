// Created by Andrii Sulimenko on 18.11.2022.

#pragma once
// Power function
double power(double x, unsigned int n, unsigned int &calls);
// Fibonacci counter
double fibonacci (unsigned int n, unsigned int& calls);
// Matrix structure
struct Matrix2x2
{
    int _11, _12, _21, _22;
};
// Vector structure
struct Vector2
{
    int _1, _2;
};
// Count Fibonacci sequence
/*
 * Matrix Fibonacci makes less recursive calls for values greater than 5
 * in comparison to the first function where it makes 11 calls for counting Fibonacci (12)
 * when matrix Fibonacci makes only 5 recursive calls
 */
int matrixFibonacci(int n, unsigned int& calls);
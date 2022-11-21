// Created by Andrii Sulimenko on 18.11.2022.

#include "func.h"

// Additional function
void zet(double &y, double &x, unsigned int &k, unsigned int& calls)
{
    if (k>0)
    {
        if (k%2==1)
        {
            y*=x; k--;
        }
        else
        {
            x*=x; k/=2;
        }
        ++calls;
        zet(y,x,k,calls);
    }
}

// Power function
double power(double x, unsigned int n, unsigned int& steps)
{
    double y = 1;
    zet(y, x, n, steps);
    return y;
}

// Additional Fibonacci function
void fib(double &f1, double &f2, unsigned int n, unsigned int& calls)
{
    if (n>=2)
    {
        double f =f2; f2+=f1; f1=f;
        ++calls;
        fib(f1, f2, n-1, calls);
    }
}

// Fibonacci counter
double fibonacci (unsigned int n, unsigned int& calls)
{
    double f0=0, f1=1;
    switch ( n )
    {
        case 0:
            return f0;
        case 1:
            return f1;
        default:
            fib(f0, f1, n, calls);
            return f1;
    }
}

// Multiplication of two matrix
Matrix2x2 multiplicated(Matrix2x2 m1, Matrix2x2 m2)
{
    return { m1._11 * m2._11 + m1._12 * m2._21,
             m1._11 * m2._12 + m1._12 * m2._22,
             m1._21 * m2._11 + m1._22 * m2._21,
             m1._21 * m2._12 + m1._22 * m2._22 };
}

// Additional function for counting matrix in power p
Matrix2x2 matrixToPowerRec(Matrix2x2& result, Matrix2x2 m, int p, unsigned int& calls)
{
    if (p > 0)
    {
        // If power value is a multiple of 2
        if (p % 2 == 0)
        {
            m = multiplicated(m, m);
            p /= 2;
        }
        // If power value is odd
        else
        {
            result = multiplicated(result, m);
            p--;
        }
        ++calls;
        matrixToPowerRec(result, m, p, calls);
    }
    return result;
}

// Matrix in power p
Matrix2x2 matrixToPower(Matrix2x2 m, int p, unsigned int& calls)
{
    Matrix2x2 result = {1, 0, 0, 1 };
    return matrixToPowerRec(result, m, p, calls);
}

// Matrix to vector
Vector2 xVect(Matrix2x2 m, Vector2 v)
{
    return {m._11 * v._1 + m._12 * v._2,
            m._21 * v._1 + m._22 * v._2};
}

// Fibonacci sequence
/*
 * Matrix Fibonacci makes less recursive calls for values greater than 5
 * in comparison to the first function where it makes 11 calls for counting Fibonacci (12)
 * when matrix Fibonacci makes only 5 recursive calls
 */
int matrixFibonacci(int n, unsigned int& calls)
{
    if (n == 0 || n == 1) return n;

    Matrix2x2 m = { 1, 1, 1, 0 };

    Vector2 v = { 0, 1 };
    v = xVect(matrixToPower(m, n, calls), v);

    // Return the first value of the first row
    return v._1;
}

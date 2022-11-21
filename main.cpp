#include <iostream>
#include "func.h"

using namespace std;

int main() {
    unsigned int recursiveCalls;
    int n;
    double x;

    cout.precision(10);

    // Initialize random seed:
    srand (time(nullptr));

    cout << "Power function:\n" << endl;

    for (double i = 0; i < 10; i += 0.5)
    {
        recursiveCalls = 0;
        x = i;
        n = rand() % 10;

        cout << ((int) (i * 2) + 1) << ". " << x << '^' << n <<  " = " << power(x, n, recursiveCalls) << "\n  • (recursive calls: " << recursiveCalls << ')' << endl;
    }

    cout << "\nFibonacci function:\n" << endl;

    for (int i = 0; i < 13; i++)
    {
        recursiveCalls = 0;
        cout << "Fibonacci for (" <<  i << ") is " << fibonacci(i, recursiveCalls) << "\n  • (recursive calls: " << recursiveCalls << ')' << endl;

        recursiveCalls = 0;
        cout << "Quick Fibonacci for (" <<  i << ") is " << matrixFibonacci(i, recursiveCalls) << "\n  • (recursive calls: " << recursiveCalls << ")\n" << endl;
    }
    return 0;
}

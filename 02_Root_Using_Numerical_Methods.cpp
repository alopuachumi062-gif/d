// QUESTION 2: ROOT USING NEWTON-RAPHSON, SECANT AND FIXED-POINT METHODS

#include <iostream>
#include <cmath>
using namespace std;

double newton(double n)
{
    double x = n, y;

    do
    {
        y = (x + n / x) / 2;

        if (abs(y - x) < 0.00001)
            break;

        x = y;
    } while (true);

    return y;
}

double secant(double n)
{
    double x0 = 0.0;
    double x1 = (n > 1.0) ? n : 1.0;
    double x2;

    for (int i = 0; i < 1000; i++)
    {
        double f0 = x0 * x0 - n;
        double f1 = x1 * x1 - n;
        double denominator = f1 - f0;

        if (abs(denominator) < 1e-12)
            return x1;

        x2 = x1 - f1 * (x1 - x0) / denominator;

        if (abs(x2 - x1) < 0.00001)
            return x2;

        x0 = x1;
        x1 = x2;
    }

    return x1;
}

double fixedPoint(double n)
{
    double x = n, y;

    do
    {
        y = (x + n / x) / 2;

        if (abs(y - x) < 0.00001)
            break;

        x = y;
    } while (true);

    return y;
}

int main()
{
    int choice;
    double n;

    cout << "Enter a positive number: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Enter a number greater than zero.";
        return 0;
    }

    cout << "\n1. Newton Raphson Method";
    cout << "\n2. Secant Method";
    cout << "\n3. Fixed Point Iteration";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "Root = " << newton(n);
            break;

        case 2:
            cout << "Root = " << secant(n);
            break;

        case 3:
            cout << "Root = " << fixedPoint(n);
            break;

        default:
            cout << "Invalid choice";
    }

    return 0;
}

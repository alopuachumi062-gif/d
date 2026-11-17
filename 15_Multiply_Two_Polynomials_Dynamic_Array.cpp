// Question 15: Multiply two polynomials using dynamic arrays and constructors.
#include <iostream>
using namespace std;

class Polynomial {
private:
    int* coeff;
    int degree;

public:
    explicit Polynomial(int d) : coeff(nullptr), degree(d >= 0 ? d : 0) {
        coeff = new int[degree + 1]{};
        cout << "Enter coefficients from constant term to highest power:\n";
        for (int i = 0; i <= degree; ++i) {
            cout << "Coefficient of x^" << i << ": ";
            cin >> coeff[i];
        }
    }

    Polynomial(const Polynomial& other)
        : coeff(new int[other.degree + 1]), degree(other.degree) {
        for (int i = 0; i <= degree; ++i) coeff[i] = other.coeff[i];
    }

    Polynomial(int d, const int values[])
        : coeff(new int[d + 1]), degree(d) {
        for (int i = 0; i <= degree; ++i) coeff[i] = values[i];
    }

    void display() const {
        bool printed = false;
        for (int i = degree; i >= 0; --i) {
            if (coeff[i] == 0) continue;
            if (printed && coeff[i] > 0) cout << " + ";
            else if (printed && coeff[i] < 0) cout << " - ";
            else if (!printed && coeff[i] < 0) cout << "-";

            int value = coeff[i] < 0 ? -coeff[i] : coeff[i];
            if (i == 0 || value != 1) cout << value;
            if (i > 0) {
                cout << "x";
                if (i > 1) cout << "^" << i;
            }
            printed = true;
        }
        if (!printed) cout << "0";
        cout << endl;
    }

    Polynomial multiply(const Polynomial& other) const {
        int resultDegree = degree + other.degree;
        int* values = new int[resultDegree + 1]{};

        for (int i = 0; i <= degree; ++i)
            for (int j = 0; j <= other.degree; ++j)
                values[i + j] += coeff[i] * other.coeff[j];

        Polynomial result(resultDegree, values);
        delete[] values;
        return result;
    }

    ~Polynomial() {
        delete[] coeff;
    }
};

int main() {
    int d1, d2;
    cout << "Enter degree of first polynomial: ";
    cin >> d1;
    if (!cin || d1 < 0) return 1;
    Polynomial p1(d1);

    cout << "Enter degree of second polynomial: ";
    cin >> d2;
    if (!cin || d2 < 0) return 1;
    Polynomial p2(d2);

    Polynomial product = p1.multiply(p2);
    cout << "First polynomial: ";
    p1.display();
    cout << "Second polynomial: ";
    p2.display();
    cout << "Product: ";
    product.display();
    return 0;
}

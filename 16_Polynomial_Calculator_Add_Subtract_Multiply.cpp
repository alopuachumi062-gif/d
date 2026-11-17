// Question 16: Polynomial calculator using dynamic memory, copy and move constructors.
#include <iostream>
#include <utility>
using namespace std;

class Polynomial {
private:
    int* coeff;
    int degree;

    void allocateAndZero(int d) {
        degree = d;
        coeff = new int[degree + 1]{};
    }

public:
    explicit Polynomial(int d) {
        allocateAndZero(d >= 0 ? d : 0);
        cout << "Enter coefficients from constant term to highest power:\n";
        for (int i = 0; i <= degree; ++i) {
            cout << "Coefficient of x^" << i << ": ";
            cin >> coeff[i];
        }
    }

    Polynomial(const Polynomial& other) {
        allocateAndZero(other.degree);
        for (int i = 0; i <= degree; ++i) coeff[i] = other.coeff[i];
    }

    Polynomial(Polynomial&& other) noexcept
        : coeff(other.coeff), degree(other.degree) {
        other.coeff = nullptr;
        other.degree = 0;
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            int* newData = new int[other.degree + 1];
            for (int i = 0; i <= other.degree; ++i)
                newData[i] = other.coeff[i];
            delete[] coeff;
            coeff = newData;
            degree = other.degree;
        }
        return *this;
    }

    Polynomial& operator=(Polynomial&& other) noexcept {
        if (this != &other) {
            delete[] coeff;
            coeff = other.coeff;
            degree = other.degree;
            other.coeff = nullptr;
            other.degree = 0;
        }
        return *this;
    }

    Polynomial add(const Polynomial& other) const {
        int d = degree > other.degree ? degree : other.degree;
        Polynomial result(d, true);
        for (int i = 0; i <= d; ++i) {
            int a = (i <= degree) ? coeff[i] : 0;
            int b = (i <= other.degree) ? other.coeff[i] : 0;
            result.coeff[i] = a + b;
        }
        return result;
    }

    Polynomial subtract(const Polynomial& other) const {
        int d = degree > other.degree ? degree : other.degree;
        Polynomial result(d, true);
        for (int i = 0; i <= d; ++i) {
            int a = (i <= degree) ? coeff[i] : 0;
            int b = (i <= other.degree) ? other.coeff[i] : 0;
            result.coeff[i] = a - b;
        }
        return result;
    }

    Polynomial multiply(const Polynomial& other) const {
        Polynomial result(degree + other.degree, true);
        for (int i = 0; i <= degree; ++i)
            for (int j = 0; j <= other.degree; ++j)
                result.coeff[i + j] += coeff[i] * other.coeff[j];
        return result;
    }

    void display() const {
        bool printed = false;
        for (int i = degree; i >= 0; --i) {
            int c = coeff[i];
            if (c == 0) continue;
            if (printed) cout << (c > 0 ? " + " : " - ");
            else if (c < 0) cout << "-";
            int value = c < 0 ? -c : c;
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

    ~Polynomial() {
        delete[] coeff;
    }

private:
    Polynomial(int d, bool) {
        allocateAndZero(d >= 0 ? d : 0);
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

    Polynomial sum = p1.add(p2);
    Polynomial difference = p1.subtract(p2);
    Polynomial product = p1.multiply(p2);

    cout << "P(x) = ";
    p1.display();
    cout << "Q(x) = ";
    p2.display();
    cout << "P(x) + Q(x) = ";
    sum.display();
    cout << "P(x) - Q(x) = ";
    difference.display();
    cout << "P(x) * Q(x) = ";
    product.display();
    return 0;
}

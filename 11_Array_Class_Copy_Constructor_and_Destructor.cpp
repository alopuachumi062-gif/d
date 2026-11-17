// Question 11: Create an Array class with dynamic memory, copy constructor and Display().
#include <iostream>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    Array(int n) : data(nullptr), size(n) {
        if (size < 0) size = 0;
        data = (size > 0) ? new int[size]{} : nullptr;

        for (int i = 0; i < size; ++i) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> data[i];
        }
    }

    Array(const Array& other) : data(nullptr), size(other.size) {
        data = (size > 0) ? new int[size] : nullptr;
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }

    void display() const {
        cout << "Array elements: ";
        for (int i = 0; i < size; ++i) cout << data[i] << " ";
        cout << endl;
    }

    ~Array() {
        delete[] data;
    }
};

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    if (!cin || n < 0) {
        cout << "Invalid size." << endl;
        return 1;
    }

    Array original(n);
    cout << "Original ";
    original.display();

    Array copied(original);
    cout << "Copied ";
    copied.display();

    return 0;
}

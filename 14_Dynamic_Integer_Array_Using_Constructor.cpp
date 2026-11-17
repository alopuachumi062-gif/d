// Question 14: Create a dynamic integer array using a constructor.
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    explicit DynamicArray(int n) : data(nullptr), size(n > 0 ? n : 0) {
        data = (size > 0) ? new int[size] : nullptr;

        for (int i = 0; i < size; ++i) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> data[i];
        }
    }

    void display() const {
        cout << "Array elements: ";
        for (int i = 0; i < size; ++i) cout << data[i] << " ";
        cout << endl;
    }

    ~DynamicArray() {
        delete[] data;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (!cin || n < 0) {
        cout << "Invalid size." << endl;
        return 1;
    }

    DynamicArray arr(n);
    arr.display();
    return 0;
}

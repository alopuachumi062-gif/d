// Question 12: Implement constructor, copy constructor, move constructor and destructor for Buffer.
#include <iostream>
#include <utility>
using namespace std;

class Buffer {
private:
    int* data;
    int size;

public:
    explicit Buffer(int n) : data(nullptr), size(n > 0 ? n : 0) {
        data = (size > 0) ? new int[size]{} : nullptr;
        for (int i = 0; i < size; ++i) data[i] = i + 1;
    }

    Buffer(const Buffer& other) : data(nullptr), size(other.size) {
        data = (size > 0) ? new int[size] : nullptr;
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
        cout << "Copy constructor called" << endl;
    }

    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "Move constructor called" << endl;
    }

    void display() const {
        cout << "Buffer: ";
        for (int i = 0; i < size; ++i) cout << data[i] << " ";
        cout << endl;
    }

    ~Buffer() {
        delete[] data;
    }
};

int main() {
    Buffer first(5);
    first.display();

    Buffer copied(first);
    copied.display();

    Buffer moved(std::move(first));
    moved.display();

    cout << "Original after move ";
    first.display();
    return 0;
}

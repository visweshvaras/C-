// DIY 6.3: Safe Array with Bounds Checking via operator[]
// Lab Manual Page 22: A class wrapping a dynamic array; overload operator[] to throw / report an error on out-of-range access instead of corrupting memory.
#include <iostream>
#include <stdexcept>

using namespace std;

class SafeArray {
private:
    int *arr;
    int size;

public:
    SafeArray(int s) : size(s) {
        if (size <= 0) size = 1;
        arr = new int[size]();
    }

    ~SafeArray() {
        delete[] arr;
    }

    int getSize() const { return size; }

    // Overloaded subscript operator with bounds checking
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index " + to_string(index) + 
                               " out of valid bounds [0, " + 
                               to_string(size - 1) + "]");
        }
        return arr[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index " + to_string(index) + 
                               " out of valid bounds [0, " + 
                               to_string(size - 1) + "]");
        }
        return arr[index];
    }
};

int main() {
    cout << "=== DIY 6.3: Safe Array Bounds Checking Overload ===" << endl;

    SafeArray safe(5);
    for (int i = 0; i < safe.getSize(); ++i) {
        safe[i] = (i + 1) * 10;
    }

    cout << "SafeArray contents: ";
    for (int i = 0; i < safe.getSize(); ++i) {
        cout << safe[i] << " ";
    }
    cout << endl;

    cout << "\nAttempting out-of-range accesses:" << endl;
    try {
        cout << "Accessing index 10: ";
        cout << safe[10] << endl;
    } catch (const out_of_range &e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    try {
        cout << "Accessing negative index -1: ";
        cout << safe[-1] << endl;
    } catch (const out_of_range &e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    return 0;
}

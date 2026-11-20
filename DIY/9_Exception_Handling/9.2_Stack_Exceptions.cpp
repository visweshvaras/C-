// DIY 9.2: Stack Overflow and Underflow Custom Exceptions
// Lab Manual Page 31: Give your Week-4 Stack custom Overflow and Underflow exceptions and handle them in main.
#include <iostream>
#include <stdexcept>

using namespace std;

class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException: Push failed, stack has reached maximum capacity!";
    }
};

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException: Pop failed, stack is currently empty!";
    }
};

class RobustStack {
private:
    int *arr;
    int capacity;
    int topIdx;

public:
    RobustStack(int cap) : capacity(cap), topIdx(-1) {
        arr = new int[capacity];
    }

    ~RobustStack() {
        delete[] arr;
    }

    void push(int val) {
        if (topIdx == capacity - 1) {
            throw StackOverflowException();
        }
        arr[++topIdx] = val;
        cout << "Pushed " << val << endl;
    }

    int pop() {
        if (topIdx == -1) {
            throw StackUnderflowException();
        }
        return arr[topIdx--];
    }
};

int main() {
    cout << "=== DIY 9.2: Stack Overflow & Underflow Custom Exceptions ===" << endl;

    RobustStack st(2);

    // Test Stack Overflow
    try {
        cout << "\nTesting Push and Overflow:" << endl;
        st.push(10);
        st.push(20);
        cout << "Attempting 3rd push onto capacity-2 stack..." << endl;
        st.push(30); // Must throw
    } catch (const StackOverflowException &e) {
        cout << "Caught: " << e.what() << endl;
    }

    // Test Stack Underflow
    try {
        cout << "\nTesting Pop and Underflow:" << endl;
        cout << "Popped: " << st.pop() << endl;
        cout << "Popped: " << st.pop() << endl;
        cout << "Attempting 3rd pop from empty stack..." << endl;
        st.pop(); // Must throw
    } catch (const StackUnderflowException &e) {
        cout << "Caught: " << e.what() << endl;
    }

    return 0;
}

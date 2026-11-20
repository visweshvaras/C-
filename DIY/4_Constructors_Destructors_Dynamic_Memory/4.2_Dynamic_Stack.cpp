// DIY 4.2: Dynamic Integer Stack with Destructor
// Lab Manual Page 16: An integer Stack backed by a dynamic array; push/pop plus a destructor that releases the buffer.
#include <iostream>

using namespace std;

class Stack {
private:
    int *arr;
    int capacity;
    int topIdx;

public:
    Stack(int cap) : capacity(cap), topIdx(-1) {
        arr = new int[capacity];
        cout << "[Stack] Constructor: Allocated dynamic stack of capacity " << capacity << endl;
    }

    ~Stack() {
        cout << "[Stack] Destructor: Freeing dynamically allocated buffer of size " << capacity << endl;
        delete[] arr;
    }

    bool push(int val) {
        if (isFull()) {
            cout << "[Stack] Overflow: Cannot push " << val << ", stack is full!\n";
            return false;
        }
        arr[++topIdx] = val;
        cout << "[Stack] Pushed " << val << " (size: " << topIdx + 1 << "/" << capacity << ")\n";
        return true;
    }

    int pop() {
        if (isEmpty()) {
            cout << "[Stack] Underflow: Stack is empty!\n";
            return -1;
        }
        int val = arr[topIdx--];
        cout << "[Stack] Popped " << val << "\n";
        return val;
    }

    int peek() const {
        if (isEmpty()) return -1;
        return arr[topIdx];
    }

    bool isEmpty() const { return topIdx == -1; }
    bool isFull() const { return topIdx == capacity - 1; }
};

int main() {
    cout << "=== DIY 4.2: Integer Stack with Dynamic Allocation & RAII ===" << endl;
    {
        Stack s(4);
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50); // Overflow test

        cout << "Current top: " << s.peek() << endl;

        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop(); // Underflow test
    }
    cout << "Scope exited successfully, buffer released.\n";

    return 0;
}

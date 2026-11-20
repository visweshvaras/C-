// DIY 13.1: Raw Pointers to Smart Pointers (unique_ptr)
// Lab Manual Page 43: Take any Week-4 program that used new/delete and rewrite it with unique_ptr so no explicit delete remains.
#include <iostream>
#include <memory>

using namespace std;

class SmartStack {
private:
    unique_ptr<int[]> arr; // Automatic memory management
    int capacity;
    int topIdx;

public:
    SmartStack(int cap) : capacity(cap), topIdx(-1) {
        arr = make_unique<int[]>(capacity);
        cout << "[SmartStack] Allocated managed buffer for capacity " << capacity << endl;
    }

    // No explicit delete required in destructor!
    ~SmartStack() {
        cout << "[SmartStack] Destructor: unique_ptr automatically frees buffer.\n";
    }

    void push(int val) {
        if (topIdx < capacity - 1) {
            arr[++topIdx] = val;
            cout << "Pushed: " << val << endl;
        }
    }

    int pop() {
        if (topIdx >= 0) {
            return arr[topIdx--];
        }
        return -1;
    }

    int peek() const {
        return (topIdx >= 0) ? arr[topIdx] : -1;
    }
};

int main() {
    cout << "=== DIY 13.1: RAII Resource Management via std::unique_ptr ===" << endl;

    {
        SmartStack stack(3);
        stack.push(101);
        stack.push(202);
        stack.push(303);

        cout << "Popped: " << stack.pop() << endl;
        cout << "Exiting stack scope...\n";
    }

    cout << "Exited scope cleanly with zero raw deletes.\n";
    return 0;
}

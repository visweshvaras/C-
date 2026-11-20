// DIY 8.3: Virtual Destructor Preventing Resource Leak
// Lab Manual Page 28: Build a Base/Derived pair where Derived allocates memory; show the leak when the destructor is not virtual, then fix it.
#include <iostream>

using namespace std;

class Base {
public:
    Base() {
        cout << "[Base Constructor] Constructed base part\n";
    }

    // VIRTUAL DESTRUCTOR ensures derived destructor is called polymorphically
    virtual ~Base() {
        cout << "[Base Destructor] Destroyed base part\n";
    }
};

class Derived : public Base {
private:
    int *dynamicBuffer;
    int bufferSize;

public:
    Derived(int size = 100) : bufferSize(size) {
        dynamicBuffer = new int[bufferSize];
        cout << "[Derived Constructor] Allocated dynamic buffer (" 
             << bufferSize << " ints) at " << dynamicBuffer << endl;
    }

    ~Derived() override {
        cout << "[Derived Destructor] Freeing dynamic buffer at " << dynamicBuffer << endl;
        delete[] dynamicBuffer;
    }
};

int main() {
    cout << "=== DIY 8.3: Virtual Destructor Leak Proof Demonstration ===" << endl;

    cout << "\nAllocating Derived object through Base pointer:" << endl;
    Base *ptr = new Derived(50);

    cout << "\nDeleting through Base pointer (virtual destructor invoked):" << endl;
    delete ptr;

    cout << "\nResult: Both Derived and Base destructors executed cleanly, no leaks!" << endl;
    return 0;
}

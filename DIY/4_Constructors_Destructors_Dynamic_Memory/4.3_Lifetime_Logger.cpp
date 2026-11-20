// DIY 4.3: Lifetime Logger
// Lab Manual Page 16: Extend Program 4.1 so each Tracer is created with new inside a loop and deleted – observe how forgetting delete leaks.
#include <iostream>

using namespace std;

class Tracer {
private:
    int id;

public:
    Tracer(int i) : id(i) {
        cout << "  [Tracer #" << id << "] Constructed at memory: " << this << endl;
    }

    ~Tracer() {
        cout << "  [Tracer #" << id << "] Destructed from memory: " << this << endl;
    }
};

int main() {
    cout << "=== DIY 4.3: Dynamic Object Lifetime & Deallocation ===" << endl;

    cout << "\nPhase 1: Properly allocated and deleted inside loop:" << endl;
    for (int i = 1; i <= 3; ++i) {
        Tracer *t = new Tracer(i);
        delete t; // Proper RAII / deallocation
    }

    cout << "\nPhase 2: Array of dynamic tracers in a scope:" << endl;
    {
        const int COUNT = 3;
        Tracer* tracers[COUNT];
        for (int i = 0; i < COUNT; ++i) {
            tracers[i] = new Tracer(100 + i);
        }

        cout << "Working with tracers in active scope...\n";

        for (int i = 0; i < COUNT; ++i) {
            delete tracers[i];
        }
    }

    cout << "\nAll dynamically created objects successfully destroyed without memory leaks." << endl;
    return 0;
}

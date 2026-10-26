// Experiment 9, Program 9.2: Exception Handling
// Manual topic: Custom exceptions, multiple catch handlers, stack unwinding and exception hierarchies.
// Warning / common pitfall: Catch exceptions by const reference and order handlers from specific to general. RAII releases resources during unwinding.
// Real-world use case: Exceptions communicate invalid transactions, timeouts and configuration failures without silent error states.
// DIY extensions from the manual:
//   1. Create a validated input exception.
//   2. Observe destructor calls during unwinding.
//   3. Build a network exception hierarchy.
// ------------------------------------------------------------

#include <iostream>
using namespace std;

class Guard {
    int n;
public:
    Guard(int n) : n(n){ cout << "acquire " << n << endl;}
    ~Guard()               {cout << "release " << n << endl;} 
};

void risky() {
    Guard g1(1);
    Guard g2(2);
    throw runtime_error("boom");       
}

int main() {
    try { risky(); }
    catch (const exception &e) { cout << "caught: " << e.what() << endl; }
    return 0;
}
// Experiment 9, Program 9.3: Exception Handling
// Manual topic: Custom exceptions, multiple catch handlers, stack unwinding and exception hierarchies.
// Warning / common pitfall: Catch exceptions by const reference and order handlers from specific to general. RAII releases resources during unwinding.
// Real-world use case: Exceptions communicate invalid transactions, timeouts and configuration failures without silent error states.
// DIY extensions from the manual:
//   1. Create a validated input exception.
//   2. Observe destructor calls during unwinding.
//   3. Build a network exception hierarchy.
// ------------------------------------------------------------

#include <iostream>
#include <exception>
using namespace std;
struct NetworkError : exception {
    const char* what() const noexcept override { return "network error"; }
};
struct TimeoutError : NetworkError {             
    const char* what() const noexcept override { return "timeout"; }
};
void fetch(int ms) {
    if (ms > 100) throw TimeoutError();
    cout << "fetched in " << ms << " ms\n";
}
int main() {
    for (int d : {50, 200}) {
        try { fetch(d); }
        catch (const NetworkError &e) {       
            cout << "caught: " << e.what() << endl;
        }
    }
    return 0;
}
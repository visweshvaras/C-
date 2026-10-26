// Experiment 9, Program 9.1: Exception Handling
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
#include <string>
using namespace std;

class InvalidAge : public exception {       
    string msg;
public:
    InvalidAge(int a) : msg("Invalid age: " + to_string(a)) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

void registerVoter(int age) {
    if (age < 0)        throw InvalidAge(age);      
    if (age < 18)       throw string("Too young to vote");  
    cout << "Registered (age " << age << ")\n";
}

int main() {
    int ages[] = {25, 15, -3};
    for (int a : ages) {
        try { registerVoter(a); }
        catch (const InvalidAge &e) { cout << "[ERR] " << e.what() << endl; }
        catch (const string &s)     { cout << "[WARN] " << s << endl; }
        catch (...)                 { cout << "[ERR] unknown\n"; }
    }
    return 0;
}
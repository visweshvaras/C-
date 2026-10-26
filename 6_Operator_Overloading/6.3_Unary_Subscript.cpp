// Experiment 6, Program 6.3: Operator Overloading
// Manual topic: Arithmetic, comparison, stream, assignment, increment and subscript operator overloading.
// Warning / common pitfall: Return the correct type for chaining. Self-assignment must be safe, and invalid subscripts must not silently redirect writes.
// Real-world use case: Operators make domain objects such as complex values, counters and register arrays readable and natural to use.
// DIY extensions from the manual:
//   1. Add more Complex operators.
//   2. Test copy assignment and self-assignment.
//   3. Improve SafeArr error handling.
// ------------------------------------------------------------

#include <iostream>
using namespace std;
class Counter {
    int v;
public:
    Counter(int v = 0) : v(v) {}
    Counter& operator++()    { ++v; return *this; }             // pre-increment
    Counter operator++(int)  { Counter t=*this; ++v; return t; }// post (dummy int)
    int value() const { return v; }
};
class SafeArr {
    int a[5] = {10,20,30,40,50};
public:
    int& operator[](int i) {                                    // bounds-checked []
        if (i < 0 || i >= 5) { cout << "out of range!\n"; return a[0]; }
        return a[i];
    }
};
int main() {
    Counter c(5); ++c; c++;                    // 5 -> 6 -> 7
    cout << "Counter = " << c.value() << endl;
    SafeArr s; cout << "s[2] = " << s[2] << endl;   // 30
    s[10] = 99;                                // triggers range check
    return 0;
}

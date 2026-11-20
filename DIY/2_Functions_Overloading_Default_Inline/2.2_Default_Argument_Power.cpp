// DIY 2.2: Default-Argument Calculator
// Lab Manual Page 10: Write power(int base, int exp = 2) so power(5) gives 25 and power(2,10) gives 1024.
#include <iostream>

using namespace std;

// Function with default parameter exp = 2
long long power(int base, int exp = 2) {
    long long result = 1;
    bool negativeExp = (exp < 0);
    int p = negativeExp ? -exp : exp;

    for (int i = 0; i < p; ++i) {
        result *= base;
    }

    return result;
}

int main() {
    cout << "=== DIY 2.2: Default-Argument Power Function ===" << endl;

    // Default argument demonstration (exp = 2)
    cout << "power(5)       [default exp=2] = " << power(5) << " (expected 25)" << endl;
    
    // Explicit exponent demonstration
    cout << "power(2, 10)   [explicit exp]  = " << power(2, 10) << " (expected 1024)" << endl;
    cout << "power(3, 4)    [explicit exp]  = " << power(3, 4) << " (expected 81)" << endl;
    cout << "power(7)       [default exp=2] = " << power(7) << " (expected 49)" << endl;
    cout << "power(10, 0)   [zero exponent] = " << power(10, 0) << " (expected 1)" << endl;

    return 0;
}

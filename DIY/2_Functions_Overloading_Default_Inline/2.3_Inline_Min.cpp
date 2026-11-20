// DIY 2.3: Inline Min Function
// Lab Manual Page 10: Write an inline overloaded minVal returning the smaller of two ints and, via a second overload, the smallest of three ints.
#include <iostream>

using namespace std;

// Overload 1: Smaller of two ints
inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

// Overload 2: Smallest of three ints (calls 2-arg overload)
inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    cout << "=== DIY 2.3: Inline Overloaded minVal ===" << endl;

    int x = 25, y = 42, z = 13;

    cout << "Comparing two ints (" << x << ", " << y << "): minVal = " 
         << minVal(x, y) << endl;

    cout << "Comparing three ints (" << x << ", " << y << ", " << z << "): minVal = " 
         << minVal(x, y, z) << endl;

    int p = -10, q = -50, r = -25;
    cout << "Comparing negative ints (" << p << ", " << q << ", " << r << "): minVal = " 
         << minVal(p, q, r) << endl;

    return 0;
}

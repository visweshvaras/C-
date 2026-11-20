// DIY 11.1: Generic Utilities Template Functions
// Lab Manual Page 37: Write template functions swapVals(T&,T&) and findMax(T arr[], int n) and test with int and double.
#include <iostream>
#include <string>

using namespace std;

template <typename T>
void swapVals(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T findMax(const T arr[], int n) {
    if (n <= 0) return T();
    T maxElem = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxElem) {
            maxElem = arr[i];
        }
    }
    return maxElem;
}

int main() {
    cout << "=== DIY 11.1: Function Templates swapVals & findMax ===" << endl;

    // Test with int
    int a = 15, b = 40;
    cout << "Before swapVals: a=" << a << ", b=" << b << endl;
    swapVals(a, b);
    cout << "After swapVals : a=" << a << ", b=" << b << endl;

    int intArr[] = {4, 18, 92, 35, 7, 61};
    cout << "findMax(intArr, 6) = " << findMax(intArr, 6) << endl;

    // Test with double
    double d1 = 3.1415, d2 = 2.7182;
    cout << "\nBefore swapVals: d1=" << d1 << ", d2=" << d2 << endl;
    swapVals(d1, d2);
    cout << "After swapVals : d1=" << d1 << ", d2=" << d2 << endl;

    double dblArr[] = {1.23, 8.91, 4.56, 12.87, 0.45};
    cout << "findMax(dblArr, 5) = " << findMax(dblArr, 5) << endl;

    return 0;
}

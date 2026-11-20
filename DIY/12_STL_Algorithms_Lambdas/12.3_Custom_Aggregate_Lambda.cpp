// DIY 12.3: Custom Aggregate with std::accumulate & Lambdas
// Lab Manual Page 40: Use accumulate with a lambda to compute the product of all elements, or the sum of only the even ones.
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    cout << "=== DIY 12.3: std::accumulate with Custom Lambdas ===" << endl;

    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Data elements: ";
    for (int v : data) cout << v << " ";
    cout << endl;

    // 1. Product of all elements via accumulate
    long long product = accumulate(data.begin(), data.end(), 1LL, [](long long acc, int val) {
        return acc * val;
    });
    cout << "Product of all elements       : " << product << endl;

    // 2. Sum of only even elements via accumulate
    int evenSum = accumulate(data.begin(), data.end(), 0, [](int acc, int val) {
        return (val % 2 == 0) ? acc + val : acc;
    });
    cout << "Sum of only even numbers (2+4+6+8): " << evenSum << endl;

    return 0;
}

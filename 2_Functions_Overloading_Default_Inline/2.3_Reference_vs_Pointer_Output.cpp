// Experiment 2, Program 2.3: Functions: Overloading, Default & Inline
// Manual topic: Function overloading, inline functions, default arguments, references and pointer output parameters.
// Warning / common pitfall: Default arguments apply from the rightmost parameter. Overloads must differ by parameter types or count, not only return type.
// Real-world use case: Overloaded helpers and output parameters are common in placement coding and verification utilities.
// DIY extensions from the manual:
//   1. Implement generic swapVals and findMax functions.
//   2. Write a generic queue with enqueue, dequeue and front.
//   3. Compare reference and pointer approaches for multiple results.
// ------------------------------------------------------------

#include <iostream>

void minMax(const int values[], int n, int& minimum, int& maximum) {
    minimum = maximum = values[0];
    for (int i = 1; i < n; ++i) {
        if (values[i] < minimum) minimum = values[i];
        if (values[i] > maximum) maximum = values[i];
    }
}

void minMaxPtr(const int values[], int n, int* minimum, int* maximum) {
    *minimum = *maximum = values[0];
    for (int i = 1; i < n; ++i) {
        if (values[i] < *minimum) *minimum = values[i];
        if (values[i] > *maximum) *maximum = values[i];
    }
}

int main() {
    const int data[] = {7, 2, 9, 4, 1};
    int low, high;
    minMax(data, 5, low, high);
    std::cout << "ref -> min=" << low << " max=" << high << '\n';
    minMaxPtr(data, 5, &low, &high);
    std::cout << "ptr -> min=" << low << " max=" << high << '\n';
}

// Experiment 12, Program 12.3: STL Algorithms, Lambdas & Problem-Solving Patterns
// Manual topic: Sorting with lambdas, count_if, accumulate, priority_queue, find_if, lower_bound and next_permutation.
// Warning / common pitfall: Comparators need strict weak ordering. lower_bound requires sorted data. Lambda captures must not outlive captured variables.
// Real-world use case: Sorting records, filtering results and maintaining top-K scores are common placement and data-processing patterns.
// DIY extensions from the manual:
//   1. Sort pairs by their second field.
//   2. Find the top three values with a heap.
//   3. Use accumulate for a custom aggregate.
// ------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values = {3, 8, 1, 9, 4};
    const auto first = std::find_if(
        values.begin(), values.end(), [](int value) { return value > 5; });

    if (first != values.end()) {
        std::cout << "first > 5 : " << *first << '\n';
    }

    std::sort(values.begin(), values.end());
    const auto lower = std::lower_bound(values.begin(), values.end(), 4);
    std::cout << "lower_bound(4) index = "
              << (lower - values.begin()) << '\n';

    std::vector<int> permutation = {1, 2, 3};
    std::cout << "perms: ";
    do {
        for (int value : permutation) {
            std::cout << value;
        }
        std::cout << ' ';
    } while (std::next_permutation(permutation.begin(), permutation.end()));
    std::cout << '\n';
}

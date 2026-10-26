// Experiment 12, Program 12.2: STL Algorithms, Lambdas & Problem-Solving Patterns
// Manual topic: Sorting with lambdas, count_if, accumulate, priority_queue, find_if, lower_bound and next_permutation.
// Warning / common pitfall: Comparators need strict weak ordering. lower_bound requires sorted data. Lambda captures must not outlive captured variables.
// Real-world use case: Sorting records, filtering results and maintaining top-K scores are common placement and data-processing patterns.
// DIY extensions from the manual:
//   1. Sort pairs by their second field.
//   2. Find the top three values with a heap.
//   3. Use accumulate for a custom aggregate.
// ------------------------------------------------------------

#include <iostream>
#include <queue>
#include <vector>

int main() {
    const std::vector<int> scores = {50, 90, 20, 75, 60, 95, 40};
    std::priority_queue<int> scoresByRank(scores.begin(), scores.end());

    std::cout << "Top 3 scores: ";
    for (int rank = 0; rank < 3 && !scoresByRank.empty(); ++rank) {
        std::cout << scoresByRank.top() << ' ';
        scoresByRank.pop();
    }
    std::cout << '\n';
}

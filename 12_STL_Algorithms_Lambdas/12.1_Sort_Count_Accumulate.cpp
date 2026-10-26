// Experiment 12, Program 12.1: STL Algorithms, Lambdas & Problem-Solving Patterns
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
#include <numeric>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int marks;
};

int main() {
    std::vector<Student> students = {
        {"Asha", 88}, {"Ravi", 95}, {"Meera", 72}
    };

    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.marks > b.marks;
              });

    for (const auto& student : students) {
        std::cout << student.name << ' ' << student.marks << '\n';
    }

    const int passed = std::count_if(
        students.begin(), students.end(),
        [](const Student& student) { return student.marks >= 75; });
    std::cout << "Passed: " << passed << '\n';

    const int total = std::accumulate(
        students.begin(), students.end(), 0,
        [](int sum, const Student& student) { return sum + student.marks; });
    std::cout << "Total: " << total << '\n';
}

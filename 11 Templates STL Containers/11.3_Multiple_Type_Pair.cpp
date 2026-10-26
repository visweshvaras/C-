// Experiment 11, Program 11.3: Templates & STL Containers
// Manual topic: Function/class templates and vector, set, map, unordered_map and queue containers.
// Warning / common pitfall: Templates are checked when instantiated. map[key] inserts missing keys; vector indexing is unchecked, so use at() when needed.
// Real-world use case: Generic containers are reusable for packets, transactions, frequency counts and associative arrays.
// DIY extensions from the manual:
//   1. Write generic swapVals and findMax.
//   2. Implement a generic Queue.
//   3. Count words with unordered_map and find the most frequent.
// ------------------------------------------------------------

#include <iostream>
#include <string>

template <typename K, typename V>
struct Pair {
    K key;
    V value;

    void show() const {
        std::cout << key << " -> " << value << '\n';
    }
};

template <typename A, typename B>
auto bigger(A a, B b) {
    return (a > b) ? a : b;
}

int main() {
    Pair<std::string, int> first{"ECE", 121};
    first.show();

    Pair<int, double> second{7, 3.5};
    second.show();

    std::cout << "bigger(3, 9.5) = " << bigger(3, 9.5) << '\n';
}

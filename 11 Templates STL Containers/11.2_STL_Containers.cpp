// Experiment 11, Program 11.2: Templates & STL Containers
// Manual topic: Function/class templates and vector, set, map, unordered_map and queue containers.
// Warning / common pitfall: Templates are checked when instantiated. map[key] inserts missing keys; vector indexing is unchecked, so use at() when needed.
// Real-world use case: Generic containers are reusable for packets, transactions, frequency counts and associative arrays.
// DIY extensions from the manual:
//   1. Write generic swapVals and findMax.
//   2. Implement a generic Queue.
//   3. Count words with unordered_map and find the most frequent.
// ------------------------------------------------------------

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    std::vector<int> marks = {88, 91, 75};
    marks.push_back(95);
    std::cout << "vector(" << marks.size() << "): ";
    for (int mark : marks) {
        std::cout << mark << ' ';
    }
    std::cout << '\n';

    std::set<int> unique = {3, 1, 2, 3, 1};
    std::cout << "set: ";
    for (int value : unique) {
        std::cout << value << ' ';
    }
    std::cout << '\n';

    std::map<std::string, int> ports = {{"eth0", 1}, {"eth1", 2}};
    ports["eth2"] = 3;
    std::cout << "map: ";
    for (const auto& [name, number] : ports) {
        std::cout << name << '=' << number << ' ';
    }
    std::cout << '\n';

    std::unordered_map<std::string, int> frequency;
    for (const std::string word : {"cpp", "stl", "cpp"}) {
        ++frequency[word];
    }
    std::cout << "unordered_map: cpp x" << frequency["cpp"] << '\n';

    std::queue<int> queue;
    queue.push(10);
    queue.push(20);
    std::cout << "queue front=" << queue.front()
              << " back=" << queue.back() << '\n';
}

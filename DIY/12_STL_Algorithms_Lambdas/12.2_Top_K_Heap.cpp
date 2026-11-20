// DIY 12.2: Top-3 with Min-Heap Priority Queue
// Lab Manual Page 40: Read N numbers and print the three largest using a priority_queue (do not sort the whole array).
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cout << "=== DIY 12.2: Top-3 Largest Numbers via Min-Heap Priority Queue ===" << endl;

    vector<int> numbers = {45, 12, 89, 3, 76, 94, 21, 99, 58, 67, 91};
    cout << "Input stream (" << numbers.size() << " elements): ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Min-heap to maintain top-3 largest elements in O(N log 3)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : numbers) {
        minHeap.push(num);
        if (minHeap.size() > 3) {
            minHeap.pop(); // Remove smallest among top 4
        }
    }

    vector<int> top3;
    while (!minHeap.empty()) {
        top3.push_back(minHeap.top());
        minHeap.pop();
    }

    cout << "\nTop 3 largest elements (without sorting whole array):" << endl;
    for (int i = static_cast<int>(top3.size()) - 1; i >= 0; --i) {
        cout << "  #" << (3 - i) << ": " << top3[i] << endl;
    }

    return 0;
}

// Experiment 11, Program 11.1: Templates & STL Containers
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

template <typename T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
class Stack {
    T data[100];
    int top = -1;

public:
    void push(const T& value) {
        if (top == 99) {
            throw std::overflow_error("stack is full");
        }
        data[++top] = value;
    }

    T pop() {
        if (empty()) {
            throw std::underflow_error("stack is empty");
        }
        return data[top--];
    }

    bool empty() const {
        return top < 0;
    }
};

int main() {
    std::cout << maxOf(3, 7) << ' '
              << maxOf(2.5, 1.1) << ' '
              << maxOf<std::string>("apple", "mango") << '\n';

    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    while (!stack.empty()) {
        std::cout << stack.pop() << ' ';
    }
    std::cout << '\n';
}

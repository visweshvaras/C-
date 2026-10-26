// Experiment 13, Program 13.3: Smart Pointers, Design Patterns & Basic Multithreading
// Manual topic: unique_ptr ownership, a thread-safe Singleton logger, and mutex-protected shared state.
// Warning / common pitfall: Prefer RAII smart pointers over raw owning pointers. Protect every shared mutation with the same mutex, and join threads before exit.
// Real-world use case: These patterns support safe resource ownership, centralized logging and concurrent testbench activity.
// DIY extensions from the manual:
//   1. Build a Factory for more shapes.
//   2. Extend the Singleton logger.
//   3. Compare synchronized and unsynchronized counters.
// ------------------------------------------------------------

#include <iostream>
#include <mutex>
#include <thread>

long counter = 0;
std::mutex counterMutex;

void addSafe(int times) {
    for (int i = 0; i < times; ++i) {
        std::lock_guard<std::mutex> lock(counterMutex);
        ++counter;
    }
}

int main() {
    std::thread first(addSafe, 100000);
    std::thread second(addSafe, 100000);

    first.join();
    second.join();

    std::cout << "counter = " << counter << " (expected 200000)\n";
}

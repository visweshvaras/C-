// DIY 13.3: Race Condition Demonstration and Mutex Protection
// Lab Manual Page 43: Run Program 13.3 without the lock_guard, observe the wrong total over several runs, then restore the lock and confirm 200000.
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

long unsafeCounter = 0;
long safeCounter = 0;
mutex mtx;

void incrementUnsafe(int times) {
    for (int i = 0; i < times; ++i) {
        unsafeCounter++; // Data race! Non-atomic read-modify-write
    }
}

void incrementSafe(int times) {
    for (int i = 0; i < times; ++i) {
        lock_guard<mutex> lock(mtx);
        safeCounter++; // Synchronized
    }
}

int main() {
    cout << "=== DIY 13.3: Thread Race Condition vs Mutex Synchronization ===" << endl;
    const int ITERATIONS = 100000;

    // 1. Without lock (Race Condition)
    {
        unsafeCounter = 0;
        thread t1(incrementUnsafe, ITERATIONS);
        thread t2(incrementUnsafe, ITERATIONS);
        t1.join();
        t2.join();
        cout << "Unsynchronized Counter: " << unsafeCounter 
             << " (expected 200000, noticed race condition loss: " 
             << (2 * ITERATIONS - unsafeCounter) << ")" << endl;
    }

    // 2. With std::lock_guard (Synchronized)
    {
        safeCounter = 0;
        thread t1(incrementSafe, ITERATIONS);
        thread t2(incrementSafe, ITERATIONS);
        t1.join();
        t2.join();
        cout << "Synchronized with Mutex : " << safeCounter 
             << " (exact expected 200000)" << endl;
    }

    return 0;
}

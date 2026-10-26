// Experiment 13, Program 13.2: Smart Pointers, Design Patterns & Basic Multithreading
// Manual topic: unique_ptr ownership, a thread-safe Singleton logger, and mutex-protected shared state.
// Warning / common pitfall: Prefer RAII smart pointers over raw owning pointers. Protect every shared mutation with the same mutex, and join threads before exit.
// Real-world use case: These patterns support safe resource ownership, centralized logging and concurrent testbench activity.
// DIY extensions from the manual:
//   1. Build a Factory for more shapes.
//   2. Extend the Singleton logger.
//   3. Compare synchronized and unsynchronized counters.
// ------------------------------------------------------------

#include <iostream>
#include <string>

class Logger {
    Logger() = default;

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& get() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) const {
        std::cout << "[LOG] " << message << '\n';
    }
};

int main() {
    Logger::get().log("system up");
    Logger::get().log("same single instance");
}

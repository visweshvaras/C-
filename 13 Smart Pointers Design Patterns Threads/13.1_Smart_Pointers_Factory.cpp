// Experiment 13, Program 13.1: Smart Pointers, Design Patterns & Basic Multithreading
// Manual topic: unique_ptr ownership, a thread-safe Singleton logger, and mutex-protected shared state.
// Warning / common pitfall: Prefer RAII smart pointers over raw owning pointers. Protect every shared mutation with the same mutex, and join threads before exit.
// Real-world use case: These patterns support safe resource ownership, centralized logging and concurrent testbench activity.
// DIY extensions from the manual:
//   1. Build a Factory for more shapes.
//   2. Extend the Singleton logger.
//   3. Compare synchronized and unsynchronized counters.
// ------------------------------------------------------------

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

struct Shape {
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

struct Circle : Shape {
    explicit Circle(double radius) : radius(radius) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

private:
    double radius;
};

struct Square : Shape {
    explicit Square(double side) : side(side) {}

    double area() const override {
        return side * side;
    }

private:
    double side;
};

std::unique_ptr<Shape> makeShape(const std::string& kind) {
    if (kind == "circle") {
        return std::make_unique<Circle>(2.0);
    }
    if (kind == "square") {
        return std::make_unique<Square>(3.0);
    }
    throw std::invalid_argument("unknown shape: " + kind);
}

int main() {
    const auto circle = makeShape("circle");
    const auto square = makeShape("square");

    std::cout << "area circle = " << circle->area()
              << ", area square = " << square->area() << '\n';
}

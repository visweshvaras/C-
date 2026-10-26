// Experiment 3, Program 3.3: Classes, Objects & Encapsulation
// Manual topic: Private data, public member functions, arrays of objects, object passing and the this pointer.
// Warning / common pitfall: Keep invariants inside member functions. Use const member functions for read-only access and initialize every data member.
// Real-world use case: Encapsulated objects model registers, accounts and transactions in hardware verification.
// DIY extensions from the manual:
//   1. Add validation to a BankAccount.
//   2. Create an array of register objects.
//   3. Build a chainable Point class.
// ------------------------------------------------------------

#include <iostream>

class Point {
    int x;
    int y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point add(const Point& point) const { return Point(x + point.x, y + point.y); }
    Point& setX(int value) { this->x = value; return *this; }
    Point& setY(int value) { this->y = value; return *this; }
    void show() const { std::cout << '(' << x << ',' << y << ")\n"; }
};

void shift(Point& point) { point.setX(99); }
void tryShift(Point point) { point.setX(-1); }

int main() {
    Point a(1, 2), b(3, 4);
    Point c = a.add(b);
    c.show();
    Point d;
    d.setX(7).setY(8);
    d.show();
    shift(a);
    a.show();
    tryShift(b);
    b.show();
}

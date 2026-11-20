// DIY 3.1: Rectangle Class with Validation
// Lab Manual Page 13: private length and width, public setters with validation (reject negatives), and area()/perimeter() getters.
#include <iostream>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l = 1.0, double w = 1.0) : length(1.0), width(1.0) {
        setLength(l);
        setWidth(w);
    }

    bool setLength(double l) {
        if (l <= 0) {
            cout << "Validation Error: Length must be positive! Rejected: " << l << endl;
            return false;
        }
        length = l;
        return true;
    }

    bool setWidth(double w) {
        if (w <= 0) {
            cout << "Validation Error: Width must be positive! Rejected: " << w << endl;
            return false;
        }
        width = w;
        return true;
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }

    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2.0 * (length + width);
    }

    void display() const {
        cout << "Rectangle [" << length << " x " << width << "] -> Area: " 
             << area() << ", Perimeter: " << perimeter() << endl;
    }
};

int main() {
    cout << "=== DIY 3.1: Rectangle Class with Encapsulation & Validation ===" << endl;

    Rectangle r1(10.5, 5.0);
    r1.display();

    cout << "\nAttempting invalid updates (negative / zero):" << endl;
    r1.setLength(-4.0);
    r1.setWidth(0.0);
    r1.display();

    cout << "\nApplying valid updates:" << endl;
    r1.setLength(15.0);
    r1.setWidth(8.0);
    r1.display();

    return 0;
}

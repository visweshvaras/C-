// DIY 7.2: Multilevel Shapes Construction & Destruction Order
// Lab Manual Page 25: Shape -> Polygon -> Rectangle; each level adds one field; demonstrate the constructor call order with print statements.
#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(const string &col) : color(col) {
        cout << "[1. Shape Constructor] Initialized color = " << color << endl;
    }

    virtual ~Shape() {
        cout << "[1. Shape Destructor] Destroyed color = " << color << endl;
    }
};

class Polygon : public Shape {
protected:
    int numSides;

public:
    Polygon(const string &col, int sides) : Shape(col), numSides(sides) {
        cout << "[2. Polygon Constructor] Initialized numSides = " << numSides << endl;
    }

    ~Polygon() override {
        cout << "[2. Polygon Destructor] Destroyed numSides = " << numSides << endl;
    }
};

class Rectangle : public Polygon {
private:
    double length;
    double width;

public:
    Rectangle(const string &col, double l, double w) 
        : Polygon(col, 4), length(l), width(w) {
        cout << "[3. Rectangle Constructor] Initialized dimensions = " 
             << length << " x " << width << endl;
    }

    ~Rectangle() override {
        cout << "[3. Rectangle Destructor] Destroyed dimensions = " 
             << length << " x " << width << endl;
    }

    double area() const { return length * width; }
};

int main() {
    cout << "=== DIY 7.2: Multilevel Inheritance Constructor/Destructor Order ===" << endl;
    cout << "Creating Rectangle object inside local scope:\n" << endl;
    {
        Rectangle rect("Blue", 12.0, 5.0);
        cout << "\nRectangle active! Area: " << rect.area() << "\n" << endl;
        cout << "Exiting scope now:" << endl;
    }
    cout << "\nScope exited. Notice constructor is Base->Derived, and destructor is Derived->Base." << endl;

    return 0;
}

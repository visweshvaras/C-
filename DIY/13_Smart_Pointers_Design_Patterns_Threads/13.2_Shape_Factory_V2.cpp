// DIY 13.2: Shape Factory v2 with Triangle & Runtime Creation
// Lab Manual Page 43: Extend Program 13.1 with a Triangle and let the user type the shape name at run time; store the created shapes in a vector<unique_ptr<Shape>>.
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual void describe() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r = 3.0) : radius(r) {}
    double area() const override { return 3.1415926535 * radius * radius; }
    void describe() const override {
        cout << "Circle (radius=" << radius << ") -> Area: " << area() << endl;
    }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l = 4.0, double w = 5.0) : length(l), width(w) {}
    double area() const override { return length * width; }
    void describe() const override {
        cout << "Rectangle (" << length << " x " << width << ") -> Area: " << area() << endl;
    }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b = 6.0, double h = 4.0) : base(b), height(h) {}
    double area() const override { return 0.5 * base * height; }
    void describe() const override {
        cout << "Triangle (base=" << base << ", height=" << height << ") -> Area: " << area() << endl;
    }
};

unique_ptr<Shape> shapeFactory(const string &type) {
    if (type == "circle") return make_unique<Circle>(3.5);
    if (type == "rectangle") return make_unique<Rectangle>(6.0, 4.0);
    if (type == "triangle") return make_unique<Triangle>(5.0, 8.0);
    return nullptr;
}

int main() {
    cout << "=== DIY 13.2: Shape Factory v2 with Triangle & vector<unique_ptr<Shape>> ===" << endl;

    vector<unique_ptr<Shape>> shapes;
    vector<string> requestedTypes = {"circle", "triangle", "rectangle", "triangle"};

    cout << "Instantiating shapes via factory from request list:\n";
    for (const string &req : requestedTypes) {
        auto shp = shapeFactory(req);
        if (shp) {
            shapes.push_back(move(shp));
        }
    }

    cout << "\nIterating polymorphically over created shapes:\n";
    for (const auto &s : shapes) {
        s->describe();
    }

    return 0;
}

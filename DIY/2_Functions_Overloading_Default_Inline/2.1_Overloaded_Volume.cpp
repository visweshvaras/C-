// DIY 2.1: Overloaded Volume Function
// Lab Manual Page 10: Write three overloads computing the volume of a cube (1 arg), cuboid (3 args) and cylinder (2 args, radius & height).
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

// 1. Volume of Cube: side^3
double volume(double side) {
    return side * side * side;
}

// 2. Volume of Cuboid: length * width * height
double volume(double length, double width, double height) {
    return length * width * height;
}

// 3. Volume of Cylinder: PI * radius^2 * height
double volume(double radius, double height) {
    return PI * radius * radius * height;
}

int main() {
    cout << "=== DIY 2.1: Overloaded Volume Calculator ===" << endl;
    cout << fixed << setprecision(3);

    double cubeSide = 4.0;
    cout << "Cube (side = " << cubeSide << "): Volume = " 
         << volume(cubeSide) << endl;

    double length = 5.0, width = 3.0, height = 2.0;
    cout << "Cuboid (l=" << length << ", w=" << width << ", h=" << height 
         << "): Volume = " << volume(length, width, height) << endl;

    double radius = 3.0, cylHeight = 7.0;
    cout << "Cylinder (r=" << radius << ", h=" << cylHeight 
         << "): Volume = " << volume(radius, cylHeight) << endl;

    return 0;
}

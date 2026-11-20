// DIY 3.3: Complex Number Class
// Lab Manual Page 13: Store real and imag, provide setData() and display(); print a small array of complex numbers.
#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    double getReal() const { return real; }
    double getImag() const { return imag; }

    void display() const {
        if (imag >= 0) {
            cout << real << " + " << imag << "i" << endl;
        } else {
            cout << real << " - " << -imag << "i" << endl;
        }
    }
};

int main() {
    cout << "=== DIY 3.3: Complex Number Class and Object Array ===" << endl;

    const int N = 3;
    Complex numbers[N];

    numbers[0].setData(3.5, 4.2);
    numbers[1].setData(1.0, -2.5);
    numbers[2].setData(-5.0, 0.0);

    cout << "Array of Complex Numbers:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Complex[" << i << "] = ";
        numbers[i].display();
    }

    return 0;
}

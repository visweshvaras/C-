// DIY 6.2: Fraction Class with Auto-Simplification & Stream I/O
// Lab Manual Page 22: A Fraction class; overload << and >> and auto-simplify (divide by GCD) on construction.
#include <iostream>
#include <numeric>
#include <sstream>

using namespace std;

class Fraction {
private:
    int num;
    int den;

    void simplify() {
        if (den == 0) {
            cout << "Warning: Denominator cannot be zero! Setting to 1.\n";
            den = 1;
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int g = std::gcd(num, den);
        num /= g;
        den /= g;
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        simplify();
    }

    friend ostream& operator<<(ostream &os, const Fraction &f) {
        if (f.den == 1) {
            os << f.num;
        } else {
            os << f.num << "/" << f.den;
        }
        return os;
    }

    friend istream& operator>>(istream &is, Fraction &f) {
        char slash = '/';
        is >> f.num;
        if (is.peek() == '/') {
            is >> slash >> f.den;
        } else {
            is >> f.den;
        }
        f.simplify();
        return is;
    }
};

int main() {
    cout << "=== DIY 6.2: Fraction Class with GCD Auto-Simplification & Stream Overloading ===" << endl;

    Fraction f1(8, 12);
    cout << "Fraction(8, 12) auto-simplified: " << f1 << " (expected 2/3)" << endl;

    Fraction f2(15, -45);
    cout << "Fraction(15, -45) auto-simplified: " << f2 << " (expected -1/3)" << endl;

    Fraction f3(14, 7);
    cout << "Fraction(14, 7) integer display: " << f3 << " (expected 2)" << endl;

    cout << "\nDemonstrating stream >> reading from stringstream:" << endl;
    stringstream ss("18/24 100/25");
    Fraction readF1, readF2;
    ss >> readF1 >> readF2;
    cout << "Read '18/24'  -> " << readF1 << endl;
    cout << "Read '100/25' -> " << readF2 << endl;

    return 0;
}

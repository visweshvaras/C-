// DIY 6.1: Money Arithmetic with Carry & Borrow Overloading
// Lab Manual Page 22: A Money class (rupees, paise); overload + and - with correct carry/borrow of paise into rupees.
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Money {
private:
    long long rupees;
    int paise;

    void normalize() {
        if (paise >= 100) {
            rupees += paise / 100;
            paise %= 100;
        } else if (paise < 0) {
            long long borrowRupees = (-paise + 99) / 100;
            rupees -= borrowRupees;
            paise += borrowRupees * 100;
        }
    }

public:
    Money(long long r = 0, int p = 0) : rupees(r), paise(p) {
        normalize();
    }

    Money operator+(const Money &other) const {
        return Money(rupees + other.rupees, paise + other.paise);
    }

    Money operator-(const Money &other) const {
        return Money(rupees - other.rupees, paise - other.paise);
    }

    friend ostream& operator<<(ostream &os, const Money &m) {
        os << "Rs. " << m.rupees << "." << setfill('0') << setw(2) << m.paise;
        return os;
    }
};

int main() {
    cout << "=== DIY 6.1: Money Class with Overloaded + and - ===" << endl;

    Money m1(150, 75); // Rs. 150.75
    Money m2(49, 50);  // Rs. 49.50
    Money m3(20, 90);  // Rs. 20.90

    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;
    cout << "m3 = " << m3 << endl;

    Money sum = m1 + m2;
    cout << "\nm1 + m2 (with carry into rupees) = " << sum << endl;

    Money diff = m1 - m2;
    cout << "m1 - m2 (with borrow)             = " << diff << endl;

    Money diff2 = m2 - m3;
    cout << "m2 - m3                           = " << diff2 << endl;

    return 0;
}

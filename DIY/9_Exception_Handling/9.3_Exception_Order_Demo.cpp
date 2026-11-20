// DIY 9.3: Exception Handler Ordering Hierarchy Demo
// Lab Manual Page 31: Define MathError and a derived DivideByZero; show that catching MathError first hides DivideByZero, then fix the order.
#include <iostream>
#include <stdexcept>

using namespace std;

// Base Exception
class MathError : public runtime_error {
public:
    MathError(const string &msg = "Generic Math Error") : runtime_error(msg) {}
};

// Derived Exception
class DivideByZero : public MathError {
public:
    DivideByZero() : MathError("DivideByZero: Division by zero is undefined!") {}
};

double safeDivide(double num, double den) {
    if (den == 0.0) {
        throw DivideByZero();
    }
    return num / den;
}

int main() {
    cout << "=== DIY 9.3: Exception Hierarchy Catch Order Demo ===" << endl;

    cout << "\nDemonstration of CORRECT Ordering (Derived first, then Base):" << endl;
    try {
        safeDivide(10.0, 0.0);
    } catch (const DivideByZero &e) {
        cout << "[Derived Handler Caught]: " << e.what() << endl;
    } catch (const MathError &e) {
        cout << "[Base Handler Caught]: " << e.what() << endl;
    } catch (const exception &e) {
        cout << "[std::exception Caught]: " << e.what() << endl;
    }

    cout << "\nNote on Pitfall: If 'catch (const MathError &e)' is placed before 'catch (const DivideByZero &e)',";
    cout << "\nthe compiler will warn/intercept all DivideByZero exceptions in the base handler, hiding the specific handler.\n";

    return 0;
}

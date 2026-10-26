// Experiment 7, Program 7.3: Inheritance
// Manual topic: Multilevel inheritance, virtual inheritance for the diamond problem and hierarchical inheritance.
// Warning / common pitfall: Base classes used polymorphically need virtual destructors and virtual functions. Virtual inheritance shares one common base subobject.
// Real-world use case: Inheritance models reusable device and stream abstractions in verification environments.
// DIY extensions from the manual:
//   1. Extend the Device hierarchy.
//   2. Demonstrate the diamond problem.
//   3. Add derived account behaviors.
// ------------------------------------------------------------

#include <iostream>
using namespace std;
class Account {
protected:                             
    double balance = 0;
public:
    void deposit(double a) { balance += a; }
    double get() const { return balance; }
};
class Savings : public Account {      
public:
    void addInterest() { balance *= 1.04; }   
};
class Current : public Account {
public:
    void charge(double fee) { balance -= fee; }
};
int main() {
    Savings s; s.deposit(1000); s.addInterest();
    Current c; c.deposit(1000); c.charge(50);
    cout << "Savings = " << s.get() << ", Current = " << c.get() << endl;
    return 0;
}

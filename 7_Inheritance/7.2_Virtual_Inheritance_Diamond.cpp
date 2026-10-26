// Experiment 7, Program 7.2: Inheritance
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

class Stream {
public:
    Stream() { cout << "Stream ctor\n"; }
    void open() { cout << "stream opened\n"; }
};

class InStream  : virtual public Stream {};
class OutStream : virtual public Stream {};
class IOStream  : public InStream, public OutStream {};

int main() {
    IOStream io;
    io.open();        
    return 0;
}

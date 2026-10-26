// Experiment 8, Program 8.2: Polymorphism & Virtual Functions
// Manual topic: Abstract bases, runtime dispatch, virtual destructors, up-casting and down-casting.
// Warning / common pitfall: Use override to catch signature mistakes. Delete derived objects through a base pointer only when the base destructor is virtual.
// Real-world use case: Runtime polymorphism allows one testbench interface to drive many transaction or device types.
// DIY extensions from the manual:
//   1. Add a new Shape.
//   2. Compare early and late binding.
//   3. Use dynamic_cast safely.
// ------------------------------------------------------------

#include <iostream>
using namespace std;

class Base {
public:
    void normal() { 
        cout << "Base::normal (early binding)\n"; 
    }
    
    virtual void special() { 
        cout << "Base::special\n"; 
    }
};

class Derived : public Base {
public:
    void normal() { 
        cout << "Derived::normal\n"; 
    }
    
    void special() override { 
        cout << "Derived::special (late binding)\n"; 
    }
};

int main() {
    Derived d;
    Base *p = &d; 
   
    p->normal();  
 p->special(); 

    return 0;
}

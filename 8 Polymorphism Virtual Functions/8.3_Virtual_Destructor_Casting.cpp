// Experiment 8, Program 8.3: Polymorphism & Virtual Functions
// Manual topic: Abstract bases, runtime dispatch, virtual destructors, up-casting and down-casting.
// Warning / common pitfall: Use override to catch signature mistakes. Delete derived objects through a base pointer only when the base destructor is virtual.
// Real-world use case: Runtime polymorphism allows one testbench interface to drive many transaction or device types.
// DIY extensions from the manual:
//   1. Add a new Shape.
//   2. Compare early and late binding.
//   3. Use dynamic_cast safely.
// ------------------------------------------------------------

#include<iostream>
using namespace std;
class animal {
    public:
    virtual void speak() const = 0;
    virtual ~animal() { cout<<"~animal\n";}
};
class dog : public animal {
    public:
    void speak() const override { cout<<"woof\n";}
    ~dog() { cout<<"~dog\n";}
};
int main()
{
    animal *a = new dog();
    if(dog *d  = dynamic_cast<dog*>(a)) {
        cout<<"downcast ok ->";
        d->speak();

    }
    delete a;
    return 0;
}

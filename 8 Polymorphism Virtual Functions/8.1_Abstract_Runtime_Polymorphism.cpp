// Experiment 8, Program 8.1: Polymorphism & Virtual Functions
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
class Shape{
    public:
        virtual double area() const = 0;
        virtual void name() const = 0;
        virtual ~Shape(){}
};
class Circle : public Shape{
    double r;
    public:
        Circle(double r) : r(r){}
        double area() const override { return 3.14 * r * r; }
        void name() const override { cout << "Circle"; }
};
class Square : public Shape{
    double s;
    public:
        Square(double s) : s(s){}
        double area() const override { return s * s; }
        void name() const override { cout << "Square"; }
};
int main(){
    Shape* shapes[] = { new Circle(2), new Square(3) };
    for(Shape* s : shapes){
        s->name();
        cout << " area = " << s->area() << endl;
    }
    for(Shape* s : shapes) delete s;
}
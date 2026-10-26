// Experiment 5, Program 5.3: Static Members & Friend Functions
// Manual topic: Static object counters, friend functions operating across objects and friend classes accessing private state.
// Warning / common pitfall: Define a static data member exactly once. Friendship grants access but should be used only when the design requires it.
// Real-world use case: Static counters and controlled private access appear in resource tracking and testbench utilities.
// DIY extensions from the manual:
//   1. Track live objects.
//   2. Normalize and add two Distance objects.
//   3. Display private Car state through a friend class.
// ------------------------------------------------------------

#include<iostream>
using namespace std;
class Car{
    int speed=0;
    friend class Dashboard;
    public:
    void accelerate(){
        speed += 10;
    }
};
class Dashboard{
    public:
    void display(const Car &c){
        cout<<"Speed= "<<c.speed<<"Km/h \n";
    }
};
int main(){
    Car c; c.accelerate(); c.accelerate();
    Dashboard().display(c);
    return 0;
}
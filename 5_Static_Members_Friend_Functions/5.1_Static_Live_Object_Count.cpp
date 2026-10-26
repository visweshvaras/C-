// Experiment 5, Program 5.1: Static Members & Friend Functions
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
class Widget{
    int id;
    static int count;
    public:
    Widget(){id=++count;
    cout<<"Created W "<<id<<endl;}
    ~Widget (){--count;
    cout<<"Destroyed W"<<id<<endl;}
    static int alive(){return count;}
};

int Widget::count=0;
int main(){
    Widget a,b;
    cout<<"Alive= "<<Widget::alive()<<endl;
    {Widget c;
    cout<<"Alive= "<<Widget::alive()<<endl;}
    cout<<"Alive= "<<Widget::alive()<<endl;
    return 0;
}
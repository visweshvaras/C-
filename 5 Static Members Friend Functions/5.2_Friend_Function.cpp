// Experiment 5, Program 5.2: Static Members & Friend Functions
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
class Distance{
    int feet,inch;
    public:
    Distance(int f=0, int i=0):feet(f),inch(i){}
    friend Distance add(const Distance&a, const Distance &b);
    void show() const { cout<<feet<<"ft "<<inch<<"in \n";}
};
Distance add(const Distance &a, const Distance &b){
    int totalInch=((a.feet+b.feet)*12)+ a.inch+ b.inch;
    return Distance(totalInch/12, totalInch % 12);
}
int main(){
    Distance d1(5,8),d2(3,7);
    Distance d3=add(d1,d2);
    d3.show();
    return 0;
}
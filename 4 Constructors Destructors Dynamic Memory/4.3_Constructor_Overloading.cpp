// Experiment 4, Program 4.3: Constructors, Destructors & Dynamic Memory
// Manual topic: Construction/destruction order, deep copying, constructor overloading and delegating constructors.
// Warning / common pitfall: Objects in a block are destroyed in reverse construction order. Shallow copies of owned memory can cause double-free errors.
// Real-world use case: Resource lifetime and copy behavior are essential when objects own buffers or handles.
// DIY extensions from the manual:
//   1. Trace nested object lifetimes.
//   2. Compare deep and shallow copies.
//   3. Add safe constructor overloads to a Box.
// ------------------------------------------------------------

#include<iostream>
using namespace std;
class Box{
    int w,h,d;
    public:
    Box(int w,int h,int d):w(w),h(h),d(d){}
    Box(): Box(1,1,1){}
    Box(int s):Box(s,s,s){}
    int volume() const { return w*h*d;}
};
int main(){
    Box a; Box b(3); Box c(2,3,4);
    cout<<a.volume()<<" "<<b.volume()<<" "<<c.volume()<<endl;
    return 0;
}
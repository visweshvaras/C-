// Experiment 4, Program 4.1: Constructors, Destructors & Dynamic Memory
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

class Tracer{
    int id;
    public:
    Tracer(int i): id(i){
        cout<<"Constructor#"<<id<<endl;
    }
    ~Tracer(){
        cout<<"Destructor#"<<id<<endl;
    }
};
    int main(){
cout<<"Enter Block\n";{
    Tracer a(1),b(2);
    cout<<".....Working....\n";
}
    cout<<"Left Block\n";
    return 0;
    }
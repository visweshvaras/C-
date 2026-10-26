// Experiment 4, Program 4.2: Constructors, Destructors & Dynamic Memory
// Manual topic: Construction/destruction order, deep copying, constructor overloading and delegating constructors.
// Warning / common pitfall: Objects in a block are destroyed in reverse construction order. Shallow copies of owned memory can cause double-free errors.
// Real-world use case: Resource lifetime and copy behavior are essential when objects own buffers or handles.
// DIY extensions from the manual:
//   1. Trace nested object lifetimes.
//   2. Compare deep and shallow copies.
//   3. Add safe constructor overloads to a Box.
// ------------------------------------------------------------

#include<iostream>
#include<cstring>
using namespace std;
class MyString{
    char *data;
    public:
    MyString(const char *s){
        data= new char[strlen(s)+1];
        strcpy(data,s);
    }
    MyString(const MyString &o){
        data= new char [strlen(o.data)+1];
        strcpy(data,o.data);
    }
    ~MyString(){
        delete[]data;
    }
    void print() const { cout <<data<<endl;}
};
int main(){
    MyString a("hardware");
    MyString b=a;
    a.print();
    b.print();
    return 0;
}
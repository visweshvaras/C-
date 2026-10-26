// Experiment 3, Program 3.2: Classes, Objects & Encapsulation
// Manual topic: Private data, public member functions, arrays of objects, object passing and the this pointer.
// Warning / common pitfall: Keep invariants inside member functions. Use const member functions for read-only access and initialize every data member.
// Real-world use case: Encapsulated objects model registers, accounts and transactions in hardware verification.
// DIY extensions from the manual:
//   1. Add validation to a BankAccount.
//   2. Create an array of register objects.
//   3. Build a chainable Point class.
// ------------------------------------------------------------

#include<iostream>
using namespace std;
class Register {
    private:
    unsigned char value;
    public:
    void write(unsigned char v) {value = v;}
    unsigned char read() const{ return value; }
    void reset()   {value = 0;}
};
int main() {
    Register file[4];
    for(int i=0;i<4;i++) 
    file[i].reset();
    file[0].write(0xAB);
    file[3].write(0x10);
    for (int i = 0; i < 4; i++)
    cout<<"R"<<i<<"="<<(int)file[i].read()<<endl;
    return 0;
}
// Experiment 3, Program 3.1: Classes, Objects & Encapsulation
// Manual topic: Private data, public member functions, arrays of objects, object passing and the this pointer.
// Warning / common pitfall: Keep invariants inside member functions. Use const member functions for read-only access and initialize every data member.
// Real-world use case: Encapsulated objects model registers, accounts and transactions in hardware verification.
// DIY extensions from the manual:
//   1. Add validation to a BankAccount.
//   2. Create an array of register objects.
//   3. Build a chainable Point class.
// ------------------------------------------------------------

#include<iostream>
#include<string>
using namespace std;
class BankAccount{
    private:
    string owner;
    double balance;
    public:
    void open (const string &name, double initial) {
        owner = name;
        balance = (initial >= 0) ? initial : 0;
    }
    void deposit(double amt){ if (amt > 0) balance += amt;}
    bool withdraw(double amt) {
        if(amt > 0 && amt<= balance){balance -= amt; return true; }
    return false ;
}
double getbalance() const{return balance;}
string getowner() const{return owner;}
};
int main() {
    BankAccount a;
    a.open("Jack",1000);
    a.deposit(500);
    if(!a.withdraw(2000))
    cout<<"Withdraw denied(insufficient)\n";
    a.withdraw(300);
    cout<<a.getowner()<<"Balance= " <<a.getbalance()<<endl;
    return 0;
}

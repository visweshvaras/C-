// Experiment 1, Program 1.1: From C to C++: The Transition
// Manual topic: References, pointers, type-safe I/O, std::string, palindrome checks and frequency counting.
// Warning / common pitfall: Keep references initialized; use string::npos for failed searches. Cast characters to unsigned char before cctype functions, and handle empty strings before using size()-1.
// Real-world use case: These patterns are the C++ foundation for testbench transactions and safe text processing.
// DIY extensions from the manual:
//   1. Write a generic swap using references and pointers.
//   2. Read integers from a file and calculate basic statistics.
//   3. Count word frequencies with an unordered_map.
// ------------------------------------------------------------

#include<iostream>
using namespace std;

void swapref(int &a,int &b){ int t=a; a=b; b=t;}
void swapptr(int *a,int *b){ int t=*a; *a=*b; *b=t;}

int main(){
    int x=10,y=20;
    swapref(x,y);
    cout<<"after swapref : x=" <<x<< ",y="<<y<< endl;
    
    swapptr(&x,&y);
    cout <<"after swapptr: x="<<x<< ",y="<<y<< endl;

    int &alias=x;
    alias=99;
    cout <<"x via alias=" <<x<< endl;
    
}
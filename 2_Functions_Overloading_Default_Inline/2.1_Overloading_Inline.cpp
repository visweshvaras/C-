// Experiment 2, Program 2.1: Functions: Overloading, Default & Inline
// Manual topic: Function overloading, inline functions, default arguments, references and pointer output parameters.
// Warning / common pitfall: Default arguments apply from the rightmost parameter. Overloads must differ by parameter types or count, not only return type.
// Real-world use case: Overloaded helpers and output parameters are common in placement coding and verification utilities.
// DIY extensions from the manual:
//   1. Implement generic swapVals and findMax functions.
//   2. Write a generic queue with enqueue, dequeue and front.
//   3. Compare reference and pointer approaches for multiple results.
// ------------------------------------------------------------

#include<iostream>
using namespace std;
inline int square(int x){
    return x*x;
}
double area(double r){
    return 3.1459*r*r;
}
int area(int l,int b){
    return l*b;
}
double area(double b,double h){
    return 0.5*b*h;
}

int main(){
    cout<<"Square(6)= "<< square(6) <<endl;
    cout<<"Circle r=2 = "<< area(2.0) <<endl;
    cout<<"Rectange 4x5= "<< area(4,5) <<endl;
    cout<<"Triangle b=3 h=8 = "<<area(3.0,8.0) <<endl;
    return 0; 
}
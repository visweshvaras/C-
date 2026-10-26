// Experiment 2, Program 2.2: Functions: Overloading, Default & Inline
// Manual topic: Function overloading, inline functions, default arguments, references and pointer output parameters.
// Warning / common pitfall: Default arguments apply from the rightmost parameter. Overloads must differ by parameter types or count, not only return type.
// Real-world use case: Overloaded helpers and output parameters are common in placement coding and verification utilities.
// DIY extensions from the manual:
//   1. Implement generic swapVals and findMax functions.
//   2. Write a generic queue with enqueue, dequeue and front.
//   3. Compare reference and pointer approaches for multiple results.
// ------------------------------------------------------------

#include<iostream>
#include<string>
using namespace std;

//level defaults to 1 (INFO); Only the msg is mandatory
void logMsg(const string &msg, int level =1){
    const string tag[] = {" ","INFO","WARN","ERROR"};
cout<<"["<<tag[level]<<"]"<<msg<<endl;
} 

//Simple Intrest (default rate of 7.5%)
double intrest(double principal,double year,double rate= 7.5){
    return principal*rate*year/100.0 ;
}

int main(){
    logMsg ("System Started");
    logMsg ("Low Memory",2);
    cout<<"Intrest= "<<intrest(10000,2)<<endl;
    cout<<"Intrest= "<<intrest(10000,2,9.0)<<endl;
    return 0;
}

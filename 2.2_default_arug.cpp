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

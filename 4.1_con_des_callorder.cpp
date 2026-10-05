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
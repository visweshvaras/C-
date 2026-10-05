#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    string s="Verification";
    cout<<"First 4:"<<s.substr(0,4)<<endl;
    cout<<"From 4:"<<s.substr(4)<<endl;
    int c=s.compare("Verify");
    cout<<"Compare VS 'Verify':"<<(c<0?"c" : c>0?">")<<endl;
    int freq[26]={0};
    for(char c: s) 
    if(isalpha(unsigned char)c)
    freq[tolower(c)-'a']++;
    cout<<"Letter count: ";
    for(int i=0; i<26 ; ++i)
    if (freq[i])
    cout<<char('a'+i)<<"!"<<freq[i]<<" ";
    cout<<endl;    
    return 0;
}
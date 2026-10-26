// Experiment 1, Program 1.2: From C to C++: The Transition
// Manual topic: References, pointers, type-safe I/O, std::string, palindrome checks and frequency counting.
// Warning / common pitfall: Keep references initialized; use string::npos for failed searches. Cast characters to unsigned char before cctype functions, and handle empty strings before using size()-1.
// Real-world use case: These patterns are the C++ foundation for testbench transactions and safe text processing.
// DIY extensions from the manual:
//   1. Write a generic swap using references and pointers.
//   2. Read integers from a file and calculate basic statistics.
//   3. Count word frequencies with an unordered_map.
// ------------------------------------------------------------

#include<iostream> 
#include<string> 
using namespace std; 
int main() 
{ 
    string s; 
    cout << "Enter a word:"; 
    cin >> s; 
 
    cout<<"Length:"<< s.length()<< endl; 
    cout<<"Upper:"; 
    for(char c :s)cout<<(char)toupper(c); 
    cout<<endl; 
     
    bool pal=true; 
    for(size_t i=0,j=s.size()-1;i<j;++i,--j 
) 
if(s[i] !=s[j]){pal=false;break;} 
cout<<s<<(pal?"IS":"is NOT")<<"a palindrome\n"; 

size_t pos=s.find("an"); 
if( pos != string :: npos)
cout<<"'an'foumd at index"<<pos<<endl; 
else cout<<"'an' not found\n "; 
return 0; 
} 
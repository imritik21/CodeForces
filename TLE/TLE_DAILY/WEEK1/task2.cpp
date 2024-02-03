#include<iostream>
using namespace std;
int main(){
    // Given two numbers A and B. Print "Multiples" if A is multiple of B or vice versa. Otherwise print "No Multiples".
    int A,B;
    cin>>A>>B;
    if (A%B==0 || B%A==0)
    {
        cout<<"Multiples"<<endl;
    }
    else{
        cout<<"No Multiples"<<endl;
    }
}
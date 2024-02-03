#include<bits/stdc++.h>
using namespace std;
long long int fib(long long int n){
    if(n<=1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return fib(n-2)+fib(n-1);
    }
}
int main(){
    long long int n;
    cin>>n;
    // fib(n);
    cout<<fib(n)<<endl;
}
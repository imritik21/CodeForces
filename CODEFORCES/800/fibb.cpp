#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int fib(int n){
    if(n==0||n==1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<fib(i)<<" ";
    }
}
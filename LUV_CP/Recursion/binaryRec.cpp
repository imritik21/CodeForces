#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int bin(int n){
    if(n==0){
        return 0;
    }
    else{
        return (n%2 + 10*bin(n/2));
    }
}
int main(){
    int n;
    cin>>n;
    cout<<bin(n);
}


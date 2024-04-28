#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll powN(ll x,ll n){
    if(n==1){
        return x;
    }
    return x*powN(x,n-1);
}
// not optimized as twice fun call so O(N);
ll power(ll x,ll n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return power(x,n/2)*power(x,n/2);
    }
    else{
        return x*power(x,n/2)*power(x,n/2);
    }
}

// optimized O(logN)
ll optimizedPow(ll x,ll n){
    if(n==0){
        return 1;
    }
    ll halfpow=optimizedPow(x,n/2);
    ll halpowSq=halfpow*halfpow;
    if(n%2!=0){
        halpowSq=x*halpowSq;
    }
    return halpowSq;
}
int main(){
    ll x;
    cin>>x;
    ll n;
    cin>>n;
    cout<<powN(x,n)<<endl;
    cout<<power(x,n)<<endl;
    cout<<optimizedPow(x,n);
}

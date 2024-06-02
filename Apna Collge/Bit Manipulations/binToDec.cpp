#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll bintoDec(ll n){
    ll power = 0;
    ll ans = 0;
    while(n>0){
        ll rem = n%10;
        ans = ans + (rem*(ll)(pow(2,power)));
        power++;
        n/=10;
    }
    return ans;
}
ll dectoBin(ll n){
    ll power=0;
    ll ans = 0;
    while(n>0){
        ll rem = n%2;
        ans = ans + (rem*(ll)(pow(10,power)));
        power++;
        n/=2;
    }
    return ans;
}
int main(){
    ll n;
    cin>>n;
    cout<<bintoDec(n)<<endl;
    cout<<dectoBin(n);
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll factors(ll n){
    ll cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(n/i != i ){
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    ll n;cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(factors(arr[i])==3){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

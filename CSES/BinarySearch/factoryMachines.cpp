#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool f(ll x,vector<ll>&arr,ll t){
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,t;
    cin>>n>>t;
    vector<ll> arr(n);
    for(auto& i:arr){
        cin>>i;
    }
    ll lb = 1,ub=1e18;
    ll ans = 1e18;
    while(lb<=ub){
        ll mid = lb + (ub-lb)/2;
        if(f(mid,arr,t)){

        }
    }
    return 0;
}

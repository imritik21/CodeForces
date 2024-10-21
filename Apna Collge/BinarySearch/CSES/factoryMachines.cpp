#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool possible(ll mid,vector<ll>&arr,ll k){
    int n = arr.size();
    ll total = 0;
    for(int i=0;i<n;i++){
        total+=(mid/arr[i]);
        if(total>=k)return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    ll lb=0,ub=1e18;
    ll ans=0;
    while(lb<=ub){
        ll mid = lb + (ub-lb)/2;
        if(possible(mid,arr,k)){
            ans=mid;
            ub=mid-1;
        }
        else{
            lb=mid+1;
        }         
    }
    cout<<ans<<endl;
    return 0;
}

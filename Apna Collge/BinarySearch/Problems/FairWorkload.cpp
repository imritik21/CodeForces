#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool f(ll x,vector<ll>& arr, ll k){
    // predicate function
    // return true if we can split the array in k segments
    // and every segmentts have sum <= x 
    ll n = arr.size();
    ll worker = 1;
    ll sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>x){
            return false;
        }
        if(sum+arr[i]<=x){
            sum+=arr[i];
        }
        else{
            worker++;
            sum=arr[i];
        }
    }
    return worker<=k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    ll lb=0,ub=1e18;
    ll ans=1e18;
    while(lb<=ub){
        ll mid = lb + (ub-lb)/2;
        if(f(mid,arr,k)){
            // can be my possible ans;
            ans=mid;
            ub = mid-1;
        }
        else{
            lb = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}

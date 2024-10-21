#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool f(ll x,vector<ll>& arr,int k){
    ll workers = 1;
    ll sum=0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]>x){
            return false;
        }
        if(sum+arr[i]<=x){
            sum+=arr[i];
        }
        else{
            workers++;
            sum=arr[i];
        }
    }
    return workers<=k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(auto& i:arr){
        cin>>i;
    }
    ll ans=1e18;
    ll lb=0,ub=1e18;
    while(lb<=ub){
        ll mid = lb + (ub-lb)/2;
        if(f(mid,arr,k)){
            ans=mid;
            ub=mid-1;
        }
        else{
            lb = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}

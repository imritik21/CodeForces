#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool flag=false;
bool isPossible(vector<ll>& arr,ll x,ll sum,ll i){
    // if(i==arr.size()){
    //     if(sum==x) flag=true;
    //     return;
    // }
    // isPossible(arr,x,sum+arr[i],i+1);
    // isPossible(arr,x,sum-arr[i],i+1);
    if(i==arr.size()){
        return sum==x;
    }
    bool ans1=isPossible(arr,x,sum-arr[i],i+1);
    bool ans2=isPossible(arr,x,sum+arr[i],i+1);
    return ans1||ans2;
}
int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(isPossible(arr,x,0,0)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    map<ll,ll> mp;
    mp[0]=1;
    ll sum=0;
    ll cnt=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        // if sum is negative
        ll rem = (sum%n+n)%n;
        
        mp[rem]++;
    }
    for(auto it:mp){
        cnt+=(it.second*(it.second-1)/2); // here i am adding all possible combinations
    }
    cout<<cnt<<endl;
    return 0;
}

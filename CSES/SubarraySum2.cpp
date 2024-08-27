#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,k;
    cin>>n>>k;
    // vector<ll> arr(n);
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    // pre[0]=0;
    ll cnt=0;
    map<ll,ll> mp;
    // mp[0]=1;
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        // ll req = sum-k;
        // if(mp.find(req)!=mp.end())cnt+=mp[req];
        cnt+=mp[sum-k];
        if(sum==k)cnt++;
        mp[sum]++;
    }
    cout<<cnt<<endl;
    return 0;
}

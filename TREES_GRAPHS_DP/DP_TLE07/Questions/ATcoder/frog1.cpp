#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// int n;
// int N = 1e6;
// int dp[N];
ll fun(vector<ll> arr,ll i,vector<ll>& dp){
    if(i==0)return 0;
    if(dp[i]!=-1)return dp[i];
    ll cnt=INT_MAX;
    cnt = min(cnt,fun(arr,i-1,dp)+abs(arr[i]-arr[i-1]));
    if (i > 1)
        cnt = min(cnt, fun(arr, i - 2,dp) + abs(arr[i] - arr[i - 2]));
    return dp[i]=cnt;
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
    // if (n == 1)
    // {
    //     cout << 0 << endl;
    //     return 0;
    // }

    // vector<ll> dp(n+1,1e9);
    // dp[0]=0;
    // dp[1] = abs(arr[0]-arr[1]);
    // for(int i=1;i<n;i++){
    //     // if(i-2>=0){
    //     //     dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), dp[i - 2] + abs(arr[i] - arr[i - 2]));
    //     // }
    //     // else
    //     //     dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), arr[i]);
    //     dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), dp[i - 2] + abs(arr[i] - arr[i - 2]));
    // }
    // cout<<dp[n-1]<<endl;
    vector<ll> dp(n,-1);
    cout<<fun(arr,n-1,dp)<<endl;
    return 0;
}

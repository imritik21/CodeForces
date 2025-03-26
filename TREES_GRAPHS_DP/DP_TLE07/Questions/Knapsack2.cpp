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
    
    ll n,w;
    cin>>n>>w;
    vector<pair<ll,ll>> vec;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    // dp
    // vector<vector<ll>> dp(n+1,vector<ll>(w+1,0));
    vector<ll> dp(w+1,1e13);
    dp[0]=0;
    // if 0 items 
    // for(int i=0;i<n;i++)dp[0][w]=0;
    // for(int i=1;i<=n;i++){
    //     for(ll j=1;j<=w;j++){
    //         if(j>=vec[i-1].first){
    //             dp[i][j] = max(vec[i-1].second+dp[i-1][j-vec[i-1].first],dp[i-1][j]);
    //         }
    //         else dp[i][j] = dp[i-1][j];
    //     }
    // }
    // cout<<dp[n][w]<<endl;
    ll ans=0;
    for(int i=0;i<n;i++){
        for(ll j=w;j>=vec[i].first;j--){
            dp[j] = max(dp[j],vec[i].second+dp[j-vec[i].first]);
            if(dp[j]<=w)ans=max(ans,j);
        }
    }
    for(ll i=1;i<n;i++)if(dp[i]<=w)ans=max(ans,i);
    cout<<ans<<endl;
    return 0;
}

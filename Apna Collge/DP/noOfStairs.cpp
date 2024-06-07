#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll totalways(int n,vector<ll>& dp){
    if(n<0) return 0;
    if(n==0 || n==1) return 1;

    if(dp[n] != -1){
        return dp[n];
    }
    // else calc
    dp[n] = totalways(n-1,dp)+totalways(n-2,dp);
    return dp[n]%mod;
}
ll countWays(int n){
    vector<ll> dp(n+1,-1);
    return totalways(n,dp);
}
int main(){
    int n;
    cin>>n;
    // cout<<countWays(n);
    vector<int> dp(n+1,-1);
    // initialize base case
    dp[-1]=0;dp[0]=1;
    // meaning for index
    // here dp[i] willl store no of ways for each ith pos
    
    // now fill- bottom to up
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
}

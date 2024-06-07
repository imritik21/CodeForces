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
    cout<<countWays(n);
}

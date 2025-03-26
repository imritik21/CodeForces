#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int dp[1000001];
int rec(int sum){
    if(sum==0){
        return 1; // base case only 1 way
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    int ans=0;
    for(int i=1;i<=6;i++){
        if(sum-i>=0){
            ans+=rec(sum-i);
            // ans%=mod;
            if(ans>=mod){
                ans-=mod;
            }
        }
    }
    return dp[sum]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<rec(n)<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int funEnter=0;
int solveDP(int n,vector<int>&dp)
{
    if(n==0)return 0;
    if(n==1 || n==2)return 1;
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans = solveDP(n-1,dp)+solveDP(n-2,dp);
    dp[n]=ans;
    return ans;
}
// int helper(int n){
//     funEnter++;
//     if(n==1 || n==2){
//         return n;
//     }
//     return helper(n-1)+helper(n-2);
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    // dp[0]=1;
    // dp[1]=1;
    cout<<solveDP(n,dp)<<endl;
    return 0;
}

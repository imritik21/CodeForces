#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int mcm(vector<int>& values,int i,int j,vector<vector<int>>dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int cost1 = mcm(values,i,k,dp);
        int cost2 = mcm(values,k+1,j,dp);
        int cost3 = values[i-1]*values[k]*values[j];
        dp[i][j] = min(dp[i][j],cost1+cost2+cost3);
    }
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> values = {3,7,4,5};
    int n = values.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<mcm(values,1,n-1,dp);
    return 0;
}

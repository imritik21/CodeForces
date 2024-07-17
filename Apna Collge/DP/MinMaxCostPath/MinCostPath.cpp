#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n=3,m=3;
    vector<vector<int>> grid={{1,3,1},{1,5,1},{4,2,1}};
    // we have to find minimum cost path to reach
    // small problem is at last grid where cost is minimum
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[n-1][m-1]=grid[n-1][m-1];
    // now fill last row and last col 
    for(int i=n-2;i>=0;i--){
        dp[i][m-1]=grid[i][m-1]+dp[i+1][m-1];
    }
    for(int j=m-2;j>=0;j--){
        dp[n-1][j]=grid[n-1][j]+dp[n-1][j+1];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
        }
    }
    cout<<dp[0][0];
    return 0;
}

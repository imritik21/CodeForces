#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int totMinSum(vector<vector<int>> &path,int i,int j,int n,int m){
    
    if(i==n-1 && j==m-1){
        return path[i][j];
    }
    if(i>=n || j>=m){
        return INT_MAX;
    }
    int w1 = totMinSum(path,i,j+1,n,m);
    int w2 = totMinSum(path,i+1,j,n,m);
    
    return path[i][j]+min(w1,w2);
}
int solveDp(vector<vector<int>> &path,int i,int j,int n,int m,vector<vector<int>>&dp){
    if (i >= n  || j >= m ) // moving outside
    {
        return INT_MAX;
    }
    if(i==n-1 && j==m-1){ // base case
        return path[i][j];
    }
    
    if(dp[i][j]!=-1){ // this state was already calculated
        return dp[i][j];
    }
    // state never calculated before
    // state: min cost path from (i,j) to bottom path
    dp[i][j] = path[i][j]+ min(solveDp(path,i+1,j,n,m,dp),solveDp(path,i,j+1,n,m,dp));
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // find the path from top left to bottom right with minimum sum path
    vector<vector<int>> path = {{1,5,8},{6,2,7},{9,3,4}};
    // left and down
    int n = path.size();
    int m = path[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int ans=0;
    cout<<totMinSum(path,0,0,n,m)<<endl;
    // TC- O(c(n+m-2,m-1))
    cout<<solveDp(path,0,0,n,m,dp)<<endl;
    // TC
    return 0;
}

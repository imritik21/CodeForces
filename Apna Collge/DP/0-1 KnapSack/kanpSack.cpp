#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void print(vector<vector<int>> dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int tabulation(int val[],int wt[],int w,int n){
    // create table 2D array 
    vector<vector<int>> dp(n+1,vector<int>(w+1));
    // initialize it
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<w+1;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int v = val[i-1];//ith val
            int wgt = wt[i-1];//ith wt
            if(wgt<=j){
                // valid
                int incProfit = v+dp[i-1][j-wgt];
                int excProfit = dp[i-1][j];
                dp[i][j] = max(incProfit,excProfit);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    print(dp);
    return dp[n][w];
}
int memoization(int val[],int wt[],int w,int n,vector<vector<int>>&dp){
    if(n==0 || w==0) return 0; // base cond
    // if already calc
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(wt[n-1]<=w){
        // valid case
        int incProfit = val[n-1]+memoization(val,wt,w-wt[n-1],n-1,dp);
        int excProfit = memoization(val,wt,w,n-1,dp);
        dp[n][w]=max(incProfit,excProfit);
        return dp[n][w];
    }
    else{
        // in valid
        dp[n][w] = memoization(val,wt,w,n-1,dp);
        return dp[n][w];
    }
}
int main(){
    int n;
    cin>>n;
    int val[] = {15,14,10,45,30};
    int wt[] = {2,5,1,3,4};
    int w = 7;
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    // cout<<memoization(val,wt,w,n,dp)<<endl;
    cout<<tabulation(val,wt,w,n);
}

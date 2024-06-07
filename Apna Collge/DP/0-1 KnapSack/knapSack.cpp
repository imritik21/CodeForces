#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int knapSackVal(int val[],int wt[],int w,int n,vector<vector<int>>& dp){
    if(w==0 || n==0) return 0;

    // if already calculated
    if(dp[n][w] != -1){
        return dp[n][w]; // return directly
    }
    // valid 
    if(wt[n-1]<=w){
        // include
        int ans1 = val[n-1]+knapSackVal(val,wt,w-wt[n-1],n-1,dp);
        // not include
        int ans2 = knapSackVal(val,wt,w,n-1,dp);

        dp[n][w]=max(ans1,ans2);
        return dp[n][w];
    }
    else{
        dp[n][w] = knapSackVal(val,wt,w,n-1,dp);
        return dp[n][w];
    }
}
int knapsack(int weight[], int value[], int n, int w) 
{
	// Write your code here
	vector<vector<int>> dp(n+1,vector<int>(w+1));
	for(int i=0;i<n+1;i++){
		dp[i][0]=0;
	}
	for(int j=0;j<w+1;j++){
		dp[0][j]=0;
	}
	for(int i=1;i<n+1;i++){ // i is items
		// j is capacity 
		for(int j=1;j<w+1;j++){
			int v = value[i-1]; // ith value
			int wt = weight[i-1]; // ith weight
			if(wt<=j){
				// valid case
				int incProfit = v+dp[i-1][j-wt];
				int excProfit = dp[i-1][j];
				dp[i][j]=max(incProfit,excProfit);
			}
			else{
				// in valid
				dp[i][j]=dp[i-1][j];//excProfit
			}
		}

	}
	return dp[n][w];
}
int main(){
    int val[] = {15,14,10,45,30};
    int wt[] = {2,5,1,3,4};
    int w = 7;
    vector<vector<int>> dp(5+1,vector<int>(w+1,-1));
    // cout<<knapSackVal(val,wt,w,5,dp);
    cout<<knapsack(wt,val,5,w);
}

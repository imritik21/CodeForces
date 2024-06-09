#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    vector<int> rv = {1,1,3,3}; // Example input
    sort(rv.begin(),rv.end());
    // 1 2 3 4 6

    int n = 4;
    int maxSum=8;
    vector<vector<int>> dp(n+1,vector<int>(maxSum+1,0));
    //
    // i,j ki i items ke sath kitna value
    /*
        eg+  1 2
        iska mat
        n=2 sum 5
        0 0 0 0 0
        0 1 
        0 3
    */
    int maxi=INT_MIN;
    for(int i=1;i<n;i++){
        for(int j=1;j<maxSum+1;j++){
            int last = rv[i-1];
            if(last>dp[i][j-1]){
                dp[i][j] = last + dp[i][j-1];
                maxi=max(maxi,dp[i][j]);
            }
            else{
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    print(dp);
    cout<<dp[n][maxSum]<<endl;
    cout<<maxi;
    return 0;
}

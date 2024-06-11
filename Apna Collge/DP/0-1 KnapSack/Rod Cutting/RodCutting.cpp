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
int main(){
    int n = 8;
    int length[] = {1,2,3,4,5,6,7,8}; // wt
    int price[] = {1,5,8,9,10,17,17,20};// val
    int totRod = 8; // w
    //we need to obtain maximum cost
    vector<vector<int>> dp(n+1,vector<int>(totRod+1,0));
    //initialize
    // agr rodlength 0 hai to 0 profit
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    // agr totrod hi 0 to profit 0 
    for(int i=0;i<totRod+1;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            int len = length[i-1];
            if(len<=j){
                // valid
                dp[i][j]=max(price[i-1]+dp[i][j-len],dp[i-1][j]);//
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    print(dp);
    cout<<dp[n][totRod];
}
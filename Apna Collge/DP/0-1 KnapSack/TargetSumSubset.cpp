#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 int cnt=0;
void print(vector<vector<bool>> dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool targetSum(int number[],int sum,int n){
    // tabulation 
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    // initialize it
    for(int i=0;i<n+1;i++){ // if sum = 0 every true as of empty subset
        dp[i][0]=true;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            int v = number[i-1];
            // valid id arr[i]<req sum abhi wala
            if(v<=j && dp[i-1][j-v]==true){ // 1 ele nikal kr and uska sum htane pe kya true h
                dp[i][j]=true; // agr chota wala true hai to i,j bhi 
            }// invalid
            else if(dp[i-1][j]==true){
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    print(dp);
    return dp[n][sum];
}
int main(){
    int number[] = {1,1,1,1,1};
    int sum = 3;
    cout<<targetSum(number,sum,5);
}

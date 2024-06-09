#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n;
    cin>>n;
    int val[] = {15,14,10,45,30};
    int wt[] = {2,5,1,3,4};
    int w=7;
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    // initialize
    for(int i=0;i<n+1;i++){ // if items are zero profit =0
        dp[i][0]=0;
    }
    for(int i=0;i<w+1;i++){ // if sack size are zero profit =0
        dp[0][i]=0;
    }
    // now
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int v = val[i-1]; //ith index
            int wgt = wt[i-1]; //ith idx
            if(wgt<=j){
                // valid and include
                int incProfit = v+dp[i][j-wgt]; // i isiliye kyuki iss ele ko bhi le skte h
                int excProfit = dp[i-1][j]; // yha no change kyuki i lena hi nhi hai
                dp[i][j]=max(incProfit,excProfit);
            }
            else{
                dp[i][j] = dp[i-1][j]; // invalid to whi same weight me i-1 ele se kitna profit
            }
        }
    }
    cout<<dp[n][w]<<endl;
}

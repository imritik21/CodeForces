#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n = 4;
    int sum=10;
    int coins[]={2,5,3,6};
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    // sum =0 hai aur items hai merepass
    // to 0 sum dene ke 1 ways h kuch na du
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;// 1 ways to hai
    }
    // agr itesm 0 to 0 hi hoga ways kyuki de hi nhi skte
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            int coin = coins[i-1];//ith value
            if(coin<=j){
                // valid hai
                // yha mujhe no of ways nikalna hai
                dp[i][j]=dp[i][j-coin]+dp[i-1][j];//include+exclude
            }
            else{
                // exclude
                // [i-1][j] //
                dp[i][j]=dp[i-1][j]; // i-1 coin se kitna ways
            }
        }
    }
    cout<<dp[n][sum];
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n=5;
    int val[] = {15,14,10,45,30};
    int wt[] = {2,5,1,3,4};
    int w = 7;
    // we need to find in wt value of 7 how much maximum 
    // profit we can make
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    // let's fill
    // when weight is 0 profit will be 0
    // when no weight is taken then also profit will be zero
    // now
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int value = val[i-1];
            int weight = wt[i-1];
            if(weight<=j){
                // valid case take the wight
                // max of include and exclude profit
                dp[i][j] = max(value+dp[i-1][j-weight],dp[i-1][j]);
            }
            else{
                // invalid case exclude
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}

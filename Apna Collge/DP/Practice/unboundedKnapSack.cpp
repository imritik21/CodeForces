#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> val = {15, 4, 10, 45, 30};
    vector<int> weight = {2, 5, 1, 3, 4};
    int n = val.size();
    int w = 7;
    // i need to find the max val/profit i can make by taking max weight of w
    // so we'll use dp to chosse wheter elements wants to come or not if they are vlid
    // since we have 2 variable here as my w will decrease when i'll put something in my sack
    // and my profit/val will inc
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    // initialize
    // since when weight will 0 then 0 profit
    // when val is 0 obv 0 profit
    // they are already initialized
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            int profit = val[i - 1]; // ith val
            int wt = weight[i - 1];  // ith weight
            if (wt <= j)
            { // valid
                dp[i][j] = max(profit + dp[i][j - wt], dp[i - 1][j]); // ele can be repeatidly taken
            }
            else{
                // invalid 
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w];
    return 0;
}

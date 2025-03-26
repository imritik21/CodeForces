// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007
// // int n;
// // int dp[1000001][n];

// int f(int sum, int idx, vector<int> &coins, vector<vector<int>>&dp)
// {
//     if (sum == 0)
//     {
//         return 1;
//     }
//     if(idx>=coins.size() || sum<0)return 0;

//     if (dp[sum][idx] != -1)
//     {
//         return dp[sum][idx];
//     }
//     // removing this loop bcz we dont want include every possible outcome
//     // for (int i = 0; i < coins.size(); i++)
//     // {
//     //     if (sum - coins[i] >= 0)
//     //     {
//     //         ans += f(sum - coins[i], coins);
//     //         if (ans >= mod)
//     //         {
//     //             ans -= mod;
//     //         }
//     //     }
//     // }
//     int ans = 0;
//     // include this coin
//     if(sum-coins[idx]>=0){
//         ans+=f(sum-coins[idx],idx,coins,dp);
//         if(ans>=mod)ans-=mod;
//     }
//     // exlude
//     ans+=f(sum,idx+1,coins,dp);
//     if(ans>=mod)ans-=mod;
//     return dp[sum][idx] = ans;
// }
// void solve()
// {
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     // cin>>n;
//     int n,sum;
//     cin>>n>>sum;
//     // i have to count total no of ways to raech sum
//     // same as dice combinations but this time on array
//     vector<int> coins(n);
//     for (int i = 0; i < n; i++)
//         cin >> coins[i];
//     vector<vector<int>> dp(sum + 1, vector<int>(n, -1));
//     cout << f(sum,0, coins,dp) << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    // dp[s] will hold the number of ways to form sum s
    vector<int> dp(target + 1, 0);
    dp[0] = 1; // One way to form sum 0

    // Since we want distinct ordered ways, iterate over the coins in order.
    // For each coin, update dp from coin's value up to target.
    for (int idx = 0; idx < n; idx++)
    {
        // 1st all sum for 2 like 2,4,6,8
        // the for 3 like 2,3,4,5(2+3),6,6,7,8,8,9,9
        // then with 5..................
        for (int s = coins[idx]; s <= target; s++)
        {
            dp[s] = (dp[s] + dp[s - coins[idx]]) % mod;
        }
        // for (int i = 1; i <= target; i++)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout<<endl;
    }
    cout << endl;
    cout << dp[target] << "\n";
    return 0;
}

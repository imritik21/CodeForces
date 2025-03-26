// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007
// int dp[1000001];

// int f(int sum,vector<int>&coins){
//     if(sum==0){
//         return 1;
//     }
//     if(dp[sum]!=-1){
//         return dp[sum];
//     }
//     int ans=0;
//     for(int i=0;i<coins.size();i++){
//         if(sum-coins[i]>=0){
//             ans+=f(sum-coins[i],coins);
//             if(ans>=mod){
//                 ans-=mod;
//             }
//         }
//     }
//     return dp[sum]=ans;
// }
// void solve()
// {
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     int n,sum;
//     cin>>n>>sum;
//     // i have to count total no of ways to raech sum
//     // same as dice combinations but this time on array
//     vector<int> coins(n);
//     for(int i=0;i<n;i++)cin>>coins[i];
//     memset(dp,-1,sizeof(dp));
//     cout<<f(sum,coins)<<endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
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
    dp[0] = 1; // There's 1 way to form sum 0 (by taking nothing)

    // Outer loop: iterate over all sums from 1 to target.
    // Inner loop: try each coin.
    for (int s = 1; s <= target; s++)
    {
        for (int i = 0; i < n; i++)
        {
            if (s - coins[i] >= 0)
            {
                dp[s] = (dp[s] + dp[s - coins[i]]) % mod;
            }
        }
    }

    cout << dp[target] << "\n";
    return 0;
}

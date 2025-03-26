
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
const int mod = 1e9+7;
int f(vector<vector<ll>> &arr, int n, int i, int j, vector<vector<ll>> &dp)
{
    if(i>=n || j>=n){
        return 0;
    }
    if(arr[i][j]==0)return 0;
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    
    dp[i][j] = (f(arr, n, i + 1, j, dp)+ f(arr, n, i, j + 1, dp))%mod;// right and down ke paths
    return dp[i][j];
}
void solve()
{
    ll n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    vector<vector<ll>> arr(n, vector<ll>(n, 1));
    vector<vector<ll>> dp(n, vector<ll>(n, -1));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='*')arr[i][j]=0;
        }
    }
    cout<<f(arr,n,0,0,dp)<<endl;
}
int main()
{
    fast_cin();
    ll t = 1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
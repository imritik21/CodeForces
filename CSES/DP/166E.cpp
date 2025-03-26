#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int add(int x, int y)
{
    return (x % mod + y % mod) % mod;
}

int fun(int rem, int pos, vector<vector<int>> &dp)
{
    if (rem == 0)
    {
        return (pos == 3) ? 1 : 0;
    }
    if (dp[rem][pos] != -1)
        return dp[rem][pos];

    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (i == pos)
            continue;
        ans = add(ans, fun(rem - 1, i, dp));
    }
    return dp[rem][pos] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> dp(n + 3, vector<int>(5, -1));

    int ans = fun(n, 3, dp);
    cout << ans << endl;

    return 0;
}

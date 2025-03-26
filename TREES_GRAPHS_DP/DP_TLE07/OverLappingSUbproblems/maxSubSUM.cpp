#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n = 6;
vector<int> dp(n, -1); // Use vector instead of array
vector<int> a = {1, 4, 2, -10, 10, 5};

int f(int idx)
{
    if (idx < 0)
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    dp[idx] = max(a[idx] + f(idx - 2), f(idx - 1));
    return dp[idx];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << f(n - 1) << endl; // Correctly computes max non-adjacent sum
    return 0;
}

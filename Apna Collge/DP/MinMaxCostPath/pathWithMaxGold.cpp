#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*
                                {0, 1, 4, 2, 8, 2},
                                 {4, 3, 6, 5, 0, 4},
                                 {1, 2, 4, 1, 4, 6},
                                 {2, 0, 7, 3, 2, 2},
                                 {3, 1, 5, 9, 2, 4},
                                 {2, 7, 0, 8, 5, 1}*/
void print(vector<vector<int>> dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> paths = {{0,6,0},
                                 {5,8,7},
                                 {0,9,0}};
    int n = paths.size(), m = paths[0].size();
    // small problem is last col ki wha max utna hi mil skta h
    // udher se fill krna shuru
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][m - 1] = paths[i][m - 1];
    }
    // now filling
    for (int j = m - 2; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                dp[i][j] = paths[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            }
            else if (i == n - 1)
            {
                dp[i][j] = paths[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            }
            else
            {
                dp[i][j] = paths[i][j] + max(dp[i][j + 1], max(dp[i - 1][j + 1], dp[i + 1][j + 1]));
            }
        }
    }
    print(dp);
    return 0;
}

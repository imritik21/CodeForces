#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void print(vector<vector<bool>> dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s = "baaabab";
    string p = "*****ba*****ab";
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] = false;
    }
    for (int j = 1; j < m + 1; j++)
    {
        if (p[j - 1] == '*')
        {
            dp[0][j] = dp[0][j - 1];
        }
        else
        {
            dp[0][j] = false;
        }
    }
    // now
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            // 3 case
            // 1 if char same or ?
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1]; // check for smaller one
            }
            else if (p[j - 1] == '*')
            {
                // 2 case arise here ignore * for empty str and include * always for long seq
                // if any one of them is ture then true
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    print(dp);
    cout<<dp[n][m];
    return 0;
}

/*
A message containing letters from A-Z can be encoded into
numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits
must be grouped then mapped back into letters using the
reverse of the mapping above (there may be multiple ways).
 For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06"
cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number
of ways to decode it.
https://leetcode.com/problems/decode-ways/description/
*/
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

    string s = "1201234";
    int n = s.size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        // there is 4 case
        // both zero  00
        if (s[i - 1] == '0' && s[i] == '0')
        {
            dp[i] = 0; // no possible way for ith index
        }
        else if (s[i - 1] == '0' && s[i] != '0')
        {
            dp[i] = dp[i - 1]; // only this way bcz zero didnt formed anything
        }
        else if (s[i - 1] != '0' && s[i] == '0')
        {
            // 2 case 20 ,70
            if (s[i - 1] == '1' || s[i - 1] == '2')
            {
                dp[i] = (i >= 2 ? dp[i - 2] : 1);
            }
            else
            {
                dp[i] = 0;
            }
        }
        else
        {
            // bot non zero
            // 2 case 23 73
            if (stoi(s.substr(i - 1, 2)) <= 26)
            {
                // tb to dono add kro valid h
                dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);
            }
            else
            {
                // 73 -> to bss prev wala hi jitna hi form krhega
                dp[i] = dp[i - 1];
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";
    cout << endl;
    cout << dp[n - 1] << endl;
    return 0;
}

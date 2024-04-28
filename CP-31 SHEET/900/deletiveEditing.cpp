#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        string t;
        cin >> t;
        int n = s.length();
        int m = t.length();
        vector<int> cnt(26, 0);
        for (auto i : t)
        {
            cnt[i - 'A']++;
        }
        string temp = "";
        for (int i = s.size()-1; i >= 0; i--)
        {
            if (cnt[s[i] - 'A'] > 0)
            {
                temp += s[i];
                cnt[s[i] - 'A']--;
            }
        }
        reverse(temp.begin(), temp.end());
        if (temp == t)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, c;
    cin >> n >> c;
    string str;
    cin >> str;
    map<char, int> mp;
    int maxLen = 0;
    ll curr = 0, a = 0, b = 0;
    for (int l = 0, r = 0; r < n; r++)
    {
        
        a += (str[r] == 'a');
        b += (str[r] == 'b');
        if (str[r] == 'b')
            curr += a;
        while (curr > c)
        {

            a -= (str[l] == 'a');
            b -= (str[l] == 'b');
            if (str[l] == 'a')
                curr -= b;
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
        // }
    }
    cout << maxLen << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve()
{
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    vv32 prefixFreqA(26, v32(n + 1, 0));
    vv32 prefixFreqB(26, v32(n + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            prefixFreqA[j][i + 1] = prefixFreqA[j][i];
            prefixFreqB[j][i + 1] = prefixFreqB[j][i];
        }
        prefixFreqA[a[i] - 'a'][i + 1]++;
        prefixFreqB[b[i] - 'a'][i + 1]++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;  

        int op = 0;
        for (int i = 0; i < 26; i++) {
            int countA = prefixFreqA[i][r + 1] - prefixFreqA[i][l];
            int countB = prefixFreqB[i][r + 1] - prefixFreqB[i][l];
            op += abs(countA - countB);
        }
        cout << op / 2 << endl;
    }
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}

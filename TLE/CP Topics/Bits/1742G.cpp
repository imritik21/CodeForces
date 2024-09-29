
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> vis(n, 0);
    vector<ll> ans;

    ll mask = 0;
    for (int bit = 0; bit < 31; bit++)
    {
        ll maxi = mask;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && ((arr[i] | mask) > maxi))
            {
                maxi = (arr[i] | mask);
                idx = i;
            }
        }
        if (idx == -1)
            break;
        vis[idx] = 1;
        ans.push_back(arr[idx]);
        mask |= maxi;
    }
    for (int i = 0; i < n; i++)
        if (!vis[i])
            ans.push_back(arr[i]);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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
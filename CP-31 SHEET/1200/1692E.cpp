
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
ll query(int l, int r, vector<ll> &p)
{
    return p[r] - (l ? p[l - 1] : 0);
}
void solve()
{
    int n,s;
    cin>>n>>s;
    vector<ll> a(n),p(n);
    forn(i, n)
    {
        cin >> a[i];
        p[i] = a[i];
        if (i)
            p[i] += p[i - 1];
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        int l = i, r = n - 1, pos = -1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (query(i, mid, p) <= s)
            {
                pos = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (pos == -1 || query(i, pos, p) != s)
            continue;
        ans = min(ans, n - (pos - i + 1));
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;
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
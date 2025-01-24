
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

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    forn(i,n)cin>>arr[i];

    vector<int> pos(k+1,0);
    map<int, vector<int>> ans;

    // Populate the map
    for (int i = 0; i < n; i++) {
        int dist = i - pos[arr[i]];
        if (!ans[arr[i]].empty()) ans[arr[i]].pop_back();
        ans[arr[i]].push_back(dist);       // Distance from start
        ans[arr[i]].push_back(n - i - 1); // Distance from end
        pos[arr[i]] = i + 1;              // Update position
    }

    int res = n;
    for (int i = 1; i <= k; i++) {
        if (ans.find(i) == ans.end()) continue; // Skip unused indices

        sort(ans[i].rbegin(), ans[i].rend());
        if (ans[i].size() > 1) {
            res = min(res, max(ans[i][0] / 2, ans[i][1]));
        } else {
            res = min(res, ans[i][0] / 2);
        }
    }
    cout<<res<<endl;
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
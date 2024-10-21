
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
bool possible(int numQueries, vector<pair<ll, ll>> &seg, vector<ll> &queries, int n, int m)
{
    vector<int> arr(n);
    for(int i=0;i<numQueries;i++){
        arr[queries[i]] = 1;
    }
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+arr[i];
    }
    // go through all seg
    for(int i=0;i<m;i++){
        int l = seg[i].first;
        int r = seg[i].second;
        int segSize = r-l+1;
        int numOnes = prefix[r]-(l>0?prefix[l-1]:0);
        if(numOnes>segSize/2) return true;
    }
    return false;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> seg(m);
    for (int i = 0; i < m; i++)
    {
        cin >> seg[i].first >> seg[i].second;
        seg[i].first--;
        seg[i].second--;
    }
    ll q;
    cin >> q;
    vector<ll> queries(q);
    for (auto &i : queries)
    {
        cin >> i;
        i--;
    }
    int start = 1, end = q;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (possible(mid, seg, queries, n, m))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout<<ans<<endl;
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
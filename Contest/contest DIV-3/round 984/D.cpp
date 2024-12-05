
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
    ll n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    int left = 0, right = m - 1, top = 0, btm = n - 1;
    while (top <= btm && left <= right)
    {
        vector<int> curr;
        for (int j = left; j <= right; j++)
        {
            curr.pb(arr[top][j] - '0');
        }
        top++;
        for (int i = top; i <= btm; i++)
        {
            curr.push_back(arr[i][right] - '0');
        }
        right--;
        if (top <= btm)
        {
            for (int j = right; j >= left; j--)
            {
                curr.pb(arr[btm][j] - '0');
            }
            btm--;
        }
        if (left <= right)
        {
            for (int i = btm; i >= top; i--)
            {
                curr.pb(arr[i][left] - '0');
            }
            left++;
        }
        // for(auto ele:curr)cout<<ele<<" ";
        // cout<<endl;
        int size = curr.size();
        for (int i = 0; i < size; i++)
        {
            if (curr[i % size] == 1 && curr[(i + 1) % size] == 5 &&
                curr[(i + 2) % size] == 4 && curr[(i + 3) % size] == 3)
            {
                ans++;
            }
        }
        curr.clear();
    }
    cout << ans << endl;
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
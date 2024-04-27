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
/*
4
1 2 3 4
// lets see the number of operations
1 2 3 4  1 2 3 4 - 1
1 1 3 4  2 2 3 4 - 1
1 1 3 4  1 1 3 4  2 2 3 4 - 1
1 1 1 1  3 4 3 4  2 2 3 4 - 2  bcz 2 one swapped
total operations == 5
3 diff = 3+(3-1) = 5
3 diff = (n-max(count))*2-1

ex-2
6
0 1 3 3 7 0
0 0 1 3 3 7
4+3distinct
// lets find no of operations
0 1 3 3 7 0   0 1 3 3 7 0 - 1
0 0 0 3 7 0   1 1 3 3 7 3 - 2
0 0 0 3 7 0   0 0 0 3 7 0  1 1 3 3 7 3 - 1
0 0 0 0 0 0   3 7 0 3 7 0  1 1 3 3 7 3 - 2
total= 6
4 non zero is 4+(4-2)


ex-3
5
2 5 7 6 3
// lets find the number of operations
2 5 7 6 3   2 5 7 6 3 - 1
2 2 7 6 3   5 5 7 6 3 - 1
2 2 7 6 3   2 2 7 6 3  5 5 7 6 3  - 1
2 2 2 2 3   7 6 7 6 3  5 5 7 6 3 - 2
2 2 2 2 3   2 2 2 2 3  7 6 7 6 3  5 5 7 6 3 - 1
2 2 2 2 2   3 2 2 2 3  7 6 7 6 3  5 5 7 6 3 - 1
total = 7
res = totalDiff + swaps
4 diff = 4 + (4 diff - 1 ele)= 7

2
-1 1
//lets se
-1 1   -1 1
-1 -1

total=2
n=2 maxc=1
n-maxc*2-1 = (2-1)*2-1
*/
void solve()
{
    int n,x;
    cin >> n;
    map<int, int> mp;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mp[x]++;
        maxi = max(maxi, mp[x]);
    }
    if (maxi == n)
    {
        cout << 0 << endl;
    }
    else
    {
        int count = 1;
        while (maxi <= n)
        {
            if (maxi + maxi >= n)
            {
                count += (n - maxi);
                break;
            }
            count += maxi;
            maxi = maxi * 2;
            count++;
        }
        cout << count << endl;
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
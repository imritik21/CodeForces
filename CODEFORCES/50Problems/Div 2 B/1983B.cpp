
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
int rowSum(vector<int> arr1, int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
        sum += arr1[i];
    return sum;
}
int colSum(vector<vector<int>> arr, int i, int n)
{
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += arr[j][i];
    }
    return sum;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> arr1, arr2;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr1.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr2.push_back(s);
    }
    int row1[m]={0};
    int row2[m]={0};
    int col1[n]={0};
    int col2[n]={0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            row1[j] += (int)(arr1[i][j] - '0');
            row1[j] %= 3;
            row2[j] += (int)(arr2[i][j] - '0');
            row2[j] %= 3;
            col1[i] += (int)(arr1[i][j] - '0');
            col1[i] %= 3;
            col2[i] += (int)(arr2[i][j] - '0');
            col2[i] %= 3;
        }
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        flag &= (col1[i] == col2[i]);
    }
    for (int i = 0; i < m; i++)
    {
        flag &= (row2[i] == row1[i]);
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
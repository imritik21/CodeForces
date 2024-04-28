
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
// edge case
// row==1 && b!=1 || row!=1 && b==1 --> NO
// any row must now contain same color

void solve()
{
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    int cntB=0,cntW=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]=='B') cntB++;
            else cntW++;
        }
    }
    if(cntB==(n*m)|| cntW==(n*m)){
        cout<<"YES"<<endl;
        return;
    }
    if (n == 1 && m == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if ((n == 1 && m != 1) || (n != 1 && m == 1))
    {
        cout << "NO" << endl;
        return;
    }
    cntB=0,cntW=0;
    bool flag = false; // ARRAY KE 1ST AND LAST ROW ME ELE DIFF HONA CHIAYE
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + 1 < m; j++)
        {
            if(arr[i][j]=='B') cntB++;
            else cntW++;
            if ((arr[i][j] == 'B' && arr[i+n-1][j] == 'W' && cntB!=0 && cntW!=0)|| (arr[i][j] == 'W' && arr[i+n-1][j] == 'B'&& cntB!=0 && cntW!=0) ) 
            {
                flag = true;
                break;
            }
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
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
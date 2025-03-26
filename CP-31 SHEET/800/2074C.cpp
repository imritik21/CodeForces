
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
int findMSB(int n)
{
    if (n == 0)
        return 0; // MSB of 0 is 0

    int msb = 0;
    while (n > 1)
    {
        n >>= 1; // Right shift until only the MSB remains
        msb++;
    }
    return (1 << msb); // Return 2^msb (actual value of MSB bit)
}
#define msb(mask) (63 - __builtin_clzll(mask))
void solve()
{
    //  8 - 1000
    int n;
    cin>>n;
    int cntBit = __builtin_popcount(n);
    int req = log2(n);
    // cout<<cntBit<<" "<<req<<endl;
    // if (cntBit == 1)
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    // if(cntBit==req){
    //     cout<<-1<<endl;
    //     return;
    // }
    /*
    int x;
    cin>>x;
    int m = msb(x);
    int y = (1<<m)-1;
    int z = x^y;
    if(x+y > z && y+z > x && x+z > y){
        cout<<y<<nl;
    }
    else{
        cout<<-1<<nl;
    }
    */
    int m = log2(n);
    // cout<<m<<" "<<req<<endl;
    int y = (1<<m)-1;
    // cout<<y<<endl;
    int z = n^y;// xor
    if(n+y>z && y+z>n && n+z>y){
        cout<<y<<endl;
    }
    else cout<<-1<<endl;
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
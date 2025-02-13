
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
#define all(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,int>> vec;
    vector<vector<ll>> arr(n,vector<ll>(m));
    for(int i=0;i<n;i++){
        ll curr=0;
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            curr+=arr[i][j];
        }
        vec.push_back({curr,i});
    }
    sort(all(vec));
    ll ans = 0;
    int x = n * m;
    for(int i=0;i<n;i++){
        int idx = vec[i].second;
        for(int j=0;j<m;j++){
            ans+=(arr[idx][j]*x);
            x--;
        }
        // cout<<idx<<" ";
        // cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
    // cout<<endl;
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

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
ll calcLessThanX(vector<ll>& arr, ll x) {
    ll n = arr.size();
    ll s = accumulate(arr.begin(), arr.end(), 0LL);
    ll j = 0, ans = 0;

    for (ll i = n - 1; i >= 0; i--) {
        while (j < n && s - arr[i] - arr[j] >= x) {
            j++;
        }
        ans += (n - j);
    }

    for (ll i = 0; i < n; i++) {
        if (s - arr[i] - arr[i] < x) {
            ans--;
        }
    }

    return ans / 2; 
}
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> arr(n);
    ll sum = 0;
    forn(i, n)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    
    sort(all(arr));
    ll cnt = calcLessThanX(arr,y+1)-calcLessThanX(arr,x);
    cout << cnt << endl;
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
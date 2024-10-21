
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
pair<ll,ll> intersection(pair<ll,ll> a,pair<ll,ll> b){
    return make_pair(max(a.first,b.first),min(a.second,b.second));
}
bool possible(ll mid, vector<pair<ll, ll>> &arr)
{
    int n = arr.size();
    pair<ll,ll> currRange = {0,0};
    for(int i=0;i<n;i++){
        currRange = {currRange.first-mid,currRange.second+mid};
        pair<ll,ll> destRange = arr[i];
        pair<ll,ll> finnalRange = intersection(currRange,destRange);
        // for pointts (x1,y1) and (x2,y2)
        // intersection is max(x1,x2),min(y1,y1) 
        // and then comp A<=B where A=max(X1,x2)
        // [1,8] [5,6]
        // [5,6] --> [2,5]   max of left and min of right
        if(finnalRange.first<=finnalRange.second){
            currRange=finnalRange;
        }
        else{
            return false;
        }
    }
    return true;
}
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    ll maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        maxi = max(maxi, max(x, y));
        arr.pb({x, y});
    }
    ll lb = 0, ub = maxi;
    ll ans = 1e18;
    while (lb <= ub)
    {
        ll mid = lb + (ub - lb) / 2;
        // cout << lb << " " << ub << " " << mid << endl;
        if (possible(mid, arr))
        {
            ans = mid;
            ub = mid - 1;
            // cout << "ans " << ans << endl;
        }
        else
        {
            lb = mid + 1;
        }
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
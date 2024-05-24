
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

ll secondSmallest(vector<ll> nums)
{
    // int min_ele = INT_MAX;
    // int n = nums.size();
    // for (int i = 0; i < n; i++)
    // {
    //     int x = nums[i];
    //     min_ele = min(min_ele, x);
    // }
    // int sec_ele = INT_MAX;
    // for (int i = 0; i < n; i++)
    // {
    //     if (min_ele == nums[i])
    //         continue;
    //     if (nums[i] < sec_ele)
    //         sec_ele = nums[i];
    // }
    // return sec_ele;
    sort(nums.begin(),nums.end());
    ll sec_ele = nums[1];
    return sec_ele;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> secMin;
    ll M = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ll m;
        cin >> m;
        vector<ll> arr(m);
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
            M = min(M, arr[i]);
        }
        // find its sec mini
        ll mini2 = secondSmallest(arr);
        secMin.push_back(mini2);
    }
    // now 
    ll K=0; // sum of sec min ele
    for(int i=0;i<secMin.size();i++){
        K+=secMin[i];
    }
    ll res = M+K;
    ll ans=INT_MIN;
    for(int i=0;i<secMin.size();i++){
        ans=max(ans,(res-secMin[i]));
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
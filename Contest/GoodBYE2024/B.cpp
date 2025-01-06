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
    ll n;
    cin >> n;
    vector<pair<int, int>> p(n);
    map<pair<int, int>, int> mp;
    int max_index=-1;
    forn(i, n)
    {
        cin >> p[i].first >> p[i].second;
        if (p[i].first == p[i].second)
        {
            mp[{p[i].first, p[i].second}]++;
        }
            max_index=max(max_index,p[i].second);
    }
    vector<int> pref(max_index+1, 0);
    pref[0] = 0;
    for (int i = 0; i <= max_index; i++)
    { 
        if (i > 0)
        {
            pref[i] = pref[i - 1]; 
        }
        else
        {
            pref[i] = 0; 
        }
 
        if (mp[{i, i}] != 0)
        {
            pref[i] += 1; 
        }
    }
    // for (auto ele : pref)
    //     cout << ele << " ";
    // cout << endl;
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++)
    {
        if (mp[{p[i].first, p[i].second}] == 1)
        {
            ans[i] = 1;
            continue;
        }
        if (mp[{p[i].first, p[i].second}] > 1)
        {
            ans[i] = 0;
            continue;
        }
        // i ony nee to
        bool flag = false;
        // cout<<p[i].first<<" "<<p[i].second<<endl;
        // 1 1e5-1
        //
        if (mp[{p[i].first, p[i].first}] == 0 || mp[{p[i].second, p[i].second}] == 0)
        {
            ans[i] = 1;
            continue;
        }
 
        ll ele = p[i].second-p[i].first+1;
        ll exist = pref[p[i].second]-pref[p[i].first]+1;
        if(exist<ele){
            flag=true;
        }
        if (flag)
        {
            ans[i] = 1;
        }
        else
            ans[i] = 0;
    }
    forn(i, n) cout << ans[i];
    cout << endl;
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
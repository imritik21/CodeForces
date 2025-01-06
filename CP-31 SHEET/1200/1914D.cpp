
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
vector<int> getBest(vector<int>&arr){
    vector<int> indices = {-1,-1,-1};
    for (int i = 0; i < arr.size(); i++) {
        if (indices[0] == -1 || arr[i] > arr[indices[0]]) {
            indices[2] = indices[1];
            indices[1] = indices[0];
            indices[0] = i;
        } else if (indices[1] == -1 || arr[i] > arr[indices[1]]) {
            indices[2] = indices[1];
            indices[1] = i;
        } else if (indices[2] == -1 || arr[i] > arr[indices[2]]) {
            indices[2] = i;
        }
    }
    return indices;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    forn(i, n) cin >> c[i];
    // find maxof all ele first with idx
    // 16 17 18
    // 14 16 19
    // 10 11 20
    vector<int> best_a = getBest(a);
    vector<int> best_b = getBest(b);
    vector<int> best_c = getBest(c);

    int ans=0;
    for(auto x:best_a){
        for(auto y:best_b){
            for(auto z:best_c){
                if(x!=y && y!=z && x!=z){
                    ans=max(ans,a[x]+b[y]+c[z]);
                }
            }
        }
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
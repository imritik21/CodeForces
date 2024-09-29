
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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> pos(31, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     ll num = arr[i];
    //     for (int bit = 30; bit >= 0; bit--)
    //     {
    //         int mask = 1 << bit;
    //         if ((num & mask) != 0)
    //         {
    //             pos[bit]++;
    //         }
    //     }
    // }
    for(int i=30;i>=0;i--){
        int temp=0;
        for(int j=0;j<n;j++){
            if(((arr[j]&(1<<i))>0)){
                temp++;
            }
        }
        pos[i]=n-temp;
    }
    // for (int i = 0; i <= 30; i++)
    // {
    //     pos[i] = (n - pos[i]);
    // }
    // find min in pos and traverse to that ele whose ith bit 
    // not set and set it
    // k=1e9 n=1e5
    // reverse(all(pos));
    // for(auto ele:pos)cout<<ele<<" ";
    int ans=0;
    for(int i=30;i>=0;i--){
        if(pos[i]<=k){
            k-=pos[i];
            ans|=(1<<i);
        }
        // if(k==0)break;
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
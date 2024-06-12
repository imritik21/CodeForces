
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
    ll h;
    int n;
    cin>>h>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    vector<int> cool(n,0);
    ll tot_damage=0;
    ll turn=0;

    while(h>0){
        tot_damage=0;
        for(int i=0;i<n;i++){
            if(cool[i]==0){
                tot_damage+=a[i];
                cool[i]=b[i];
            }
        }
        if(tot_damage > 0){
            h-=tot_damage;
        }
        else{
            int mini = INT_MAX;
            for(int i=0;i<n;i++){
                if(cool[i]>0){
                    mini=min(mini,cool[i]);
                }
            }
            for(int i=0;i<n;i++){
                if(cool[i]>0){
                    cool[i]=max(0,cool[i]-mini);
                }
            }
            turn+=mini;
            continue;
        }
        for(int i=0;i<n;i++){
            if(cool[i]>0){
                cool[i]--;
            }
        }
        turn++;
    }
    cout<<turn<<endl;
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
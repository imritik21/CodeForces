
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
bool possible(ll x,vector<ll>&arr,ll n){
    ll sum = arr[0]+arr[1]+arr[2];
    ll k = x/3;
    int rem = x%3;
    ll left=0;
    if(rem==1){
        left+=arr[0];
    }
    else if(rem==2){
        left+=arr[0];
        left+=arr[1];
    }
    if((k*sum)+left>=n){
        return true;
    }
    else return false;
}
void solve()
{
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<ll> arr = {a,b,c};
    ll lb=1,ub=1e9+7;
    ll ans=0;
    while(lb<=ub){
        ll mid = (lb+ub)/2;
        if(possible(mid,arr,n)){
            ans=mid;
            ub=mid-1;
        }
        else{
            lb=mid+1;
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
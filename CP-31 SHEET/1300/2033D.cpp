
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
    cin>>n;
    vector<ll> arr(n+1);
    for(int i=1;i<=n;i++)cin>>arr[i];
    vector<ll> prefix(n+1,0);
    prefix[0]=arr[0];
    // 2 1 -3 2 1
    // 2 3 0 2 3
    
    // 2 1 -3 -5 5
    // 2 3 0 -5 0

    // 12 -4 4 43 -3 -5 8
    // 12 8 12 55 52 47 55

    // 0 -4 0 3 0 1
    // 0 -4 -4 -1 -1 0
    map<ll,int> mp;
    // for(int i=0;i<n;i++)cout<<prefix[i]<<" ";
    int lst[n+1];
    mp[0]=0;
    for(int i=1;i<n+1;i++){
        prefix[i]=prefix[i-1]+arr[i];
        if(mp.find(prefix[i])==mp.end()){
            lst[i]=-1;
        }
        else{
            lst[i]=mp[prefix[i]];
        }
        mp[prefix[i]]=i;
    }
    int dp[n+1];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i],dp[i-1]);
        if(lst[i]!=-1){
            dp[i]=max(dp[i],dp[lst[i]]+1);
        }
    }
    cout<<*max_element(dp,dp+n+1)<<endl;
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
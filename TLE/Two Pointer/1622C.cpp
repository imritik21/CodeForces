
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
bool possible(ll x,vector<ll>&arr,ll k,ll sum){
    if(sum-x<=k)return true;
    for(int i=arr.size()-1;i>=max(1LL,(int)arr.size()-x);i--){
        sum-=arr[i];// curr ele remove
        ll opLeft = x - (arr.size()-i);
        ll temp = sum - arr[0] + (arr.size()-i+1)*(arr[0]-opLeft);
        if(temp<=k)return true;
    }
    return false;
}
void solve()
{
    // its better to always perform op1 and rest of op2
    // so lets assume we performed m op1  ans = sum-m
    // similarly m-1 op1  ans = sum - a1 - an-1 + 2*(a1-m)
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(auto &i:arr)cin>>i;
    sort(all(arr));
    ll sum=0;
    for(int i=0;i<n;i++)sum+=arr[i];
    ll lb=0,ub=1e15,ans=1e18;
    while(lb<=ub){
        ll mid =(ub+lb)/2;
        if(possible(mid,arr,k,sum)){
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
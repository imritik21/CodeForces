
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
    vector<ll> arr(n);
    forn(i,n)cin>>arr[i];
    sort(all(arr));
    // 2  5 10 31 62 310 401 802 2005 4010 12431 24862 62155 
    //  2*62155 = 124310

    // bool flag = true;
    ll num = arr[0]*arr[n-1];
    // lets find and store the factors of num 
    vector<ll> factors;
    for(ll i=2;i*1LL*i<=num;i++){
        if(num%i==0){
            // if((num/i)==i){
            //     factors.pb(i);
            // }
            // else{
            //     factors.push_back(i);
            //     factors.pb(num/i);
            // }
            factors.push_back(i);
            if(i != num/i) factors.push_back(num/i);
        }
    }
    sort(all(factors));
    // for(auto ele: factors) cout<<ele<<" ";
    // cout<<endl;
    if(factors==arr)cout<<num<<endl;
    else cout<<-1<<endl;
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
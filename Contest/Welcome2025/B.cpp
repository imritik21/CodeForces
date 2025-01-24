
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
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    map<int,int> mp;
    forn(i,n){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    if(k==0){
        cout<<mp.size()<<endl;
        return;
    }
    if(k>=n){
        cout<<1<<endl;
        return;
    }
    // now k will always be less than n
    vector<pair<int,int>> store;
    for(auto &ele:mp){
        store.push_back({ele.second,ele.first});
    }
    sort(all(store));
    int cnt=mp.size();
    for(int i=0;i<store.size();i++){
        int curr = store[i].first;
        if(curr<=k){
            k-=curr;
            cnt--;
        }
        else{
            break;
        }
    }
    cout<<cnt<<endl;
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

// 11 4
// 1 1 2 2 3 3 3 3 4 4 4
// --
// 3 3 3 3 3 3 3 3 4 4 4
// 1 1 2 2 4 4 4 3 3 3 3
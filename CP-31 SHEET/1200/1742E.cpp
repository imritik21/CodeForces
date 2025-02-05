
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
ll binSearch(vector<ll>&arr,ll ele){
    ll lb = 0 , ub = arr.size()-1;
    ll ans=-1;
    while(lb<=ub){
        ll mid = (lb+ub)/2;
        if(arr[mid]>ele){
            ub=mid-1;   
        }
        else{
            ans=mid;
            lb=mid+1;
        }
    }
    return ans;
}
void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> prefix;
    prefix.pb(0);
    vector<int> prefmax;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        prefix.push_back(prefix.back()+x);
        if(i==0) prefmax.push_back(x);
        else prefmax.push_back(max(prefmax.back(),x));
    }
    // for(auto& ele:prefix)cout<<ele<<" ";
    // cout<<endl;
    // for (auto &ele : prefmax)
    //     cout << ele << " ";
    // cout << endl;
    while(q--){
        ll step;
        cin>>step;
        int idx = upper_bound(all(prefmax), step)-prefmax.begin();
        cout<<prefix[idx]<<" ";
    }
    cout<<endl;
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
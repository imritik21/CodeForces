
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
    vector<ll> a(n),b(n);
    forn(i,n)cin>>a[i];
    forn(i,n)cin>>b[i];
    vector<pair<pair<int,int>,int>> vec;
    for(int i=0;i<n;i++){
        if(b[i]>=a[i]){
            vec.push_back({{a[i],b[i]},abs(a[i]-b[i])});
        }
    }
    if(vec.size()==0){
        cout<<0<<endl;
        return;
    }
    vector<pair<pair<int, int>, int>> req;
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            req.push_back({{a[i],b[i]},abs(a[i]-b[i])});
        }
    }
    sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
         {
             return a.second < b.second;
         });
    sort(req.begin(), req.end(), [](const auto &a, const auto &b)
         {
             return a.second < b.second; 
         });
    // for(auto& it:req){
    //     cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
    // }
    // cout<<endl;
    // for(auto& it:vec){
    //     cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
    // }
    int i=0,j=0;
    ll ans=0;
    ll no=0;
    vector<int> vis(vec.size(),0);
    while(i<req.size() && j<vec.size()){
        // cout<<req[i].second<<" "<<vec[j].second<<endl;
        if(req[i].second<=vec[j].second){
            // cout<<"YES"<<endl;
            i++;
            vis[j] = 1;
            j++;
            ans++;
        }
        else{
            j++;
        }
    }
    for(int k=0;k<vec.size();k++){
        if(vis[k]==0)no++;
    }
    // ans+=(vec.size()-j)/2;
    cout<<ans+(no/2)<<endl;
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
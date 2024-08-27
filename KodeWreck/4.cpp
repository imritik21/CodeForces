
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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> arr1(n);
    vector<ll> arr2(m);
    for(int i=0;i<n;i++)cin>>arr1[i];
    for(int i=0;i<m;i++)cin>>arr2[i];
    sort(all(arr1));
    sort(all(arr2));
    unordered_map<ll,int> mp1;
    unordered_map<ll,int> mp2;
    for(auto ele:arr1)mp1[ele]++;
    for(auto ele:arr2)mp2[ele]++;
    ll mini=INT_MAX;
    ll maxi=*max_element(all(arr2));
    ll minele=*min_element(all(arr2));
    // cout<<maxi<<" "<<minele;
    ll min1= *min_element(all(arr1));
    if(k<min1 && k<minele && k>){
        cout<<min1+minele<<endl;
        return;
    }
    else if(k==min1 && k==minele){
        cout<<(min1+minele)-k<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(mp2.find(abs(k-arr1[i]))!=mp2.end()){
            cout<<0<<endl;
            return;
        }
    }
    // cout<<mini<<endl;
    
     if(k>min1 && k<minele){
        for(int i=0;i<n;i++){
            mini=min(mini,abs(minele+min1)-k);
        }
        // cout<<mini<<endl;
    }
    for(int i=0;i<n;i++){
        ll num = abs(k-arr1[i]);
        ll lo=minele;
        ll hi=maxi;
        while(lo<=hi){
            ll mid = lo+(hi-lo)/2;
            if(mid<num){
                if(mp2[mid])mini=min(mini,abs(num-mid));
                lo=mid+1;
            }
            else{
                if(mp2[mid])mini=min(mini,abs(num-mid));
                hi=mid-1;
            }
        }
        // cout<<num<<" "<<mini<<endl;
    }
    cout<<mini<<endl;
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
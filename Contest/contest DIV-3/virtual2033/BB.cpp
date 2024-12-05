
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
bool possible(ll x,vector<ll>&arr){
    int n = arr.size();
    // bool f1=false,f2=false;
    
    // for(int i=0;i<n-1;i++){
    //     if(abs(arr[i]-arr[i+1])>x){
    //         return false;
    //     }
    // }
    // for(int i=0;i<n-2;i++){
    //     if(abs(arr[i]-arr[i+1])>=x){
    //         f1=true;
    //     }
    //     else{
    //         f1=false;
    //         break;
    //     }
    // }
    // for(int i=1;i<n-1;i++){
    //     if(abs(arr[i]-arr[i+1])>=x){
    //         f2=true;
    //     }
    //     else{
    //         f2=false;
    //         break;
    //     }
    // }
    // if(f1||f2){
    //     return true;
    // }
    // return true;
    vector<bool> f1(n+1,false);
    vector<bool> f2(n+1,false);
    f1[0]=true;
    f2[0]=false;
    for(int  i=0;i<n;i++){
        vector<bool> c0(n+1,false);
        vector<bool> c1(n+1,false);
        if(f1[i]){
            if(i+1<n && abs(arr[i+1]-arr[i])<=x){
                c0[i+2]=true;
            }
            if(x>=1){
                c1[i+1]=true;
            }
        }
        if(f2[i]){
            if(i+1<n && abs(arr[i+1]-arr[i])<=x){
                c1[i+2]=true;
            }
        }
        for(int j=0;j<=n;j++){
            if(c0[j])f1[j]=true;
            if(c1[j])f2[j]=true;
        }
    }
    return f1[n]||f2[n];
}
void solve()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n==2){
        cout<<abs(arr[0]-arr[1])<<endl;
        return;
    }
    ll ans=0;
    ll lb = 0,ub=1e18;
    while(lb<=ub){
        ll mid = lb + (ub-lb)/2;

        if(possible(mid,arr)){
            ans=mid;
            ub = mid-1;
        }
        else{
            lb = mid+1;
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
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

int main()
{
    fast_cin();
    ll n,a,b;
    cin>>n>>a>>b;
    ll x=-1,y;
    for(y=0;y<=1e7;y++){
        if((n-y*b)%a==0 && n-y*b >= 0){
            x=(n-y*b)/a;
            break;
        }
    }
    if(x==-1)cout<<"NO"<<endl;
    else cout<<"YES\n"<<x<<" "<<y<<'\n';


    // bool flag=false;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if((i*a+j*b)==n){
    //             cout<<"YES"<<endl;
    //             cout<<i<<" "<<j<<endl;
    //             flag=true;
    //             break;
    //         }
    //     }
    // }
    // if(!flag){
    //     cout<<"NO"<<endl;
    // }
    return 0;
}
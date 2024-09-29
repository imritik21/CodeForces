
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
    int n;
    cin>>n;
    // n is even
    // two case
    /// 1).  n/2 is even
    //      n can be [4,8,12..]
    //      eg= n=8
    //      10    11
    //     100   101
    //     110   111
    //    1000  1001
    if(n==3){
        cout<<"1 2 3"<<endl;
        return;
    }
    stack<int> even,odd;
    int f=2;
    for(int i=0;i<n/2;i++){
        even.push(f);
        odd.push(f+1);
        f+=2;
    }
    if((n/2)&1){
        int p = odd.top();
        p^=1;
        odd.pop();
        int q = 1LL<<20;
        p^=q;
        odd.top()^=q;
        odd.push(p);
    }
    for(int i=1;i<=n;i++){
        if((n&1)&&i==n){
            cout<<0<<" ";
        }
        else if(i&1){
            cout<<odd.top()<<" ";
            odd.pop();
        }
        else{
            cout<<even.top()<<" ";
            even.pop();
        }
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
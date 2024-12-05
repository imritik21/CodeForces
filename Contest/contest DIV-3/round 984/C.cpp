
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
string str;
ll n;
bool check(ll i){
    if(i<0) return false;
    if(i>=str.size()-3)return false;
    if(str[i]=='1'&&str[i+1]=='1'&&
      str[i+2]=='0' && str[i+3]=='0')return true;
      return false;
}
void solve()
{
    // string str;
    cin >> str;
    ll n = str.size();
    // bool flag = false;
    // if (n < 4)
    // {
    //     flag = true;
    // }
    //  111010
    //  111010
    //  111000  yes  5 0
    //  111100  yes  4 1
    //  111100  yes  5 0   q*n
    ll cnt=0;
    for (int i = 0; i < n; i++)
    {
        if(check(i)){
            cnt++;
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll idx, v;
        cin >> idx >> v;
        idx--;

        // if (flag)
        // {
        //     cout << "NO" << endl;
        // }
        // else{
            if(str[idx]!='0'+v){
                int prev = check(idx-3)||check(idx-2)||check(idx-1)||check(idx);
                str[idx] = '0'+v;
                int after = check(idx-3)||check(idx-2)||check(idx-1)||check(idx);
                cnt+=(after-prev);
            }
            cout<<(cnt?"YES\n":"NO\n");
        // }
    }
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
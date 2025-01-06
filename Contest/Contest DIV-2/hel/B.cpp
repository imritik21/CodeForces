
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

const int MOD = 1e9 + 7;

long long factorialMod(ll n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}
bool isDivisibleBy7(ll n) {
    if (n >= 7) {
        return true; 
    }

    long long factorial = 1; 
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    return factorial % 7 == 0;
}
void solve()
{
    ll n,d;
    cin>>n>>d;
    if(n>=7 && d%5!=0){
        cout<<"1 3 7 9 "<<endl;
        return;
    }
    else if(n>=7 && d%5==0){
        cout<<"1 3 5 7 9 "<<endl;
        return;
    }
    
    ll times = factorialMod(n);
    ll sum = d*times; 
    bool three=false,nine=false,seven=false,five=false;
    if(sum%9==0){
        three=true;
        nine=true;
    }
    if(sum%3==0){
        three=true;
    }
    if(d%5==0){
        five=true;
    }
    if(n==2 && d==7){
        seven=true;
    }
    if(n>=3){
        seven=true;
    }
    vector<int> ans;
    ans.push_back(1);
    if(three)ans.push_back(3);
    if(five)ans.push_back(5);
    if(seven)ans.push_back(7);
    if(nine)ans.push_back(9);
    sort(all(ans));
    for(auto ele:ans)cout<<ele<<" ";
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
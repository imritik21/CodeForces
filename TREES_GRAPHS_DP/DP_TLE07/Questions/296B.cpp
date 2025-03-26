
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
ll MOD = 1e9+7;
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
long long mod(long long x){
    return ((x%MOD+MOD)%MOD);
}
long long add(ll a,ll b){
    return mod(mod(a)+mod(b));
}
ll mul(ll a,ll b){
    return mod(mod(a) * mod(b));
}
int n;
string s,t;
int dp[100002][2][2];
int rec(int idx,bool one,bool two){
    if(idx==n){
        if(one && two){
            return 1;
        }
        else {
            return 0;
        }
    }
    if(dp[idx][one][two]!=-1){
        return dp[idx][one][two];
    }

    if(s[idx]!='?' && t[idx]!='?'){
        if(s[idx]>t[idx]){
            dp[idx][one][two] = rec(idx+1,true,two);
        }
        else if (s[idx] < t[idx]){
            dp[idx][one][two] = rec(idx + 1, one, true);
        }
        else
            dp[idx][one][two] = rec(idx + 1, one, two);
    }
    else{
        dp[idx][one][two]=0;
        if(s[idx]=='?' && t[idx]=='?'){
            dp[idx][one][two] = add(dp[idx][one][two], mul(10 ,(rec(idx + 1, one, two))));
            dp[idx][one][two] = add(dp[idx][one][two], mul(45, (rec(idx + 1, true, two))));
            dp[idx][one][two] = add(dp[idx][one][two], mul(45, (rec(idx + 1, one, true))));
        }
        else if(s[idx]=='?'){
            int v = 9-(t[idx]-'0');
            dp[idx][one][two] = add(dp[idx][one][two], mul(v, (rec(idx + 1, true, two))));
            v = (t[idx] - '0'); // to make two true
            dp[idx][one][two] = add(dp[idx][one][two], mul(v, (rec(idx + 1, one, true))));
            dp[idx][one][two] = add(dp[idx][one][two], mul(1, (rec(idx + 1, one, two))));
        }
        else if (t[idx] == '?')
        {
            int v = (s[idx] - '0'); // to make two true
            dp[idx][one][two] = add(dp[idx][one][two], mul(v, (rec(idx + 1, true, two))));
            v = 9 - (s[idx] - '0');
            dp[idx][one][two] = add(dp[idx][one][two], mul(v, (rec(idx + 1, one, true))));
            dp[idx][one][two] = add(dp[idx][one][two], mul(1, (rec(idx + 1, one, two))));
        }
    }
    return dp[idx][one][two];
}
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            for (int k = 0; k < 2; k++){
                dp[i][j][k]=-1;
            }
        }
    }
    cin>>s>>t;
    cout<<rec(0,false,false)<<endl;
}
int main()
{
    fast_cin();
    ll t=1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
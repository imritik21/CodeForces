
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
    string s;cin>>s;
    int n = s.size();
    if(n==1 && (s[0]=='0')){
        cout<<0<<endl;
        return;
    }
    if(n==1 && (s[0]=='1')){
        cout<<1<<endl;
        return;
    }
    //    1 0 1       0 1 0    0 1 0 1     1 0 0 1    1 0 0 1 1 0 0 1
    //    1 1 0       0 0 1    1 0 1 0     1 1 0 0    1 1 0 0 1 1 0 0
    //    0 1 1       1 0 0    0 1 0 1     0 1 1 0    0 1 1 0 0 1 1 0
    //                                                0 0 1 1 0 0 1 1
    //                                                1 0 0 1 1 0 0 1
    //                                                1 1 0 0 1 1 0 0
    // n= 2 ya to max(len,(n-1)*2,(n-2)*3,(n-3)*4)
    ll maxi = INT_MIN;         // 111064  211016
    ll maxLen = 0;// 110 - 2  
    ll cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1')cnt++;
        else{
            maxLen=max(maxLen,cnt);
            cnt=0;
        }
    }
    // 11011101
    // cout<<maxLen<<endl;
    cnt=0;
    s+=s;
    // cout<<s<<endl;
    for(int i=1;i<s.size();i++){
        if(s[i]=='1')cnt++;
        else{
            maxLen=max(maxLen,cnt);
            cnt=0;
        }
    }
    maxLen=max(maxLen,cnt);
    if(maxLen==n){
        cout<<pow(n,2)<<endl;
        return;
    }
    for(ll i=1;i<n;i++){
        maxi=max(maxi,(maxLen-i)*(i+1LL));
    }
    maxi=max(maxi,maxLen);
    // cout<<maxLen<<endl;
    cout<<maxi<<endl;
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
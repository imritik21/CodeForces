
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
    string str;
    cin>>str;
    int n=str.length();
    int cnt1=0,cnt0=0;
    for(int i=0;i<n;i++){
        if(str[i]=='0') cnt0++;
        else cnt1++;
    }
    if(cnt0 == 0 || cnt1 ==0){
        cout<<"NET"<<endl;
        return;
    }
    if(cnt0 ==1 || cnt1 ==1){
        cout<<"DA"<<endl;
        return;
    }
    // both odd
    if(cnt1%2 !=0 && cnt0%2 !=0){
        cout<<"DA"<<endl;
        return;
    }
    // both even
    if(cnt1%2 ==0 && cnt0%2 ==0){
        cout<<"NET"<<endl;
        return;
    }
    // evn odd
    if(cnt0%2==0 && cnt1%2 !=0){
        if(cnt0<cnt1){
            cout<<"NET"<<endl;
        }
        else{
            cout<<"DA"<<endl;
        }
        return;
    }
    // odd even
    if(cnt0%2!=0 && cnt1%2 ==0){
        if(cnt0<cnt1){
            cout<<"DA"<<endl;
        }
        else{
            cout<<"NET"<<endl;
        }
        return;
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
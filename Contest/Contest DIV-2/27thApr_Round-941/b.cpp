
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
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    int cntB=0,cntW=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    // we need  to find that is either black/white is present in all 
    // four starting rows and colmn or not 
    // chechk for white if there exits a single of them in each 4 then its YES
    for(int j=0;j<m;j++){
        if(arr[0][j]=='W'){
            cntW++;
            break;
        } 
    }
    for(int j=0;j<m;j++){
        if(arr[0][j]=='B'){
            cntB++;
            break;
        } 
    }
    for(int j=0;j<m;j++){
        if(arr[n-1][j]=='W'){
            cntW++;
            break;
        }
    }
    for(int j=0;j<m;j++){
        if(arr[n-1][j]=='B'){
            cntB++;
            break;
        }
    }
    for(int j=0;j<n;j++){
        if(arr[j][0]=='W'){
            cntW++;
            break;
        }
    }
    for(int j=0;j<n;j++){
        if(arr[j][0]=='B'){
            cntB++;
            break;
        }
    }
    for(int j=0;j<n;j++){
        if(arr[j][m-1]=='W'){
            cntW++;
            break;
        }
    }
    for(int j=0;j<n;j++){
        if(arr[j][m-1]=='B'){
            cntB++;
            break;
        }
    }
    if(cntB>=4 || cntW>=4){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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
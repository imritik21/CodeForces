
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
    vector<vector<char>> arr(8,vector<char>(8));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>arr[i][j];
        }
    }
    bool flagR=false,flagB=false;
    for(int i=0;i<8;i++){ // RRRRRRRR
        int cnt=0;
        for(int j=0;j<8;j++){
            if(arr[i][j]=='R'){
                cnt++;
            }
        }
        if(cnt==8){
            flagR=true;
            break;
        }
        // if(flagR==false)break;
    }

    for(int j=0;j<8;j++){
        int cnt=0;
        for(int i=0;i<8;i++){
            if(arr[i][j]=='B'){
                cnt++;
            }
        }
        if (cnt == 8)
        {
            flagB = true;
            break;
        }
    }
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         cout<< arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(flagB)cout<<"B"<<endl;
    if(flagR)cout<<"R"<<endl;
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
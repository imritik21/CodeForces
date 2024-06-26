
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
    ll n,m;
    cin>>n>>m;
    ll arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            while (true) {
                bool isPeak = true;
                int maxi = INT_MIN;
                if (j > 0 && arr[i][j] <= arr[i][j-1]) {
                    isPeak = false;
                }
                else if(j>0){
                    int num1 = arr[i][j-1];
                    maxi=max(maxi,num1);
                }
                if (j < m-1 && arr[i][j] <= arr[i][j+1]) {
                    isPeak = false;
                }
                else if(j<m-1){
                    int num2=arr[i][j+1];
                    maxi=max(maxi,num2);
                }
                if (i > 0 && arr[i][j] <= arr[i-1][j]) {
                    isPeak = false;
                }
                else if(i>0){
                    int num3=arr[i-1][j];
                    maxi=max(maxi,num3);
                }
                if (i < n-1 && arr[i][j] <= arr[i+1][j]) {
                    isPeak = false;
                }
                else if(i<n-1){
                    int num4 = arr[i+1][j];
                    maxi=max(maxi,num4);
                }

                if (!isPeak) {
                    break;
                }
                arr[i][j]=maxi;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
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
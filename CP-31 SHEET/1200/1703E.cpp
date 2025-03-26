
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
    vector<vector<char>> arr(n+1,vector<char>(n+1));
    // vector<vector<int>> vis(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    // if()
    int ans=0;
    int i=1,j=1;
    int a=1,b=n-1;
    int x;
    if(n%2!=0){
        x=(n+1)/2;
    }
    else x=n/2;
    while(i<=x){
        // 
        for(int j=a;j<=b;j++)
        {
            int curr0 = 0, curr1 = 0;
            // 1,1
            if(arr[i][j]=='1')curr1++;
            else curr0++;
            int n_i = n+1-j;
            int n_j = i;
            if(arr[n_i][n_j]=='1')curr1++;
            else curr0++;
            int ni2 = n+1-n_j;
            int nj2 = n_i;
            if(arr[ni2][nj2]=='1')curr1++;
            else curr0++;
            int ni3 =n+1-nj2;
            int nj3 = ni2;
            if(arr[ni3][nj3]=='1')curr1++;
            else curr0++;
            // cout << i << " " << j << endl;
            // cout << n_i << " " << n_j << endl;
            // cout << ni2 << " " << nj2 << endl;
            // cout << ni3 << " " << nj3 << endl;
            // cout << endl;
            // cout << curr0 << " " << curr1 << endl;
            // cout << endl;
            ans += min(curr1, curr0);
        }
        // ans+=min(curr1,curr0);
        i++;
        a++;
        b--;
    }
    cout<<ans<<endl;
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
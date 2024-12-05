
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

// void solve()
// {
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     forn(i,n)cin>>arr[i];
//     if(n==1){
//         cout<<0<<endl;
//         return;
//     }
//     int idx;
//     if(n%2==0){
//         idx = n/2-1;
//     }
//     else idx = n/2;
//     int ele = arr[idx];
//     int cnt=0;
//     for(int i=idx+1;i<n;i++){
//         if(arr[i]<ele)cnt++;
//     }
//     for(int i=idx-1;i>=0;i--){
//         if(arr[i]>ele)cnt++;
//     }
//     cout<<cnt<<endl;
// }
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int,int> mp;
    forn(i, n) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int maxi = INT_MIN;
    for(auto it:mp){
        maxi=max(maxi,it.second);
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    int idx = (n % 2 == 0) ? (n / 2 - 1) : (n / 2);
    int ele = arr[idx];
    int idx2;
    if(n%2==0){
        idx2 = n/2;
    }
    int cnt = 0,cnt2=0;

    for (int i = idx + 1; i < n; i++) {
        if (arr[i] < ele) cnt++;
    }
    for (int i = idx - 1; i >= 0; i--) {
        if (arr[i] > ele) cnt++;
    }
    for (int i = idx2 + 1; i < n; i++) {
        if (arr[i] < ele) cnt2++;
    }
    for (int i = idx2 - 1; i >= 0; i--) {
        if (arr[i] > ele) cnt2++;
    }
    // if(n%2==0)cout<<min(cnt,min(n-maxi,cnt2))<<endl;
    // else 
    // cout << min(n-maxi,cnt) << endl;
    cout<<n-maxi<<endl;
    // cout<<min(cnt,cnt2)<<endl;
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
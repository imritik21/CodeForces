
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
//     ll n;cin>>n;
//     vector<ll> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<pair<int,int>> p(n);
//     vector<ll> prefix(n);
//     sort(all(arr));
//     prefix[0]=arr[0];
//     for(int i=1;i<n;i++){
//         prefix[i]=prefix[i-1]+arr[i];
//     }
//     p[n-1].first=arr[n-1];
//     p[n-1].second=n-1;
//     for(int i=n-2;i>=0;i--){
//         if(prefix[i]>=arr[i+1]){
//             p[i].first=arr[i];
//             p[i].second=p[i+1].second;
//         }
//         else{
//             p[i].first=arr[i];
//             p[i].second=i;
//         }
//     }
// }
void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<pair<ll, ll>> original(n);  // To store original value and index
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        original[i] = {arr[i], i};
    }
    
    sort(all(arr));
    vector<pair<ll, ll>> p(n);
    vector<ll> prefix(n);
    
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    
    p[n - 1].first = arr[n - 1];
    p[n - 1].second = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (prefix[i] >= arr[i + 1]) {
            p[i].first = arr[i];
            p[i].second = p[i + 1].second;
        } else {
            p[i].first = arr[i];
            p[i].second = i;
        }
    }
    
    // Map results back to original indices
    vector<ll> result(n);
    for (int i = 0; i < n; i++) {
        result[original[i].second] = p[lower_bound(all(arr), original[i].first) - arr.begin()].second;
    }
    
    // Print the second element of the pairs according to the initial array
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
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
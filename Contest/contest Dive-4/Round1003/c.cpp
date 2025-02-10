
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
    vector<int> arr(n), b(m);
    forn(i, n) cin >> arr[i];
    forn(i, m) cin >> b[i];
    sort(all(b));
    if (is_sorted(all(arr)))
    {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i + 1 < n; i++)
    {
        if (i == 0 && arr[i] > arr[i + 1])
        {
            // cout << "here " << i << endl;
            int lb = 0;
            int ub = m - 1;
            int ele = INT_MIN;
            while (lb <= ub)
            {
                int mid = (lb + ub) / 2;
                // cout << "mid ele req" << mid << " " << b[mid] << " " << b[mid] - arr[i] << endl;
                if (b[mid] - arr[i] >= INT_MIN && b[mid] - arr[i] <= arr[i + 1])
                {
                    // cout << "1st" << endl;
                    ele = b[mid] - arr[i];
                    break;
                }
                else if (b[mid] - arr[i] > arr[i + 1])
                {
                    // cout << "2nd" << endl;
                    ub = mid - 1;
                }
                else if (b[mid] - arr[i] < arr[i - 1])
                {
                    // cout << "3rd" << endl;
                    lb = mid + 1;
                }
            }
            if (ele != INT_MIN)
                arr[i] = ele;
        }
        if (i > 0 && i < n)
        {
            // cout << "here " << i << endl;
            int lb = 0;
            int ub = m - 1;
            int ele = INT_MIN;
            while (lb <= ub)
            {
                int mid = (lb + ub) / 2;
                // cout << "mid ele req" << mid << " " << b[mid] << " " << b[mid] - arr[i] << endl;
                if (b[mid] - arr[i] >= arr[i - 1] && b[mid] - arr[i] <= arr[i + 1])
                {
                    // cout << "1st" << endl;
                    ele = b[mid] - arr[i];
                    break;
                }
                else if (b[mid] - arr[i] > arr[i + 1])
                {
                    // cout << "2nd" << endl;
                    ub = mid - 1;
                }
                else if (b[mid] - arr[i] < arr[i - 1])
                {
                    // cout << "3rd" << endl;
                    lb = mid + 1;
                }
            }
            if (ele != INT_MIN)
                arr[i] = ele;
        }
    }
    // for(auto& ele:arr)cout<<ele<<" ";
    // cout<<endl;
    if (is_sorted(all(arr)))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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
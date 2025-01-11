
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
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b; // To prevent overflow
}
long long range_sum(long long l, long long r)
{
    if (l > r)
        return 0;
    return (l + r) * (r - l + 1) / 2;
}
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    // ele1 = n/x
    // ele2 = n/y
    // sum1 = find ele1 no. of largest  in P
    // sum2 = find ele2 No. of smallest in P
    // ans = sum2-sum1
    // common ele = if x*y<=n
    /*
    To calculate the number of purple indices, we need to notice that the condition "index is divisible by both x
    and y
    " is equivalent to "index is divisible by lcm(x,y)
    ", where lcm
     denotes the least common multiple. Therefore, the number of purple indices is ⌊nlcm(x,y)⌋

     Let R
 be the number of "red but not purple" indices, and let B
 be the number of "blue but not purple" indices. Then it is not difficult to see that the maximum score is (n+(n−1)+…+(n−(R−1))−(1+2+…+B)
.
    */
    ll lccm = lcm(x, y);

    ll plus = n / x - n / lccm;  // red but not purple
    ll minus = n / y - n / lccm; // blue but not purple

    ll sum1 = range_sum(n - plus + 1, n);
    ll sum2 = range_sum(1, minus);
    cout << sum1 - sum2 << endl;
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
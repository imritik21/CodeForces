
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
ll calc(const string& s, const vector<char>& ops) {
    vector<ll> term;
    ll curr = s[0] - '0';
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == '+') {
            term.push_back(curr);
            curr = s[i + 1] - '0';
        } else {
            curr *= s[i + 1] - '0';
        }
    }
    term.push_back(curr);
    ll res = 0;
    for (ll t : term) {
        res += t;
    }
    return res;
}

void find(const string& s, vector<char>& ops, int idx, long long& min_res) {
    if (idx == s.size()-1) {
        min_res = min(min_res, calc(s, ops));
        return;
    }
    ops[idx - 1] = '+';
    find(s, ops, idx + 1, min_res);
    ops[idx - 1] = '*';
    find(s, ops, idx + 1, min_res);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> ops(n - 1);
    ll min_res = LLONG_MAX;
    find(s, ops, 1, min_res);
    cout << min_res << endl;
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
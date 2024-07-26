#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = __gcd(ans, abs(a[i] - a[n - i - 1]));
    }
    cout << ans << '\n';
}
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
ll MOD = 998244353;

#define ln "\n"
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve() {
    ll n;
    cin >> n;

    
    ll sum1to3, sum1to2, sum2to3;

    cout << "? 1 3" << endl;
    fflush(stdout); 
    cin >> sum1to3;

    cout << "? 1 2" << endl;
    fflush(stdout);
    cin >> sum1to2;

    cout << "? 2 3" << endl;
    fflush(stdout);
    cin >> sum2to3;

    
    v64 arr(n + 1); 
    arr[1] = sum1to3 - sum2to3;
    arr[2] = sum1to2 - arr[1];
    arr[3] = sum2to3 - arr[2];

    for (int i = 4; i <= n; i++) {
        ll curr;
        cout << "? " << i - 1 << " " << i << endl;
        fflush(stdout);
        cin >> curr;

        arr[i] = curr - arr[i - 1];
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    fflush(stdout); 
}

int main() {
    fast_cin();
    ll t=1;
    for (int it = 1; it <= t; it++) {
        solve();
    }
    return 0;
}

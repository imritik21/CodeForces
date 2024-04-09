#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    
    ll l = 0, m = n - 1;
    ll i = 1;

    // Find the length of the repetitive pattern
    ll patternLength = 2 * n;
    while (i <= k && i < patternLength) {
        if (i % 2 != 0 && arr[l] != 0) {
            arr[l]--;
            if (arr[l] == 0)
                l++;
        } else if (i % 2 == 0 && arr[m] != 0) {
            arr[m]--;
            if (arr[m] == 0)
                m--;
        }
        i++;
    }

    // Calculate the number of zeros after the repetitive pattern
    ll zerosAfterPattern = 0;
    for (ll j = 0; j < n; j++) {
        if (arr[j] == 0)
            zerosAfterPattern++;
    }

    // Calculate the result
    ll totalZeros = zerosAfterPattern + (k - (patternLength - 1)) * (n / 2);
    cout << totalZeros << endl;
}

int main() {
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}

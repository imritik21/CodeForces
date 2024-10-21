#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (auto &it : arr) cin >> it;

    // Create pairs of (value, original_index)
    vector<pair<ll, ll>> p;
    for (int i = 0; i < n; i++) {
        p.push_back({arr[i], i});
    }
    
    // Sort by value (keeping track of original indices)
    sort(p.begin(), p.end());

    int l = 0, r = n - 1;
    bool possible = false;
    ll left = -1, right = -1;

    // Two pointer approach to find the pair with sum k
    while (l < r) {
        ll target = p[l].first + p[r].first;

        if (target == k) {
            left = p[l].second;  // Get original index from sorted pair
            right = p[r].second;  // Get original index from sorted pair
            possible = true;
            break;
        } else if (target > k) {
            r--;
        } else {
            l++;
        }
    }

    if (possible) {
        // Output the indices in 1-based indexing
        cout << left + 1 << " " << right + 1 << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

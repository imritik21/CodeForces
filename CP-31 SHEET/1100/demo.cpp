#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;cin>>tc;
    while(tc){
        solve();
    }
    return 0;
}

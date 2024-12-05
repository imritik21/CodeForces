#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> nums(n);
    unordered_map<int, int> x_count;
    set<pair<int, int>> unique_pairs;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        nums[i] = {x, y};
        x_count[x]++;
        unique_pairs.insert(nums[i]);
    }

    long long ans = 0;

    //  contributions based on x-coordinate frequency
    for (auto it = x_count.begin(); it != x_count.end(); ++it) {
        int x = it->first;
        int count = it->second;
        if (count == 2) {
            ans += n - 2;
        }
    }

    // Check neighbors for each unique pair
    for (auto it = unique_pairs.begin(); it != unique_pairs.end(); ++it) {
        int x = it->first;
        int y = it->second;
        if (unique_pairs.count({x - 1, y ^ 1}) && unique_pairs.count({x + 1, y ^ 1})) {
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

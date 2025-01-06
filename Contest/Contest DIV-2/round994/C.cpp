#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<long long>
#define vvi vector<vector<long long>>
#define all(x) (x).begin(), (x).end()
#define test(t) int t; cin >> t; while (t--)
#define print(arr) for (auto &o : (arr)) { cout << o << " "; } cout << endl;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;

    vi a(n, -1);
    vvi neighbors(n);

    // Initialize neighbors
    for (int i = 0; i < n; ++i) {
        neighbors[i].push_back((i + 1) % n);
        neighbors[i].push_back((i - 1 + n) % n);
    }
    neighbors[x].push_back(y);
    neighbors[y].push_back(x);

    // Function to calculate MEX of neighbors
    auto mex = [&](int idx) {
        set<int> neighbor_values;
        for (int neighbor : neighbors[idx]) {
            neighbor_values.insert(a[neighbor]);
        }
        int mex_val = 0;
        while (neighbor_values.count(mex_val)) {
            ++mex_val;
        }
        return mex_val;
    };

    // Check function
    auto check = [&](const vi &arr) {
        for (int i = 0; i < n; ++i) {
            if (mex(i) != arr[i]) {
                return false;
            }
        }
        return true;
    };

    // Populate the array
    if (n % 2 != 0) {
        int idx = x;
        a[idx++] = 2;
        for (int i = 1; i < n; ++i) {
            idx %= n;
            a[idx++] = (i % 2 == 0) ? 1 : 0;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            a[i] = (i % 2 == 0) ? 1 : 0;
        }
        if (a[x] == a[y]) {
            a[x] = 2;
        }
    }

    // Output the result
    print(a);
    assert(check(a));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test(t) solve();
    return 0;
}

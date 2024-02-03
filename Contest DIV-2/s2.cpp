#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        
        int n;
        cin >> n;

        int minn = LLONG_MIN;
        int maxx = LLONG_MIN;
        unordered_set<int> v;

        int a[n], b[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            if (a[i] == 1) {
                minn = max(minn, b[i]);
            } else if (a[i] == 2) {
                maxx = max(maxx, b[i]);
            } else {
                v.insert(b[i]);
            }
        }

        int count = 0;

        for (int val : v) {
            if (val >= minn && val <= maxx) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}

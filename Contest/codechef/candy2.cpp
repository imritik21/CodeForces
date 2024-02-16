#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        vector<int> a(N);

        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        vector<int> dp(N, 1);  // dp[i] represents the length of LIS ending at index i

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] > a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < N; i++) {
            count += (dp[i] > 1);  // Count only friends who receive at least one candy
        }

        cout << count << endl;
    }

    return 0;
}

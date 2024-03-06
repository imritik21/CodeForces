#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int tc;
    cin >> tc;
    while (tc--) {
        long long N, X;
        cin >> N >> X;
        long long space[N], rating[N];
        for (int i = 0; i < N; i++) {
            cin >> space[i] >> rating[i];
        }
        long long ans = INT_MIN;
        for (int i = 0; i < N; i++) {
            if (space[i] <= X) {
                ans = max(ans, rating[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

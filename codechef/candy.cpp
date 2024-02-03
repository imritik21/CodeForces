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

        vector<int> candies(N, 1);

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] > a[i]) {
                    candies[i] = max(candies[i], candies[j] + 1);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < N; i++) {
            count += (candies[i] > 1);  // Count only friends who receive at least one candy
        }

        cout << count << endl;
    }

    return 0;
}

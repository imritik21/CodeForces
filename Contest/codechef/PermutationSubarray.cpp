#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    vector<int> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + P[i];
    }

    vector<long long> count(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            int sum = prefix_sum[i] - prefix_sum[j];
            if (sum <= N) {
                count[sum]++;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << count[i] << " ";
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent / 2;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int N, K, B, R;
    cin >> N >> K >> B >> R;

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (j > 0) {
                dp[i][j] = (dp[i - 1][j - 1] * B + dp[i - 1][j + 1] * R) % MOD;
            } else {
                dp[i][j] = (dp[i - 1][j] * R + dp[i - 1][j + 1] * B) % MOD;
            }
        }
    }

    int total_chains = dp[N][0]; // Number of good chains with equal blue and red balls

    // Calculate probability of each great chain
    long long prob_per_chain = power(B * R, N, MOD); // (B * R)^N mod MOD

    // Calculate total probability
    long long total_prob = (total_chains * prob_per_chain) % MOD;

    cout << total_prob << endl;

    return 0;
}

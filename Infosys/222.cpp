#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Modular inverse
long long mod_inv(long long x, long long p) {
    long long res = 1, y = p - 2;
    while (y) {
        if (y & 1) res = res * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return res;
}

long long solve(int N, int K, int B, int R) {
    long long prob_blue = B * mod_inv(1e6, MOD) % MOD;
    long long prob_red = R * mod_inv(1e6, MOD) % MOD;

    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(N + 1, vector<long long>(N + 1, 0)));
    dp[0][0][0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int b = 0; b <= N; ++b) {
            for (int r = 0; r <= N; ++r) {
                if (b > 0 && b <= r + K) {
                    dp[i][b][r] = (dp[i][b][r] + dp[i - 1][b - 1][r] * prob_blue % MOD) % MOD;
                }
                if (r > 0) {
                    dp[i][b][r] = (dp[i][b][r] + dp[i - 1][b][r - 1] * prob_red % MOD) % MOD;
                }
            }
        }
    }

    long long great_chains = 0;
    for (int b = 0; b <= N; ++b) {
        for (int r = 0; r <= N; ++r) {
            if (b <= r + K) {
                great_chains = (great_chains + dp[N][b][r] * dp[N][r][b] % MOD) % MOD;
            }
        }
    }

    return great_chains;
}

int main() {
    int N, K, B, R;
    cin >> N >> K >> B >> R;
    
    cout << solve(N, K, B, R) << endl;
    
    return 0;
}

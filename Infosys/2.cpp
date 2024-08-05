// // // // #include <iostream>
// // // // #include <vector>
// // // // #include <cmath>

// // // // using namespace std;

// // // // const int MOD = 1e9 + 7;

// // // // // Modular inverse using Fermat's Little Theorem
// // // // long long mod_inv(long long x, long long p) {
// // // //     long long res = 1, y = p - 2;
// // // //     while (y) {
// // // //         if (y & 1) res = res * x % p;
// // // //         x = x * x % p;
// // // //         y >>= 1;
// // // //     }
// // // //     return res;
// // // // }

// // // // long long solve(int N, int K, int B, int R) {
// // // //     long long prob_blue = B * mod_inv(1e6, MOD) % MOD;
// // // //     long long prob_red = R * mod_inv(1e6, MOD) % MOD;
    
// // // //     vector<vector<long long>> dp(K + 1, vector<long long>(K + 1, 0));
// // // //     dp[0][0] = 1;

// // // //     for (int i = 1; i <= N; ++i) {
// // // //         vector<vector<long long>> new_dp(K + 1, vector<long long>(K + 1, 0));
// // // //         for (int b = 0; b <= K; ++b) {
// // // //             for (int r = 0; r <= K; ++r) {
// // // //                 if (b <= r + K) {
// // // //                     if (b > 0) new_dp[b][r] = (new_dp[b][r] + dp[b - 1][r] * prob_blue) % MOD;
// // // //                     if (r > 0) new_dp[b][r] = (new_dp[b][r] + dp[b][r - 1] * prob_red) % MOD;
// // // //                 }
// // // //             }
// // // //         }
// // // //         dp = new_dp;
// // // //     }

// // // //     long long great_chains = 0;
// // // //     for (int b = 0; b <= K; ++b) {
// // // //         for (int r = 0; r <= K; ++r) {
// // // //             if (b <= r + K) {
// // // //                 great_chains = (great_chains + dp[b][r] * dp[r][b]) % MOD;
// // // //             }
// // // //         }
// // // //     }

// // // //     return great_chains;
// // // // }

// // // // int main() {
// // // //     int N, K, B, R;
// // // //     cin >> N >> K >> B >> R;

// // // //     cout << solve(N, K, B, R) << endl;

// // // //     return 0;
// // // // }
// // // #include <iostream>
// // // #include <vector>

// // // using namespace std;

// // // const int MOD = 1e9 + 7;

// // // long long power(long long base, long long exponent, long long mod) {
// // //     long long result = 1;
// // //     base = base % mod;
// // //     while (exponent > 0) {
// // //         if (exponent % 2 == 1)
// // //             result = (result * base) % mod;
// // //         exponent = exponent / 2;
// // //         base = (base * base) % mod;
// // //     }
// // //     return result;
// // // }

// // // int main() {
// // //     int N, K, B, R;
// // //     cin >> N >> K >> B >> R;

// // //     vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
// // //     dp[0][0] = 1;

// // //     for (int i = 1; i <= N; ++i) {
// // //         for (int j = 0; j <= K; ++j) {
// // //             if (j > 0) {
// // //                 dp[i][j] = (dp[i - 1][j - 1] * B + dp[i - 1][j + 1] * R) % MOD;
// // //             } else {
// // //                 dp[i][j] = (dp[i - 1][j] * R + dp[i - 1][j + 1] * B) % MOD;
// // //             }
// // //         }
// // //     }

// // //     int total_chains = dp[N][0]; // Number of good chains with equal blue and red balls

// // //     // Calculate probability of each great chain
// // //     long long prob_per_chain = power(B * R, N, MOD); // (B * R)^N mod MOD

// // //     // Calculate total probability
// // //     long long total_prob = (total_chains * prob_per_chain) % MOD;

// // //     cout << total_prob << endl;

// // //     return 0;
// // // }

// // #include <iostream>
// // #include <vector>

// // using namespace std;

// // const int MOD = 1e9 + 7;
// // const int SCALE = 1e6;

// // long long power(long long base, long long exponent, long long mod) {
// //     long long result = 1;
// //     base = base % mod;
// //     while (exponent > 0) {
// //         if (exponent % 2 == 1)
// //             result = (result * base) % mod;
// //         exponent = exponent / 2;
// //         base = (base * base) % mod;
// //     }
// //     return result;
// // }

// // int main() {
// //     int N, K, B, R;
// //     cin >> N >> K >> B >> R;

// //     vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
// //     dp[0][0] = 1;

// //     for (int i = 1; i <= N; ++i) {
// //         for (int j = 0; j <= K; ++j) {
// //             if (j > 0) {
// //                 dp[i][j] = (dp[i - 1][j - 1] * B + dp[i - 1][j + 1] * R) % MOD;
// //             } else {
// //                 dp[i][j] = (dp[i - 1][j] * R + dp[i - 1][j + 1] * B) % MOD;
// //             }
// //         }
// //     }

// //     int total_chains = dp[N][0]; // Number of good chains with equal blue and red balls

// //     // Calculate probability of each great chain
// //     long long prob_per_chain = power(B * R, N, MOD * SCALE); // (B * R)^N mod (MOD * SCALE)
// //     prob_per_chain = (prob_per_chain * power(SCALE, MOD - 2, MOD)) % MOD; // Divide by SCALE^N mod MOD

// //     // Calculate total probability
// //     long long total_prob = (total_chains * prob_per_chain) % MOD;

// //     cout << total_prob << endl;

// //     return 0;
// // }
// #include <iostream>
// #include <vector>
// using namespace std;

// const int MOD = 1e9 + 7;

// long long modInverse(long long a, long long m) {
//     long long m0 = m, y = 0, x = 1;
//     if (m == 1) return 0;
//     while (a > 1) {
//         long long q = a / m;
//         long long t = m;
//         m = a % m, a = t;
//         t = y;
//         y = x - q * y;
//         x = t;
//     }
//     if (x < 0) x += m0;
//     return x;
// }

// long long binomialCoefficient(int n, int k) {
//     if (k > n) return 0;
//     long long res = 1;
//     for (int i = 0; i < k; i++) {
//         res = (res * (n - i)) % MOD;
//         res = (res * modInverse(i + 1, MOD)) % MOD;
//     }
//     return res;
// }

// long long probabilityOfGreatChain(int N, int K, int B, int R) {
//     // Calculate the total number of great chains
//     // This would require combinatorial counting based on the constraints
//     // Here we would return the calculated probability mod MOD
//     // This is a placeholder for the actual logic needed
//     return 0; // Replace with actual logic
// }

// int main() {
//     int N, K, B, R;
//     cin >> N >> K >> B >> R;

//     long long result = probabilityOfGreatChain(N, K, B, R);
//     cout << result << endl;

//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate modular inverse
long long modInverse(long long a, long long m) {
    long long m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

// Function to calculate binomial coefficient
long long binomialCoefficient(int n, int k) {
    if (k > n) return 0;
    long long res = 1;
    for (int i = 0; i < k; i++) {
        res = (res * (n - i)) % MOD;
        res = (res * modInverse(i + 1, MOD)) % MOD;
    }
    return res;
}

// Function to calculate the probability of a great chain
long long probabilityOfGreatChain(int N, int K, int B, int R) {
    // If N is odd, return 0
    if (N % 2 != 0) return 0;

    int halfN = N / 2; // Number of blue and red balls
    // Calculate the total number of valid configurations
    long long totalWays = 0;

    // Count valid configurations based on K
    for (int b = 0; b <= halfN; ++b) {
        int r = halfN - b;
        if (b <= r + K) {
            totalWays = (totalWays + binomialCoefficient(halfN, b)) % MOD;
        }
    }

    // Calculate the probability of each configuration
    long long prob_per_chain = (B * R) % MOD; // P(B) * P(R)
    prob_per_chain = (prob_per_chain * modInverse(1e6 * 1e6, MOD)) % MOD; // Normalize by (1e6)^N

    // Calculate total probability
    long long total_prob = (totalWays * prob_per_chain) % MOD;

    return total_prob;
}

int main() {
    int N, K, B, R;
    cin >> N >> K >> B >> R;

    long long result = probabilityOfGreatChain(N, K, B, R);
    cout << result << endl;

    return 0;
}

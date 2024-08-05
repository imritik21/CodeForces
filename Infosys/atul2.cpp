#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int countValidArrays(int N, int K) {
    int limit = (1 << K) + 1;
    
    // Initialize DP tables
    std::vector<std::vector<long long>> dp(2, std::vector<long long>(limit, 0));
    std::vector<std::vector<bool>> valid(limit, std::vector<bool>(limit, false));
    
    // Initialize the first row of dp
    for (int i = 1; i < limit; ++i) {
        dp[0][i] = 1;
    }
    
    // Precompute valid transitions
    for (int i = 1; i < limit; ++i) {
        for (int j = 1; j < limit; ++j) {
            if ((i & j) > 0) {
                valid[i][j] = true;
            }
        }
    }
    
    // Fill the DP table
    for (int len = 2; len <= N; ++len) {
        int curr = len % 2;
        int prev = 1 - curr;
        
        for (int currState = 1; currState < limit; ++currState) {
            dp[curr][currState] = 0; // Reset current dp row
        }
        
        for (int prevState = 1; prevState < limit; ++prevState) {
            if (dp[prev][prevState] > 0) {
                for (int nextState = 1; nextState < limit; ++nextState) {
                    if (valid[prevState][nextState]) {
                        dp[curr][nextState] = (dp[curr][nextState] + dp[prev][prevState]) % MOD;
                    }
                }
            }
        }
    }
    
    // Sum up all valid arrays of length N
    long long result = 0;
    int finalRow = N % 2;
    
    for (int i = 1; i < limit; ++i) {
        result = (result + dp[finalRow][i]) % MOD;
    }
    
    return result-1; // Exclude the empty array case
}

int main() {
    int N, K;
    std::cin >> N >> K;
    
    std::cout << countValidArrays(N, K) << std::endl;
    
    return 0;
}

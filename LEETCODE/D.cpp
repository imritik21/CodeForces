#include <vector>
#include <algorithm>
#include <iostream>
#define MOD 1000000007

using namespace std;

// Function to calculate the number of permutations satisfying the inversion constraints
int countPermutations(int n, vector<vector<int>>& requirements) {
    // DP table to store the number of ways to arrange i elements with j inversions
    vector<vector<int>> dp(n+1, vector<int>(n*(n-1)/2 + 1, 0));
    dp[0][0] = 1;

    // Fill the DP table
    for (int len = 1; len <= n; ++len) {
        for (int inv = 0; inv <= n*(n-1)/2; ++inv) {
            for (int k = 0; k < len; ++k) {
                if (inv - k >= 0) {
                    dp[len][inv] = (dp[len][inv] + dp[len-1][inv-k]) % MOD;
                }
            }
        }
    }

    // Now we need to filter out permutations that don't meet the requirements
    vector<vector<int>> valid_dp(n+1, vector<int>(n*(n-1)/2 + 1, 0));
    valid_dp[0][0] = 1;

    for (auto& req : requirements) {
        int end = req[0] + 1; // Convert 0-based end to length
        int cnt = req[1];

        for (int len = n; len >= end; --len) {
            for (int inv = n*(n-1)/2; inv >= cnt; --inv) {
                valid_dp[len][inv] = (valid_dp[len][inv] + valid_dp[len-end][inv-cnt] * dp[end][cnt]) % MOD;
            }
        }
    }

    int result = 0;
    for (int inv = 0; inv <= n*(n-1)/2; ++inv) {
        result = (result + valid_dp[n][inv]) % MOD;
    }

    return result;
}

int main() {
    int n = 3;
    vector<vector<int>> requirements = {{2, 2},{1,1},{0,0}};
    cout << countPermutations(n, requirements) << endl;
    return 0;
}

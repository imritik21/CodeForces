#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int maze(int n, int m, vector<vector<int>>& blocked) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    // If the starting cell is blocked, return 0
    if (blocked[0][0] == 1 || blocked[n-1][m-1] == 1) {
        return 0;
    }

    // Initialize the starting position
    dp[0][0] = 1;

    // Fill the DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blocked[i][j] == 1) {
                dp[i][j] = 0; // Blocked cell
            } else {
                if (i > 0) {
                    dp[i][j] += dp[i-1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
    }

    return dp[n-1][m-1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> blocked(n, vector<int>(m, 0));

    int k;
    cin >> k;
    while (k--) {
        int i, j;
        cin >> i >> j;
        blocked[i][j] = 1; // Mark the cell as blocked
    }

    cout << maze(n, m, blocked) << endl;

    return 0;
}

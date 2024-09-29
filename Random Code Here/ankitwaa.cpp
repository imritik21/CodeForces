#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to find the minimum cost to reach (m-1, n-1)
int minCost(vector<vector<int>>& grid, int m, int n) {
    // Create a 2D array to store the minimum cost up to each cell
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the starting point
    dp[0][0] = grid[0][0];

    // Fill the first row (can only come from the left)
    for (int i = 1; i < n; i++) {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    // Fill the first column (can only come from above)
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the rest of the dp array by choosing the minimum of coming from the left or top
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Return the minimum cost to reach (m-1, n-1)
    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter the grid values:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = minCost(grid, m, n);
    cout << "Minimum cost to reach (m-1, n-1): " << result << endl;

    return 0;
}
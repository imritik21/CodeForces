#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e9 + 7;

using namespace std;

vector<vector<int>> adj;
vector<int> values;
int K;
vector<bool> visited;

void dfs(int node, vector<int>& path, vector<vector<int>>& dp) {
    visited[node] = true;
    path.push_back(values[node]);

    // Initialize the DP array for the current path
    vector<int> new_dp(K + 1, 0);
    new_dp[0] = 1; // Base case: empty subset sum to 0
    
    for (int value : path) {
        for (int sum = K; sum >= value; --sum) {
            new_dp[sum] = (new_dp[sum] + new_dp[sum - value]) % MOD;
        }
    }
    
    // Add to total count
    dp[node] = new_dp;
    
    // Recurse for all children
    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child, path, dp);
        }
    }
    
    path.pop_back();
}

int main() {
    int N, M;
    cin >> N >> M;
    values.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> values[i];
    }
    
    adj.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cin >> K;
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    visited.assign(N + 1, false);

    vector<int> path;
    dfs(1, path, dp);

    long long result = 0;
    for (int i = 1; i <= N; ++i) {
        result = (result + dp[i][K]) % MOD;
    }
    
    cout << result << endl;

    return 0;
}
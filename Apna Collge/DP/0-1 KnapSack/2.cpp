#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
void print(vector<vector<int>> dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int solve(int n, int k, vector<vector<int>>& dp) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (dp[n][k] != -1){
        // calc ho gya h
        return dp[n][k];
    }
    // calc
    dp[n][k] = (solve(n - 1, k - 1, dp) + solve(n - 1, k, dp));
    // print(dp);
    return dp[n][k]%MOD;
}

int findValueAfterKSeconds(int n, int k) {
    vector<vector<int>> dp(n + k, vector<int>(k + 1, -1));
    return solve(n + k - 1, k, dp);
}

int main() {
    int n = 4; 
    int k = 1000; 

    cout<<findValueAfterKSeconds(n, k);
    

    return 0;
}

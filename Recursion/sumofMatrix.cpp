#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


int n, m;
vector<vector<int>> res;
vector<int> curr_row;

void solve(vector<vector<int>>& arr1, vector<vector<int>>& arr2, int i, int j) {
    if (j == m) {
        res.push_back(curr_row);
        solve(arr1, arr2, i + 1, 0);
        return;
    }
    if (i == n) {
        return;
    }
    curr_row[j] = arr1[i][j] + arr2[i][j];
    solve(arr1, arr2, i, j + 1);
}

vector<vector<int>> MatrixSum(vector<vector<int>>& arr1, vector<vector<int>>& arr2) {
    solve(arr1, arr2, 0, 0);
    return res;
}
int main() {
    cin >> n >> m;
    vector<vector<int>> arr1(n, vector<int>(m));
    vector<vector<int>> arr2(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr2[i][j];
        }
    }
    curr_row.assign(m, 0);
    vector<vector<int>>ans = MatrixSum(arr1, arr2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
} 
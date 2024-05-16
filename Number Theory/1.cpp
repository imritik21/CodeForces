#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDist(int i, int j, vector<vector<int>>& arr, int n, int m) {
    int mini = INT_MAX;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (arr[x][y] == 1) {
                int dist = abs(x - i) + abs(y - j); // Manhattan distance
                mini = min(mini, dist);
            }
        }
    }
    return mini;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) {
                    int mini = minDist(i, j, arr, n, m);
                    maxi = max(maxi, mini);
                }
            }
        }
        cout << maxi << endl;
    }
    return 0;
}

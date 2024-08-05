#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<char>> arr(n, vector<char>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    // Initialize the result vector with appropriate size
    vector<vector<char>> res(n / k, vector<char>(n / k));
    
    for (int i = 0; i < n; i += k) {
        for (int j = 0; j < n; j += k) {
            if (arr[i][j] == '0') {
                res[i / k][j / k] = '0';
            } else {
                res[i / k][j / k] = '1';
            }
        }
    }
    
    for (int i = 0; i < n / k; i++) {
        for (int j = 0; j < n / k; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

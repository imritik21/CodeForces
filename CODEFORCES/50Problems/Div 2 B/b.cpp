#include <iostream>
#include <vector>
#include <string>
using namespace std;

int rowSum(const vector<string>& arr1, int m) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int num = stoi(arr1[i]);
        sum += num;
    }
    return sum;
}

int colSum(const vector<vector<string>>& arr, int colIndex, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num = stoi(arr[i][colIndex]);
        sum += num;
    }
    return sum;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> arr1(n),arr2(n);
    for (int i = 0; i < n; i++) {
        cin>>arr1[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin>>arr2[i];
    }

    bool flag = true;

    // Check row sums
    for (int i = 0; i < n; i++) {
        int sum1 = rowSum(arr1[i], m);
        int sum2 = rowSum(arr2[i], m);
        if (sum1 % 3 != sum2 % 3) {
            flag = false;
            break;
        }
    }

    // Check column sums
    for (int j = 0; j < m; j++) {
        int sum1 = colSum(arr1, j, n);
        int sum2 = colSum(arr2, j, n);
        if (sum1 % 3 != sum2 % 3) {
            flag = false;
            break;
        }
    }
    cout<<rowSum(arr1[0],m)<<" "<<colSum(arr1,0,n);

    // if (flag) cout << "YES" << endl;
    // else cout << "NO" << endl;
}

int main() {
    int tc;cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}

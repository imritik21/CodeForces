#include <bits/stdc++.h>
using namespace std;

int valueAfterKSeconds(int n, int k) {
    vector<int> arr(n, 1);
    if (k == 0)
        return arr[n-1];

    const int MOD = 1e9+7;

    while (k--) {
        vector<int> newArray(n, 1);
        newArray[0] = arr[0];
        for (int i = 1; i < n; i++) {
            newArray[i] = (newArray[i - 1] + arr[i]);
        }
        arr = newArray;
        // cout << "After iteration " << k << ": ";
        // for (int i = 0; i < n; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
    }

    return arr[n - 1] % MOD;
}

int main() {
    cout << valueAfterKSeconds(4, 1000) << endl;
    return 0;
}
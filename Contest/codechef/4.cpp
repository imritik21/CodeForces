#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countCursedIndices(vector<int>& arr) {
    int n = arr.size();
    int cursedIndices = 0;
    int prefixSum = 0;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (prefixSum >= arr[i]) {
            cursedIndices++;
        }
        prefixSum += arr[i];
    }

    return cursedIndices;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int minCursedIndices = countCursedIndices(arr);

        cout << minCursedIndices << endl;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

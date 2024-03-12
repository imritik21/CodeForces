#include <bits/stdc++.h>
using namespace std;

bool canMakeZero(vector<int>& arr) {
    int n = arr.size();

    // Handle base cases (array size less than or equal to 2)
    if (n <= 2) {
        return false;
    }

    // Iterate through the middle elements (i from 1 to n-2, inclusive)
    for (int i = 1; i < n - 1; i++) {
        int operation1 = arr[i - 1] - 1; // Subtract 1 from previous element
        int operation2 = arr[i - 1];    // Use the value of the previous element
        int operation3 = arr[i + 1] - 1; // Subtract 1 from the next element

        // Check if any operation results in zero for current or next element
        if (operation1 >= 0 && operation1 <= arr[i]) { // Make current zero using prev
            arr[i] -= operation1;
        } else if (operation2 == 0) { // Use previous zero for current
            arr[i] = operation2;
        } else if (operation3 >= 0 && operation3 <= arr[i + 1]) { // Make next zero
            arr[i + 1] -= operation3;
        } else {
            return false; // No valid operation found
        }
    }

    // Check if all elements are zero after processing
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (canMakeZero(arr)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}

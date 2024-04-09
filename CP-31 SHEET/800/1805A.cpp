#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Size of the array
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // Input elements of the array
        }

        int xor_result = 0;
        for (int x : a) {
            xor_result ^= x; // Calculating XOR of all elements
        }

        if (xor_result == 0) {
            cout << 0 << endl;
        } else {
            if (n % 2 == 1) {
                cout << xor_result << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}

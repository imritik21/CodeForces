#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
        }
        bool found = false;
        for (int i = 1; i < sum; i++) {
            if (i * i == sum) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

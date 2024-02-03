#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Base case: n is already zero
        if (n == 0) {
            cout << "YES" << endl;
        } else {
            // Check if n can be made zero by subtracting 3 or 4
            while (n >= 3) {
                if (n % 3 == 0) {
                    n -= 3;
                } else {
                    n -= 4;
                }
            }

            // Check if n is zero after the loop
            if (n == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}

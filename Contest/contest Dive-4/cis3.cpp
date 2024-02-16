#include <iostream>
#include <cmath> // Include the cmath library for sqrt function
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int A[n];
        long long int sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> A[i];
            sum += A[i];
        }

        if (sum > 0 && sqrt(sum) == floor(sqrt(sum))) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

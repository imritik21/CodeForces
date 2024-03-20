#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define mod 1000000007

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    int A[n];
    int B[n];
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }

    ll sum = 0;
    for(int i = 0; i < n; i++) {
        ll sum1 = 0;
        if(x >= 0 && y >= 0 && z >= 0) {
            // Operation 1
            sum1 = sum1 - B[i];
        }

        ll sum2 = 0;
        if(x >= 0 && y >= 0 && z >= 0) {
            // Operation 2
            ll oper2 = 1;
            x--; y--;
            oper2 = oper2 * A[i] * x * y * z;
            sum2 = sum2 + oper2;
        }

        ll sum3 = 0;
        if(x >= 0 && y >= 0 && z >= 0) {
            // Operation 3
            ll oper3 = 1;
            z--; y--;
            oper3 = oper3 * A[i] * x * y * z;
            sum3 = sum3 + oper3;
        }

        sum = sum + max(sum1, max(sum2, sum3));
    }
    cout << sum << endl;

    return 0;
}

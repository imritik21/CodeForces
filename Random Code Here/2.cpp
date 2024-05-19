#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (char c = 'a'; c < 'a' + i; c++) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}

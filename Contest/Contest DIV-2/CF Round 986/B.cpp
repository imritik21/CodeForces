#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string str;
        cin >> str;
        int right = 0, up = 0;
        int flag = 0;
        for (int i = 0; i <= 500; i++) {
            if (right == a && up == b) {
                flag = 1;
                break;
            }
            if (str[i % n] == 'N') {
                up++;
            } else if (str[i % n] == 'E') {
                right++;
            } else if (str[i % n] == 'S') {
                up--;
            } else if (str[i % n] == 'W') {
                right--;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
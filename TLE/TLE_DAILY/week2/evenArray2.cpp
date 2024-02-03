 #include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int count = 0;
        bool found = false;

        if (n == 1) {
            found = false;
        }

        for (int i = 0; i < n ; i++) {
            if (i % 2 != arr[i] % 2) {
                found = true;
                swap(arr[i], arr[i + 1]);
                count++;
            }
        }

        if (found) {
            cout << count << '\n';
        } else {
            cout << "-1" << '\n';
        }
    }

    return 0;
}
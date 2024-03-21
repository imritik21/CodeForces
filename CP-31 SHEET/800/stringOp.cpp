#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;

    int count = 0;
    while (x.length() < s.length()) {
        x += x; // Extend x by concatenating itself
        count++;
    }

    size_t pos = x.find(s);

    if (pos != string::npos) {
        cout << count << endl;
    } else {
        cout << "-1" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int it = 1; it <= t; it++) {
        solve();
    }
    return 0;
}

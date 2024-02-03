#include <bits/stdc++.h>
using namespace std;

bool isConsonant(char ch) {
    return (ch >= 'a' && ch <= 'z' && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u');
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string out;
        
        for (int i = 0; i < n; i++) {
            if (i + 2 < n && isConsonant(s[i]) && (s[i + 1] >= 'a' && s[i + 1] <= 'e') && isConsonant(s[i + 2])) {
                out.push_back(s[i]);
                out.push_back(s[i + 1]);
                out.push_back(s[i + 2]);
                i += 2;
            } else if (isConsonant(s[i])) {
                out.push_back(s[i]);
            } else {
                out.push_back('.');
            }
        }

        cout << out << "\n";
    }

    return 0;
}

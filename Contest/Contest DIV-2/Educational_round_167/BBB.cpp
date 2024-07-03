#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if `b` is a subsequence of `merged`
bool isSubsequence(const string &b, const string &merged) {
    int j = 0;
    for (int i = 0; i < merged.length() && j < b.length(); i++) {
        if (b[j] == merged[i]) {
            j++;
        }
    }
    return (j == b.length());
}

int minLengthSubstringAndSubsequence(const string &a, const string &b) {
    // To store the merged result
    string merged = a;

    // Check if `b` is already a subsequence of `a`
    if (isSubsequence(b, a)) {
        return a.length();
    }

    // Try to merge `b` at every possible position in `a`
    int min_length = a.length() + b.length(); // Initial large value
    for (int i = 0; i <= a.length(); i++) {
        string temp = a.substr(0, i) + b + a.substr(i);
        if (isSubsequence(b, temp)) {
            min_length = min(min_length, (int)temp.length());
        }
    }

    return min_length;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << minLengthSubstringAndSubsequence(a, b) << endl;
    return 0;
}

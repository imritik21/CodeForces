#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int cnt = 0;
vector<vector<int>> allPermutations; // Contains all permutations

void subsets(int ind, int size, vector<int>& f, vector<int>& curr) {
    if (ind == size) {
        // We reached the end, so push the current permutation
        allPermutations.push_back(curr);
        cnt++;
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (f[i] > 0) {
            f[i]--;
            curr.push_back(i);
            subsets(ind + 1, size, f, curr);
            curr.pop_back(); // Backtrack
            f[i]++; // Restore the frequency
        }
    }
}

int main() {
    string str;
    cin >> str;
    vector<int> f(10, 0); // Frequency array for digits 0 to 9
    for (char c : str) {
        f[c - '0']++;
    }

    vector<int> curr;
    subsets(0, str.length(), f, curr);
    
    cout << cnt << endl;
    for (const auto& perm : allPermutations) {
        for (int num : perm) {
            cout << num;
        }
        cout << endl;
    }

    return 0;
}

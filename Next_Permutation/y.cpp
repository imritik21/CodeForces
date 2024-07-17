#include <iostream>
#include <vector>
using namespace std;

int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int n = colors.size();
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        bool isAlternating = true;
        for (int j = 1; j < k; ++j) {
            if (colors[(i + j) % n] == colors[(i + j - 1) % n]) {
                isAlternating = false;
                break;
            }
        }
        if (isAlternating) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    vector<int> colors = {0, 1, 0,0, 1,0,1}; // Example input
    int k = 6; // Example k
    cout << numberOfAlternatingGroups(colors, k) << endl; // Output the number of alternating groups
    return 0;
}

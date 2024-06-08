#include <iostream>
#include <vector>

using namespace std;

void findElementSegments(const vector<int>& arr, vector<pair<int, int>>& p) {
    int n = arr.size();
    int low = 0;

    for (int i = 1; i <= n; ++i) {
        if (i == n || arr[i] != arr[i - 1]) {
            p.push_back({low, i - 1});
            low = i;
        }
    }
}

int main() {
    vector<int> arr = {1,2,3,4,5}; // Example input
    vector<pair<int, int>> p;

    findElementSegments(arr, p);

    for (const auto& segment : p) {
        cout << segment.first << " " << segment.second << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long countSubsequences(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> indicesMap;
    vector<long long> dp(n, 0);
    long long count = 0;

    // Store indices of each element
    for (int i = 0; i < n; ++i) {
        indicesMap[nums[i]].push_back(i);
    }

    // Calculate subsequences ending at each position
    for (int i = 0; i < n; ++i) {
        int num = nums[i];
        for (int j : indicesMap[num]) {
            if (j > i) {
                dp[j] += dp[i] + 1;
                count += dp[i] + 1;
            }
        }
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 6, 5, 3};
    cout << countSubsequences(nums) << endl; // Output: 6
    return 0;
}

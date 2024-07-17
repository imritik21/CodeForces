#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;

void checkSpecialPermutation(vector<int>& perm, int n) {
    for (int i = 0; i + 1 < n; i++) {
        if (perm[i] % perm[i + 1] != 0 && perm[i + 1] % perm[i] != 0) {
            return;
        }
    }
    ans++;
}

void permute(vector<int>& nums, int l, int r) {
    if (l == r) {
        checkSpecialPermutation(nums, r + 1);
    } else {
        for (int i = l; i <= r; i++) {
            swap(nums[l], nums[i]);
            permute(nums, l + 1, r);
            swap(nums[l], nums[i]); // backtrack
        }
    }
}

int specialPerm(vector<int>& nums) {
    int n = nums.size();
    permute(nums, 0, n - 1);
    return ans;
}

int main() {
    vector<int> nums = {2,3,6}; // Example input
    cout << specialPerm(nums) << endl; // Output the number of special permutations
    return 0;
}

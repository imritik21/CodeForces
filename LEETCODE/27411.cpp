#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;

void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used, int n) {
    if (curr.size() == n) {
        ans++;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        
        if (!curr.empty() && !(curr.back() % nums[i] == 0 || nums[i] % curr.back() == 0)) {
            continue;
        }
        
        used[i] = true;
        curr.push_back(nums[i]);
        
        backtrack(nums, curr, used, n);
        
        used[i] = false;
        curr.pop_back();
    }
}

int specialPerm(vector<int>& nums) {
    int n = nums.size();
    vector<int> curr;
    vector<bool> used(n, false);
    
    backtrack(nums, curr, used, n);
    
    return ans;
}

int main() {
    vector<int> nums = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192}; // Example input
    cout << specialPerm(nums) << endl; // Output the number of special permutations
    return 0;
}

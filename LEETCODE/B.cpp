#include <iostream>
#include <vector>
using namespace std;

int minOperationsToMakeAllOnes(vector<int>& nums) {
    int n = nums.size();
    int flips = 0;
    
    for (int i = 0; i < n - 2; ++i) {
        if (nums[i] == 0) {
            // Flip the current element and the next two elements
            nums[i] = 1 - nums[i];
            nums[i+1] = 1 - nums[i+1];
            nums[i+2] = 1 - nums[i+2];
            ++flips;
        }
    }
    
    // Check if the last two elements are all ones
    for (int i = n - 2; i < n; ++i) {
        if (nums[i] == 0) {
            return -1; // It's impossible to flip remaining 0s
        }
    }
    
    return flips;
}

int main() {
    vector<int> nums = { 0,1,1,0,1};
    int result = minOperationsToMakeAllOnes(nums);
    if (result == -1) {
        cout << "It's impossible to make all elements 1." << endl;
    } else {
        cout << "Minimum number of operations required: " << result << endl;
    }
    return 0;
}
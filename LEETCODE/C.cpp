#include <iostream>
#include <vector>
using namespace std;

int minOperationsToMakeAllOnes(vector<int>& nums) {
    int n = nums.size();
    int flips = 0;
    
    // Traverse the array
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            // Perform the flip from index i to the end
            flips++;
            for (int j = i; j < n; ++j) {
                nums[j] = 1 - nums[j];
            }
        }
    }
    
    return flips;
}
int minOperations(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;
    bool flip = false;  // This flag will help us to avoid unnecessary flipping.

    for (int i = 0; i < n; ++i) {
        // Check the current state of nums[i] considering the flip flag.
        if (flip) {
            nums[i] = 1 - nums[i];
        }
        // If we encounter a 0, we need to flip the rest of the array.
        if (nums[i] == 0) {
            cnt++;
            flip = !flip;  // Toggle the flip flag.
        }
    }

    return cnt;
}
int main() {
    vector<int> nums = {1,0,0,0};
    int result = minOperations(nums);
    if (result == -1) {
        cout << "It's impossible to make all elements 1." << endl;
    } else {
        cout << "Minimum number of operations required: " << result << endl;
    }
    return 0;
}

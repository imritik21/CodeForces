#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> curr_subset;
    vector<vector<int>> final_output;

    void solve(int i, vector<int> &nums)
    {
        // Base case: if i reaches the end of the vector nums
        if (i == nums.size())
        {
            // Add the current subset to the final_output vector
            final_output.push_back(curr_subset);
            return;
        }

        // Recursive call to solve function wi thout including nums[i] in the subset
        solve(i + 1, nums);

        // Include nums[i] in the subset
        curr_subset.push_back(nums[i]);

        // Recursive call to solve function after including nums[i] in the subset
        solve(i + 1, nums);

        // Backtrack: Remove nums[i] from the subset before returning
        curr_subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        final_output.clear();
        solve(0, nums);
        return final_output;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3};
    solution s;

    for (auto i : s.subsets(nums))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

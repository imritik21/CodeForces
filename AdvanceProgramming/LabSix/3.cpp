/*Given an integer array and an integer k the task
is to check if it is possible to divide the given array
 into k non empty subsets of equal sub such that every
 array element is a part of a single subset.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool backtrack(vector<int> &nums, vector<int> vis, int target, int curr_sum, int i, int k)
{
    if (k == 1)
        return true;

    if (curr_sum == target)
        return backtrack(nums, vis, target, 0, 0, k - 1);

    for (int j = i; j < nums.size(); j++)
    {
        if (vis[j] || curr_sum + nums[j] > target)
            continue;

        vis[j] = 1; // mark and take in sum
        if (backtrack(nums, vis, target, curr_sum + nums[j], j + 1, k))
            return true;
        vis[j] = 0;
    }

    return false;
}
bool isPossible(vector<int> &nums, int k)
{
    int sum = 0;
    for(auto& ele:nums)sum+=ele;
    if (nums.size() < k || sum % k)
        return false;
    vector<int> vis(nums.size(), false);
    return backtrack(nums, vis, sum / k, 0, 0, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k = 3;
    vector<int> arr = {2, 8, 5, 5, 9, 1};
    //  {2,8}  {5,5}  {9,1} k subset of equal sum
    int n = arr.size();
    bool possible = isPossible(arr, k);
    if(possible)cout<<"Possible"<<endl;
    else cout<<"Not Possible"<<endl;
    return 0;
}

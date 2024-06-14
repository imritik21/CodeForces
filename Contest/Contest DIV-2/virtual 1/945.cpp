#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int minIncrementForUnique(vector<int> &nums)
{
    int cnt = 0;
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }
    sort(nums.begin(), nums.end());
    for (int i = n - 1; i >= 0; i--)
    {
        if (mp[nums[i]] > 1)
        {
            nums[i]++;
            cnt++;
            // update

            mp[nums[i]]--;
            mp[nums[i] + 1]++;
            i = n;
        }
    }
    return cnt;
}
int main()
{
    vector<int> nums = {1,2,2};
    int cnt = 0;
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }
    sort(nums.begin(), nums.end());
    // 1 1 2 2 3 7
    for (int i = n - 1; i >= 0; i--)
    {
        if (mp[nums[i]] > 1)
        {
            mp[nums[i]]--;
            nums[i]++;
            cnt++;
            // update
            cout<<"iteration "<<cnt<<" "<<nums[i]<<endl;
            
            cout<<mp[nums[i]]<<endl;
            mp[nums[i]]++;
            cout<<mp[nums[i]+1]<<endl;
            i = n;
        }
    }
    cout<<cnt;
}

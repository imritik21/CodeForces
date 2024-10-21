#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    int n = nums.size();

    deque<int> dq;
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i=0;i<k;i++){
        dq.push_back(i);
        maxi=max(maxi,nums[i]);
    }
    ans.push_back(maxi);

    for(int i=k;i<n;i++){
        dq.push_back(nums[i]);
        if()
    }
    return 0;
}

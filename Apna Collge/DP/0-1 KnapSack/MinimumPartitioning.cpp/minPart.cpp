#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int totsum(vector<int>& nums,int n){
    int tot=0;
    for(int i=0;i<n;i++) tot+=nums[i];
    return tot;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> nums = {1,6,11,5};
    int n = nums.size();
    int sum = totsum(nums,n);
    int w = sum/2;
    vector<vector<int>> dp(n+1,vector<int>(w,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int ele = nums[i-1];
            if(ele<=j){
                // valid
                dp[i][j] = max(ele+dp[i-1][j-ele],dp[i-1][j]);
            }
            else{
                // invalid
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int sum1 = dp[n][w];
    int sum2 = sum-sum1;
    cout<<abs(sum1-sum2);
    return 0;
}

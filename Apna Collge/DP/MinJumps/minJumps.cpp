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
    vector<int> nums = {2,3,1,1,4};
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        int steps = nums[i];
        int ans = INT_MAX;
        for(int j=i+1;j<=i+steps &&j<n;j++){
            if(dp[j]!=-1){
                ans=min(ans,dp[j]+1);
            }
        }
        if(ans!=INT_MAX){
            dp[i]=ans;
        }
    }
    // 0 se n-1 tk min steps 
    cout<<dp[0]<<endl;
    return 0;
}

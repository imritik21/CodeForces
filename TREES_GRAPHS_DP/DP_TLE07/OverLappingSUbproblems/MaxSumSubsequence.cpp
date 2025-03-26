#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// int solveDp(vector<int>&arr,vector<int>&dp,)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {1,4,2,-10,10,5};
    int n = arr.size();
    // find max SUm oof Subarray such that no two ele are adjacent
    // brute 
    // ans should be 4+10 = 14
    
    vector<int> dp(n,0);
    dp[0] = arr[0];
    if(n>1){
        dp[1] = max(arr[0],arr[1]);
    }
    for(int i=1;i<n;i++){
        if(i-2>=0){
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        }
    }
    // for(auto& ele:dp)cout<<ele<<" ";
    // cout<<endl;
    cout<<dp[n-1]<<endl;
    return 0;
}

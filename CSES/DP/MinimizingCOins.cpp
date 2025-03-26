#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int dp[1000001];

int f(int sum,vector<int>&arr){
    if(sum==0){
        return 0;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    int ans=INT_MAX; 
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum - arr[i] >= 0)
        {
            int curr = f(sum-arr[i],arr);
            if(curr!=INT_MAX){
                ans = min(ans, curr + 1);
            }
        }
    }
    return dp[sum]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,sum;
    cin>>n>>sum;
    vector<int> arr(n);
    // 3 11
    // 1 5 7  ans = 3 (5,5,1)
    // here the main idea is that i dont have to count
    // i have only have to find the min coins required
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = f(sum,arr);
    if (ans == INT_MAX){
        cout<<-1<<endl;
    }
    else
        cout <<ans <<endl;
        
    return 0;
}

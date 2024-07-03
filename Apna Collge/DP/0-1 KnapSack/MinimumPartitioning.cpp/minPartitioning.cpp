#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int total(vector<int>&values,int n){
    int tot=0;
    for(int i=0;i<n;i++) tot+=values[i];
    return tot;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> values = {1,6,11,5};
    int n = values.size();
    // i need to take a container of sum/2 to find min diff
    int sum = total(values,n);
    int w = sum/2;
    vector<vector<int>> dp(n+1,vector<int> (w+1,0));
    // i need to find max value of conatiner or sum1
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int ele = values[i-1];
            if(ele<=j){ // valid
                dp[i][j] = max(ele+dp[i-1][j-ele],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int sum1  = dp[n][w];
    int sum2 = sum-sum1;
    cout<<abs(sum1-sum2)<<endl;
    return 0;
}

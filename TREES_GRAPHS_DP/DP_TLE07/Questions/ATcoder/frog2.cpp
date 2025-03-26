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
    

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n+1,0);
    dp[0]=0;
    // dp[1] = abs(arr[1]-arr[0]);
    for(int i=1;i<n;i++){
        int curr=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                curr = min(curr, dp[i - j] + abs(arr[i] - arr[i - j]));
            }
        }
        dp[i]=curr;
    }
    cout<<dp[n-1]<<endl;
    return 0;
}

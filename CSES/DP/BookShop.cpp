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
    
    ll n,x;
    cin>>n>>x;
    vector<int> weight(n),value(n);
    for(int i=0;i<n;i++)
        cin >> weight[i];
    for (int i = 0; i < n; i++)
        cin >> value[i];
    
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    vector<int> dpp(x+1,0);

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=x;j++){
    //         int w = weight[i-1];
    //         int val = value[i-1];
    //         if(j>=w){
    //             dp[i][j] = max(val+dp[i-1][j-w],dp[i-1][j]);
    //         }
    //         else 
    //         dp[i][j]=dp[i-1][j];
    //     }
    // }
    for(int i=0;i<n;i++){
        for(int j=x;j>=weight[i];j--){
            dpp[j] = max(value[i]+dpp[j-weight[i]],dpp[j]);
        }
    }
    cout<<dpp[x]<<endl;
    // cout<<dp[n][x]<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool valid(int x,int m){
    return x>=1&&x<=m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // dp[i][k] states no of possible ways 
    for(int i=1;i<=m;i++){
        if(arr[0]==0 || arr[0]==i){
            dp[1][i]=1;// oth index
        }
    }
    for(int i=2;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(arr[i-1]!=0 && arr[i-1]!=k){
                dp[i][k]=0;
                continue;
            }

            for(int prev=k-1;prev<=k+1;prev++){
                if(!valid(prev,m))continue;
                dp[i][k] = (dp[i][k] + dp[i-1][prev])%mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans= (ans+dp[n][i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    // here dp[i] means i store ith catalan
    for(int i=2;i<n+1;i++){
        // catalan formula
        for(int j=0;j<=i-1;j++){
            dp[i]+=dp[j]*dp[i-j-1];
            dp[i]%=mod;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}

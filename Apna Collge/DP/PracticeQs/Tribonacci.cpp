#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n ;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[2]=1;
    for(int i=3;i<n+1;i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}

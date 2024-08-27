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
    
    int n;cin>>n;

    vector<ll> dp(n+1,0);

    dp[1]=1;// only 1 way single
    dp[2]=2;// 2 way single -single and paired
    // now 
    // for dp[n] = dp[n-1] + (n-1)*dp[n-2];
    //     dp[n-1] = phla bnda single rhega to baki bache hue kaise pairup honge
    //    (n-1)*dp[n-2] = phla bnda pair up krna chahta h to no of ways * bache hue n-2 log
    for(int i=3;i<n+1;i++){
        dp[i] = (dp[i-1] + ((i-1)*dp[i-2])%mod)%mod;
    }

    cout<<dp[n]<<endl;
    return 0;
}

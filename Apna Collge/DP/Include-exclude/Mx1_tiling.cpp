#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// tiles are Mx1
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<int> dp(n+1);
    // base case rhega ki n<m and tiles to Mx1 size ki hai to ek hin way h vertically
    // aur jb equal h n==m to 2 way hz and vt both
    // wrna f(m,n) = f(m,n-1)+f(m,n-m)
    //                vt and   hz
    for(int i=1;i<n+1;i++){
        if(i<m){
            dp[i]=1;
        }
        else if(i==m){
            dp[i]=2;

        }
        else{
            dp[i]=dp[i-1]+dp[i-m];
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}

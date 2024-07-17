#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // count binary string without consecutive 0's
    int n=5;//10101
    vector<int> dp0(n+1,0);
    vector<int> dp1(n+1,0);
    // if len is 1 then only 1 comb
    dp0[1]=1;dp1[1]=1;
    for(int i=2;i<n+1;i++){
        dp1[i]=dp0[i-1]+dp1[i-1];
        dp0[i]=dp1[i-1];
    }
    cout<<(dp1[n]+dp0[n]);
    return 0;
}

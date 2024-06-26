#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void print(vector<vector<int>> dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1 = "ABCDE";
    string str2 = "ABGCE";
    int n=5;
    int m=5;

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans = 0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){

            // if char are equal
            if(str1[i-1]==str2[j-1]){
                dp[i][j] =max(dp[i][j], 1 + dp[i-1][j-1]);
                ans = max(ans,dp[i][j]);
            }
            else{
                //char are diff
                dp[i][j] = 0;
            }
        }
    }

    print(dp);
    cout<<ans<<endl;
}

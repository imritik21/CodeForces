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
    string str = "hello";
    string str2 = "helo";
    int n=5;
    int m=4;

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str[i-1]==str2[j-1]){
                // case 1 both matches
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                // doest not matche
                // again 2 case take i or take j
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

    }
    print(dp);
    cout<<dp[n][m]<<endl;
    return 0;
}

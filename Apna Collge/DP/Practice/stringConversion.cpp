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
    
    string str1 = "abcdef";
    string str2 = "aceg";

    int n = str1.size();
    int m = str2.size();
    // convert str1 to str2 using only insert and delete
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    // steps
    // 1. find LCS
    // 2. del left ele from str1 : x=n-LCS
    // 3. add y ele of str2 : y=m-LCS
    // return x+y
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            // char same
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int lcs = dp[n][m];
    //now
    int x = n-lcs;
    int y = m-lcs;
    cout<<x+y<<endl;
    return 0;
}

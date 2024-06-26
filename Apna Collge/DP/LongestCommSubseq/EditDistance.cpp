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
    
    string word1 = "intention";
    string word2 = "execution";

    int n = word1.size();
    int m = word2.size();

    // we need to find min operation needed to change word1 --> word2
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<n+1;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<m+1;i++){
        dp[0][i]=i;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){

            // 2 case 
            // if same 
            if(word1[i-1]==word2[j-1]){
                dp[i][j] = dp[i-1][j-1]; // no changes and will check for smaller
            }
            else{
                // thn we have to take min of all 3 case
                // for insert
                int insert = dp[i][j-1]+1;
                int del = dp[i-1][j] +1 ;
                int replace = dp[i-1][j-1]+1;

                dp[i][j] = min(insert,min(del,replace));
            }
        }
    }
    print(dp);
    cout<<dp[n][m];
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string word1 = "horse";
    string word2 = "ros";
    int n=word1.size();
    int m=word2.size();
    // three operation insert,delete,replace
    // we need to find min operation to 
    // convert word1 to word2
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // when word1 is empty we need to insert that many operartion 
    for(int i=0;i<n+1;i++){
        dp[i][0]=i;
    }
    // same if word2 is empty then we need word1 len operations
    for(int i=0;i<m+1;i++){
        dp[0][i]=i;
    }
    // now
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            // 2 case whn char are sme
            if(word1[i-1]==word2[j-1]){
                //no operation needed
                // move on to smaaler substring
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                // we need min of all three oper
                int del = dp[i-1][j]+1;
                int ins = dp[i][j-1]+1;
                int repl = dp[i-1][j-1]+1;
                dp[i][j]=min(ins,min(del,repl));
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}

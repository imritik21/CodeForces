#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> arr1 = {50,3,10,7,40,80};
    // we need to find longest inc subsequence
    // we need arr 2 to match common subseq
    // we will take ele in set and create arr2 from it and then we'll follow LCS
    set<int> st;
    for(auto ele: arr1){
        st.insert(ele);
    }
    vector<int> arr2;
    for(auto ele: st){
        arr2.push_back(ele);
    }
    int n = arr1.size();
    int m = arr2.size();

    // now
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // 
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){

            if(arr1[i-1]==arr2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<"LIS is "<<dp[n][m]<<endl;
    return 0;
}

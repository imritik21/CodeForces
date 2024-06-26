#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    // int row = v.size();
    // int col = v[0].size();
    int sum = 0;
    int minAbsValue = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = v[i][j];
            x = x * -1;
            sum += x;
        }
    }
    // return abs(sum);
    cout<<abs(sum)<<endl;
}

int main()
{
    int tc;cin>>tc;
    while(tc--){
        solve();
    }

    return 0;
}
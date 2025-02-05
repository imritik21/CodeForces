#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int minCost(vector<vector<int>> &cost, int row, vector<bool> &assigned)
{
    int n = cost.size();
    if (row == n)
        return 0;

    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (!assigned[j])
        { 
            assigned[j] = true;
            ans = min(ans, cost[row][j] + minCost(cost, row + 1, assigned));
            assigned[j] = false; 
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n = 4;
    vector<vector<int>> cost = {{9,2,7,8},
                                {6,4,3,7},
                                {5,8,1,8},
                                {7,6,9,4}};
    vector<bool> assigned(n,false);
    int ans = minCost(cost,0,assigned);
    // for(int i=0;i<n;i++){
    //     cout<<assigned[i]<<" ";
    // }
    // cout<<endl;
    cout<<ans<<endl;
    return 0;
}

/*
    You are given an m x n binary matrix grid,
    where 0 represents a sea cell and 1 represents a land cell.

    A move consists of walking from one land cell to
    another adjacent (4-directionally) land cell or walking off the
     boundary of the grid.

    Return the number of land cells in grid for which we cannot
     walk off the boundary of the grid in any number of moves.
*/
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

    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    int n = grid.size();
    int m = grid[0].size();
    // just visit all outer 1's and mark all comp connected to it as vis
    // as it definetly lead to walk off boundary
    // DFS- Not optimal as n*m
    // BFS - collect all oter points and one BFS iterations
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int j = 0; j < m; j++)
    {
        int i = 0;
        if (grid[i][j] == 1)
        {
            q.push({i, j});
        }
    }
    for (int j = 0; j < m; j++)
    {
        int i = n - 1;
        if (grid[i][j] == 1)
        {
            q.push({i, j});
        }
    }
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        if (grid[i][j] == 1)
        {
            q.push({i, j});
        }
    }
    for (int i = 0; i < n; i++)
    {
        int j = m - 1;
        if (grid[i][j] == 1)
        {
            q.push({i, j});
        }
    }
    
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        vis[row][col]=1;
        q.pop();

        for(auto& dir:directions){
            int nrow = row+dir.first;
            int ncol = col+dir.second;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]
            && grid[nrow][ncol]==1){
                // vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==0)cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

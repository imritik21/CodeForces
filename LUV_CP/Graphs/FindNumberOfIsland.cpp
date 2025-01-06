#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
//     vis[row][col]=1;
//     int n = grid.size();
//     int m = grid[0].size();
//     for(int i=-1;i<=1;i++){
//         for(int j=-1;j<=1;j++){
//             int nrow = row+i;
//             int ncol = col+j;
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]
//             && grid[nrow][ncol]!='0'){
//                 dfs(nrow,ncol,vis,grid);
//             }
//         }
//     }
// }
void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    vis[i][j] = 1;

    int n = grid.size();
    int m = grid[0].size();
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            int nrow = i + x;
            int ncol = j + y;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] != '0')
            {
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
}
int main()
{
    /*
    Given a grid of size n*m (n is the number of rows and
    m is the number of columns in the grid) consisting of
    '0's (Water) and '1's(Land). Find the number of islands.

    Note: An island is either surrounded by water or the
    boundary of a grid and is formed by connecting adjacent
    lands horizontally or vertically or diagonally i.e., in
    all 8 directions.
    */
    vector<vector<char>> grid = {{'0', '1'}, {'1', '0'}, {'1', '1'}, {'1', '0'}};
    // grid is
    //  0  1
    //  1  0
    //  1  1
    //  1  0  all lands are connected
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                dfs(i, j, vis, grid);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

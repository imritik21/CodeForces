#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

// void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &mat)
// {
//     vis[row][col] = 1;
//     int n = mat.size();
//     int m = mat[0].size();

//     // All four directions
//     vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//     for (auto dir : directions)
//     {
//         int nrow = dir.first + row;
//         int ncol = dir.second + col;
//         if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1)
//         {
//             vis[nrow][ncol] = 1; // Mark as visited
//             dfs(nrow, ncol, vis, mat);
//         }
//     }
// }

//NOTE:  DFS won't work because it goes depth 
// but we need in min TIME only posible if you move neigh at equal pase
// so BFS would be handy
// for ex:     0 1 2
//             0 1 1
//             2 1 1   in queue :  (0,2),(2,0)

int main()
{             //{{0, 1, 2}, {0, 1, 2}, {2, 1, 1}}
    vector<vector<int>> mat = {{2, 1, 1},{1,1,0},{0,1,1}};
    int cnt = 0;
    int n = mat.size();
    int m = mat[0].size();

    // perform BFS
    queue<pair<pair<int,int>,int>> q;
    int vis[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==2){
                q.push({{i,j},0});// push all rotten at time 0
                vis[i][j]=2;
            }
            else{
                vis[i][j]=0;
            }
        }
    }
    int maxTime=0;
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        maxTime=max(maxTime,time);
        q.pop();

        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto dir:directions){
            int nrow = row+dir.first;
            int ncol = col+dir.second;

            if(nrow>=0 && nrow<n && ncol>=0 && 
            ncol<m && vis[nrow][ncol]==0
            && mat[nrow][ncol]==1){
                q.push({{nrow,ncol},time+1});
                vis[nrow][ncol]=2;
            }
        }
    }
    bool fresh=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]!=2 && mat[i][j]==1){
                fresh=true;
                break;
            }
        }
        if(fresh)break;
    }
    if(fresh){
        cout<<-1<<endl;
    }
    else cout<<maxTime<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<int>> grid= {{0,0,0},{0,1,0},{0,0,0}};
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
        }
    }

    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dis = q.front().second;
        dist[row][col]=dis;
        q.pop();

        for(auto dir:directions){
            int nrow = row + dir.first;
            int ncol = col + dir.second;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},dis+1});
            }
        }
    }

    for(auto ele:dist){
        for(auto cell:ele){
            cout<<cell<<" ";
        }
        cout<<endl;
    }

    return 0;
}

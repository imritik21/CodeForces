#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis
        ,vector<pair<int,int>>&vec,int row0,int col0){
    vis[row][col]=1;
    vec.push_back({row-row0,col-col0});
    int n = grid.size();
    int m = grid[0].size();
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
    for(auto& dir:directions){
        int nrow = row+dir.first;
        int ncol = col+dir.second;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
           !vis[nrow][ncol]&&grid[nrow][ncol]==1){
            dfs(nrow,ncol,grid,vis,vec,row0,col0);
           }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<int>> grid = {{1,1,0,0,0},
                                {1,1,0,0,0},
                                {0,0,0,1,1},
                                {0,0,0,1,1}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && grid[i][j]==1){
                vector<pair<int,int>> vec;
                dfs(i,j,grid,vis,vec,i,j);
                st.insert(vec);
            }
        }
    }
    // TC- O(N*M*log(N*M)+(N+M));
    cout<<st.size()<<endl;
    return 0;
}

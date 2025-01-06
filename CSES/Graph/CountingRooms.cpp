#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&arr){
    vis[row][col]=1;
    int n = arr.size();
    int m = arr[0].size();
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    for(auto dir:directions){
        int nrow = row + dir.first;
        int ncol = col + dir.second;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
           && !vis[nrow][ncol] && arr[nrow][ncol]=='.'){
            vis[nrow][ncol]=1;
            dfs(nrow,ncol,vis,arr);
           }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int cnt=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && arr[i][j]=='.'){
                dfs(i,j,vis,arr);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

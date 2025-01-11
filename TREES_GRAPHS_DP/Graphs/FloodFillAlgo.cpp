#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void dfs(int row, int col, vector<vector<int>> &image, int newCol, int oldCol, vector<vector<int>> &vis)
{
    vis[row][col]=1;
    int n = image.size();
    int m = image[0].size();

    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    for(auto dir:directions){
        int nrow = dir.first+row;
        int ncol = dir.second+col;

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
        !vis[nrow][ncol] && image[nrow][ncol]==oldCol){
            image[nrow][ncol]=newCol;
            dfs(nrow,ncol,image,newCol,oldCol,vis);
        }
    }
}

int main()
{
    /*
    An image is represented by a 2-D array of integers, 
    each integer representing the pixel value of the image.

    Given a coordinate (sr, sc) representing the starting pixel 
    (row and column) of the flood fill, and a pixel value newColor,
     "flood fill" the image.

    To perform a "flood fill", consider the starting pixel, 
    plus any pixels connected 4-directionally to the starting
     pixel of the same color as the starting pixel, plus any 
     pixels connected 4-directionally to those pixels (also with 
     the same color as the starting pixel), and so on. Replace the 
     color of all of the aforementioned pixels with the new color.
    */

    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;

    int oldColor = image[sr][sc];
    image[sr][sc] = newColor;

    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    dfs(sr, sc, image, newColor, oldColor, vis);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

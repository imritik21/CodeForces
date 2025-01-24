// Diameter of a Graph
/*
    The diameter of a graph is the largest distance between
    any pair of vertices, i.e. maxu,v d(u, v). The best known
    algorithm for finding the diameter exactly is by running
    an algorithm for APSP and returning the largest distance
*/
// Approach: what we can do is that we can calculate All path Shortest path
// and find the maximum dist amoung them
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void AllPathShortestPath(vector<vector<int>>&mat,int &diameter){
    // if no edge mark it as INF so wont update it
    int n = mat.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]<0){
                mat[i][j]=1e9;
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][k]!=1e9 && mat[k][j]!=1e9){
                    mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
    }
    // again replace
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1e9){
                mat[i][j]=-1;
            }
            diameter=max(diameter,mat[i][j]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<int>> mat = {{0,25},{-1,0}};
    // -1 means ki no edge 
    int Diameter = 0;
    AllPathShortestPath(mat,Diameter);
    cout<<Diameter<<endl;
    return 0;
}

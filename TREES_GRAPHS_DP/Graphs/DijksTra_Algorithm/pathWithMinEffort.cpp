#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*  A route's effort is the maximum absolute difference in heights
    between two consecutive cells of the route.

    Return the minimum effort required to travel from the
    top-left cell to the bottom-right cell.
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> height = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    // approach
    // we can apply plain Dijkstra and in dist array we'll keep the maxof abs diff req
    // to reach there
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    int n = height.size();
    int m = height[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[0][0]=0;
    pq.push({0,{0,0}});
    
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if(row==n-1 && col==m-1){
            cout<<dis<<endl;
            return 0;
        }
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto& dir:directions){
            int nrow = row+dir.first;
            int ncol = col+dir.second;

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int newEffort = max(dis,abs(height[nrow][ncol]-height[row][col]));
                if(newEffort<dist[nrow][ncol]){
                    dist[nrow][ncol]=newEffort;
                    pq.push({dist[nrow][ncol],{nrow,ncol}});
                }
            }
        }
    }
    cout<<"NO Valid Path "<<endl;// never executesṇṇ
    
    return 0;
}

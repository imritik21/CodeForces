#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int N = 1e3+10;
// adjacency list rep
// vector<int> graph[N];
// if we want to store the weights

// adjacency matrix
int graph1[N][N];
vector<pair<int,int>> graph[N];
int main()
{
    // we store list for every node
    // each list contains neighbour
    // SC = O(V+E)
    // eg
    // 0 --> 1
    // 1 --> 0,2
    // 2 --> 1
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        // matrix
        graph1[v1][v2]=wt;
        graph1[v2][v1]=wt;

        // list
        graph[v1].push_back({v2,wt});
        graph[v2].push_back({v1,wt});
    }

    // for(auto ele:graph){
    //     for(int i=0;i<ele.size();i++){
    //         cout<<ele[i]<<" ";
    //     }
    //     cout<<endl;
    // }
     // now suppose if we want to 
    // wheater i,j connected ? ya to fir i,j ka wt ?
    // we can do this in O(1) in matrix
    if(graph1[i][j]==1){
        // connected
    }
    int weightof_i_j =graph1[i][j] 

    // but in list
    for(pair<int,int> child: graph[i]){
        if(child.first == j){
            // connected hai
            child.second // will give weight
        }
    }
    return 0;
}

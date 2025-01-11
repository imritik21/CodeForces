#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N = 1e5+10;
vector<int> graph[N];
bool vis[N];

void dfs(int vertex){
    /* Take action on vertex 
          before entering vertex
    */
   cout<<vertex<<endl;
    vis[vertex]=true;
    for(auto child:graph[vertex]){
        // Take action on child
        // before entering into child
        cout<<"parent "<<vertex<<" Child "<<child<<endl;
        if(vis[child])continue;

        dfs(child);
        // take action on child after 
        // exiting child
    }
    cout<<"Node explored\n";
    //take action on vertex
    // before exiting the vertex
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    return 0;
}

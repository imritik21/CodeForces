#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int N = 1e3+10;
int graph[N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    // n vertices and m edges

    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    // SC is much more O(N^2)
    // N=10^6  can't store 
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
class DisjointSet
{
    vector<int> rank, parent,size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u; // take any
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 belong to same compo
    if (ds.findPar(3) == ds.findPar(7))
    {
        cout << "SAME\n";
    }
    else
        cout << "NOT SAME\n";
    ds.unionBySize(3, 7);
    if (ds.findPar(3) == ds.findPar(7))
    {
        cout << "SAME\n";
    }
    else
        cout << "NOT SAME\n";
        // both are of smae time Complexity O(4alpha)
    return 0;
}

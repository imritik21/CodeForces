#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // priority_queue<int> pq;
    // pq.push(10);
    // pq.push(2);
    // pq.push(4);
    // pq.push(8);
    // cout<<pq.top()<<endl;

    // priority_queue<int,vector<int>,greater<int>> pq;
    // pq.push(10);
    // pq.push(2);
    // pq.push(4);
    // pq.push(8);
    // cout<<pq.top();

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({1,2});
    pq.push({10,2});
    pq.push({1,3});
    pq.push({4,2});
    pq.push({0,2});

    cout<<pq.top().first<<" "<<pq.top().second<<endl;

    
    return 0;
}

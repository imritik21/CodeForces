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

    ll n,s;
    cin>>n>>s;
    vector<ll> weight(n),cost(n);
    for(auto &i:weight)cin>>i;
    for(auto &i:cost)cin>>i;
    // vector<ll> prefix(n+1,0);
    // deque<int> dq;
    ll sum=0;
    ll maxCost=INT_MIN;
    ll sum2=0;
    int j=0;
    for(int i=0;i<n;i++){
        sum+=weight[i];
        sum2+=cost[i];
        while(j<=i && sum>s){
            sum-=weight[j];
            sum2-=cost[j];
            j++;
        }
        if(sum<=s){
            maxCost=max(maxCost,sum2);
            // cout<<maxCost<<" ";
        }
        // dq.push_back(i);
    }
    // cout<<endl;
    cout<<maxCost<<endl;
    return 0;
}

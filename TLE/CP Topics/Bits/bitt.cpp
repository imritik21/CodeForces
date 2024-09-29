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
    
    ll n=1;
    // cin>>n;

    ll mask = 1<<30;
    ll res = n|mask;
    // cout<<res<<endl;

    // i want to know set bit in 15 - 1111
    vector<int> set(31,0);
    for(int i=30;i>=0;i--){
        int mask = 1<<i;
        if((mask&15)!=0){
            set[i]=1;
        }
    }
    for(auto ele:set)cout<<ele<<" ";
    return 0;
}

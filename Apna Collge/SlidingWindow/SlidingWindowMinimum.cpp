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
    
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(auto &it:arr)cin>>it;

    deque<ll> dq;
    // we'll use deque optimization
    for(int i=0;i<n;i++){
        // check everytime what should be in top
        while(!dq.empty() && arr[dq.back()]>=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        // cond for out of window
        if(dq.front()==i-k){
            dq.pop_front();
        }
        // add res for window
        if(i>=k-1){
            cout<<arr[dq.front()]<<" ";
        }
    }
    return 0;
}

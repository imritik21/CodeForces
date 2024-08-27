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
    
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<int> NSL(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            NSL[i]=-1;
        }
        else{
            NSL[i]=st.top();
        }
        st.push(i);
    }
    for(auto ele:NSL)cout<<ele+1<<" ";
    return 0;
}

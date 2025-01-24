#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    int cont=0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]=i;
    }
    for(int i=0;i+1<n;i++){
        cont+=abs(arr[i]-arr[i+1]);
    }
    if(cont==0){
        cout<<1<<endl;
        return;
    }
    int ans=n;
    int rem=0;
    for(int i=0;i<n;i++){
        int curr = arr[i];
        int req = cont-rem;
        // cout<<curr+req<<" ";
        if(mp.find(curr+req)!=mp.end()){
            // cout<<"found ";
            // cout<<(mp[curr+req])<<" ";
            ans=min(ans,n-(mp[curr+req]-i-1));
        }
        if(mp.find(rem)!=mp.end()){
            ans=min(ans,n-(i-mp[rem]-1));
        }
        if(i+1<n)rem+=abs(arr[i]-arr[i+1]);
        // cout<<endl;
    }
    cout<<ans<<endl;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<ll> start(n,0),end(n,0),prefix(n,0),suffix(n,0);
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            start[i] = arr[i-1]-arr[i];
        }
        else start[i]=0;
        // cout<<start[i]<<" ";
    }
    prefix[0]=start[0];
    for(int i=1;i<n;i++)prefix[i]=prefix[i-1]+start[i];
    for(int i=n-2;i>=0;i--){
        if(arr[i+1]>arr[i]){
            end[i]=arr[i+1]-arr[i];
        }
        else end[i]=0;
        // cout<<end[i]<<" ";
    }
    suffix[n-1]=end[n-1];
    for(int i=n-2;i>=0;i--)suffix[i]=suffix[i+1]+end[i];
    // for(int i=0;i<n;i++)cout<<prefix[i]<<" ";
    // 0 2 2 5 5 5 10 
    // 7 7 6 6 4 0 0 
    // cout<<endl;
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        if(l<r){
            l--;
            r--;
            cout<<prefix[r]-prefix[l]<<endl;
        }
        else{
            r--;
            l--;
            cout<<suffix[r]-suffix[l]<<endl;
        }
    }
    return 0;
}

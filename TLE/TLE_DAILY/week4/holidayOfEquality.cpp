#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int maxx=*max_element(arr,arr+n);
    int res=0;
    for(int j=0;j<n;j++){
        int req=(maxx-arr[j]);
        if(arr[j]<maxx){
            res=res+req;
        }
    }
    cout<<res<<endl;
}
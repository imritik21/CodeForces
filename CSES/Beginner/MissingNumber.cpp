#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int n;
    cin>>n;
    int arr[n];
    int totalsum=(n*(n+1))/2;
    int rest=0;
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
        rest+=arr[i];
    }
    cout<<totalsum-rest<<endl;
}

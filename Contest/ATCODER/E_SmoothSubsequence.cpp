#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int n,d;
    cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int maxCount=INT_MIN;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i;j<n;j++){
            if(abs(arr[i]-arr[j]<=d)){
                count++;
            }
        }
        maxCount=max(maxCount,count);
    }
    cout<<maxCount;
}
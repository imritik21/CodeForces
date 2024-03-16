#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int prefixSum[n];
    prefixSum[0]=arr[0];
    for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+arr[i];
    }
    // for(int i=0;i<n;i++){
    //     cout<<prefixSum[i]<<" ";
    // }
    // cout<<endl;
    int q;
    cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        if(l>0){
            cout<<prefixSum[r]-prefixSum[l-1]<<endl;
        }
        else{
            cout<<prefixSum[r]<<endl;
        }
    }
}

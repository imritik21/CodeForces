#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int N=1e7+10;
long long int arr[N];

int main(){
    int n,q;cin>>n>>q;
    long long  maxi=-1;
    while(q--){
        int a,b,k;
        cin>>a>>b>>k;
        arr[a]+=k;
        arr[b+1]-=k;
    }
    // prefixsum
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
    }
    for(int i=1;i<=n;i++){
        if(maxi<arr[i]){
            maxi=arr[i];
        }
    }
    cout<<maxi<<endl;
}

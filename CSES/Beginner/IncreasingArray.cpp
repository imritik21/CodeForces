#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    ll n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll cost=0;
    for(int i=0;i+1<n;i++){
        if(arr[i]>arr[i+1]){
            cost+=arr[i]-arr[i+1];
            arr[i+1]=arr[i];
        }
    }
    cout<<cost<<endl;
}

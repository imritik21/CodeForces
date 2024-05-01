#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void backTracking(int arr[],int n,int i){
    if(i==n){
        return;
    }
    backTracking(arr,n,i+1);
    arr[i]=arr[i]-2; // backtracking steps;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    backTracking(arr,n,0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

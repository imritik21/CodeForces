#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void printEven(ll arr[],ll n,ll index){
    if(index<-1){
        return;
    }
    if(index%2 !=0){
        return printEven(arr,n,index-1);;
    }
    cout<<arr[index]<<" ";
    return printEven(arr,n,index-1);
}
int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    printEven(arr,n,n-1);
}

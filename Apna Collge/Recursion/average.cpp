#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
double averageSum(ll i,ll arr[],ll n,double sum){
    if(i==n) return (sum*1.0/n*1.0);
    return averageSum(i+1,arr,n,sum+arr[i]);
}
int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<setprecision(7)<<fixed<<averageSum(0,arr,n,0.0);
}

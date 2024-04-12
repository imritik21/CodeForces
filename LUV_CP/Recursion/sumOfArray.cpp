#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int sum(int n, int arr[]){
    if(n<0) return 0;
    return sum(n-1,arr)+arr[n];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=sum(n-1,arr);
    cout<<res<<endl;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n=5;
    int arr[5]={1,2,3,4,5};
    int prefixSum[5];
    prefixSum[0]=arr[0];
    for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+arr[i];

    }
    for(int i=0;i<n;i++){
        cout<<prefixSum[i]<<" ";
    }
    cout<<endl;
}

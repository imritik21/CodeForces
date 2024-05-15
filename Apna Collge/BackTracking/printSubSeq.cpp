#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void printSeq(int ind,vector<int>& ds,int s,int sum,int arr[],int n){
    if(ind==n){
        if(s==sum){
            for(int i=0;i<ds.size();i++) cout<<ds[i]<<" ";
            cout<<endl;
        }
        return;
    }
    // not pick
    printSeq(ind+1,ds,s,sum,arr,n);
    // pick
    ds.push_back(arr[ind]);
    s+=arr[ind];
    printSeq(ind+1,ds,s,sum,arr,n);
    ds.pop_back();
}
int main(){
    int arr[]= {1,2,1};
    int n=3;
    int sum=2;
    vector<int> ds;
    printSeq(0,ds,0,sum,arr,n);
}
